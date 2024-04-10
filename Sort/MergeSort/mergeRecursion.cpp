#include "merge.h"

void mergeRecursive(int* array, int* buffer, int left, int mid, int right) 
{
  int elemLeft  = mid - left + 1;
  int elemRight = right - mid;

  for (int i = 0; i < elemLeft; i++)
    buffer[i] = array[left + i];
  for (int j = 0; j < elemRight; j++)
    buffer[elemLeft + j] = array[mid + 1 + j];
  
  int i = 0, j = elemLeft, k = left;

  while (i < elemLeft && j < elemLeft + elemRight) 
  {
    if (buffer[i] <= buffer[j]) 
    {
      array[k] = buffer[i];
      i++;
    } 
    else 
    {
      array[k] = buffer[j];
      j++;
    }
    k++;
  }

  while (i < elemLeft) 
  {
    array[k] = buffer[i];
    i++;
    k++;
  }

  while (j < elemLeft + elemRight) 
  {
    array[k] = buffer[j];
    j++;
    k++;
  }
}


void merge_recursive(int* array, int* buffer, int left, int right) 
{
  if (left < right) 
  {
    int m = left + (right - left) / 2;

    merge_recursive(array, buffer, left, m);
    merge_recursive(array, buffer, m + 1, right);
    mergeRecursive (array,  buffer, left, m, right);
  }
}

void mergeSortRecursive(int* array, size_t size) 
{
  int* buffer = (int*)calloc(size,sizeof(int));
  if (buffer == NULL)
  {
    exit(errMemory);
  }
  
  merge_recursive (array, buffer, 0, size - 1);

  free(buffer);
}
