#include "qsort5.h"


int partition(int* array, int left, int right, int mid)
{
  while( left <= right )
  {
    while( array[left] < mid )
        left++;

    while( array[right] > mid )
      right--;

    if (left >= right) 
      break;

    swap(array + right, array + left);
    left++;
    right--;
  }
  return right;
}

void qelem(int* array, int low, int high)
{
  if (low > high - 1) 
    return;

  int pivot = array[low + (high - low) / 2];

  int midIndex = partition(array, low, high, pivot);

  qelem (array, low,    midIndex);
  qelem (array, midIndex + 1 , high);
}

void qsortElem(int* data, size_t size)
{
  qelem(data, 0, size - 1);
}