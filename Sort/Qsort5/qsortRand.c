#include "qsort5.h"

void qsortRand(int* array, size_t size)
{
  qsort_rand(array, 0, size - 1);
}

void qsort_rand(int* array, int low, int high)
{
  if (low > high - 1) 
    return;
  int id = (int) (rand() % (high - low));
  int pivot = array[low + id];

  int midIndex = partition(array, low, high, pivot);

  qsort_rand (array, low,       midIndex);
  qsort_rand (array, midIndex + 1 , high);
}

