#include "qsort.h"
#include "time.h"

void flagPartition(int* array, int left, int right, int* equalsFrom, int* equalsTo)
{
  int midIndex = left;
  int pivot    = array[left + (right - left) / 2];
  int temp     = 0;

  while (midIndex <= right)
  {
    if (array[midIndex] < pivot)
    {
      int temp        = array[left];
      array[left]     = array[midIndex];
      array[midIndex] = temp;
      midIndex++;
      left++;
    }
    else if (pivot == array[midIndex])
    {
      midIndex++;
    }
    else
    {
      temp            = array[midIndex];
      array[midIndex] = array[right];
      array[right]    = temp;
      right--;
    }
  }

*equalsFrom = left;
*equalsTo   = right;
}

void qsortFlag(int* array, int low, int higt)
{
  if (low >= higt) 
    return;
  int equalsFrom = 0;
  int equalsTo   = 0;

  flagPartition(array, low, higt, &equalsFrom, &equalsTo);

  qsortFlag (array, low,     equalsFrom);
  qsortFlag (array, equalsTo + 1 , higt);
}

void flagQsort(int* array, size_t size)
{
  qsortFlag(array, 0, size - 1);
}
