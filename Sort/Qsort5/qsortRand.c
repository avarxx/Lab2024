#include "qsort5.h"

void qrand(int* array, int low, int high)
{
  if (low > high - 1) 
    return;
  int id = (int) (rand() % (high - low));
  int pivot = array[low + id];

  int midIndex = partition(array, low, high, pivot);

  qrand (array, low,       midIndex);
  qrand (array, midIndex + 1 , high);
}

void qsortRand(int* array, size_t size)
{
  qrand(array, 0, size - 1);
}
