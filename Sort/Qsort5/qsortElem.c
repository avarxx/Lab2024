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

void qsortElem(int* data, size_t size)
{
  qsort_elem(data, 0, size - 1);
}

void qsort_elem(int* array, int low, int high)
{
  if (low > high - 1) 
    return;

  int pivot = array[low + (high - low) / 2];

  int midIndex = partition(array, low, high, pivot);

  qsort_elem (array, low,    midIndex);
  qsort_elem (array, midIndex + 1 , high);
}