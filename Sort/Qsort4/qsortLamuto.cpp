#include "qsort.h"
#include <time.h>
int lomutoPartition(int* array, int left, int right)
{
  int midIndex  = left + (right - left) / 2;
  int midElem   = array[midIndex];

  int temp        = array[midIndex];
  array[midIndex] = array[right];
  array[right]    = temp;
  int i = left;
  for (int j = left; j <= right; j++)
  {
    if (midElem > array[j])
    {
      temp     = array[i];
      array[i] = array[j];
      array[j] = temp;

      i++;
    }
  }
  temp          = array[i];
  array[i]      = array[right];
  array[right]  = temp;
  return i;
}

void qsortLamuto(int* array, int low, int high) 
{ 
	if (low < high) 
	{ 
    int pi = lomutoPartition(array, low, high); 
    qsortLamuto(array, low, pi - 1); 
    qsortLamuto(array, pi + 1, high); 
	} 
} 

void lamutoQsort(int* array, size_t size)
{
  qsortLamuto(array, 0, size - 1);
}

