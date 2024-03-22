#include "qsort.h"

int hoarPartition(int* array, int left, int right)
{
  int midIndex = left + (right - left) / 2;
  int midElem = array[midIndex];

  while (left <= right)
  {
    while (array[left] < midElem)
      left++;
    while (array[right] > midElem)
      right--; 
    
    if ( left >= right) 
      return right;

    int temp     = array[left];
    array[left]  = array[right];
    array[right] = temp;
    left++;
    right--;
  }

  return right;
}

void qsortHoar(int* array, int low, int higt)
{
  if (low >= higt) return;

  int midIndex = hoarPartition(array, low, higt);

  qsortHoar (array, low,       midIndex);
  qsortHoar (array, midIndex + 1 , higt);
}

void hoarQsort(int* array, size_t size)
{
  qsortHoar(array, 0, size - 1);
}

