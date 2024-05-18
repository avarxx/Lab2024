#include "qsort5.h"

void qsortMedian(int* array, size_t size)
{
    qmedian(array, 0, size - 1);
}

void qmedian(int* array, int low, int high)
{
  if (low > high - 1) 
    return;

  int midIndex = low + (high - low) / 2;

  if (array[low]  > array[midIndex]) 
    swap(array + low , array + midIndex);
  if (array[low]  > array[high])    
    swap(array + low , array + high);
  if (array[midIndex] > array[high])    
    swap(array + midIndex, array + high);

  midIndex = partition(array, low, high, array[midIndex]);

  qmedian (array, low,    midIndex);
  qmedian (array, midIndex + 1 , high);
}

