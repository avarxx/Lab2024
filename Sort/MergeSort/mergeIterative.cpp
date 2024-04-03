#include "merge.h"

void mergeInteractive(int* array, int left, int mid, int right) 
{
  int elemLeft    = mid - left + 1;
  int elemRight   = right - mid;
  int* arrayLeft  = (int*) calloc(elemLeft , sizeof(int)); 
  int* arrayRight = (int*) calloc(elemRight, sizeof(int)); 
  if (arrayLeft == NULL || arrayRight == NULL)
  {
    exit(errMemory);
  }
  

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

void merge_interactive(int* array, int left, int right) 
{
  if (left < right) 
  {
    int m = left + (right - left) / 2;

    merge_interactive(array, left, m);
    merge_interactive(array, m + 1, right);
    mergeInteractive(array, left, m, right);
  }
}

void mergeSortInteractive(int* array, size_t size) 
{
  merge_interactive(array, 0, size - 1);
}
