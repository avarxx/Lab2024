#include "merge.h"

void mergeRecursive(int* array, int left, int mid, int right) 
{
  int elemLeft    = mid - left + 1;
  int elemRight   = right - mid;
  int* arrayLeft  = (int*) calloc(elemLeft, sizeof(int)); 
  int* arrayRight = (int*) calloc(elemRight, sizeof(int)); 


  for (int i = 0; i < elemLeft; i++)
      arrayLeft[i] = array[left + i];
  for (int j = 0; j < elemRight; j++)
      arrayRight[j] = array[mid + 1 + j];
    int i = 0, j = 0, k = left;

  while (i < elemLeft && j < elemRight) 
  {
    if (arrayLeft[i] <= arrayRight[j]) 
    {
      array[k] = arrayLeft[i];
      i++;
    } 
    else 
    {
      array[k] = arrayRight[j];
      j++;
    }
    k++;
  }

  while (i < elemLeft) 
  {
    array[k] = arrayLeft[i];
    i++;
    k++;
  }

  while (j < elemRight) 
  {
    array[k] = arrayRight[j];
    j++;
    k++;
  }

  free (arrayLeft);
  free (arrayRight);
}

void merge_recursive(int* array, int left, int right) 
{
  if (left < right) 
  {
    int m = left + (right - left) / 2;

    merge_recursive(array, left, m);
    merge_recursive(array, m + 1, right);

    mergeRecursive(array, left, m, right);
  }
}

void mergeSortRecursive(int* array, size_t size) 
{
  merge_recursive (array, 0, size - 1);
}
