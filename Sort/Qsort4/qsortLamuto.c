#include "qsort.h"
#include <time.h>

int lomutoPartition(int* array, int left, int right)
{
  int midIndex    = left + (right - left) / 2;
  int midElem     = array[midIndex];
  swap(array + midIndex, array + right);

  size_t i = left;
  for (size_t j = left; j <= right; j++)
  {
    if (midElem > array[j])
    {
      swap(array + i, array + j);
      i++;
    }
  }
  swap(array + i, array + right);
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
