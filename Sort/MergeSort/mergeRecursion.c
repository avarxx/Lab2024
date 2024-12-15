#include "merge.h"

void merge(int* array, int* buffer, int left, int mid, int right) 
{
  int elemLeft  = mid - left + 1;
  int elemRight = right - mid;

  memcpy(buffer, &array[left], elemLeft * sizeof(int));
  memcpy(&buffer[elemLeft], &array[mid + 1], elemRight * sizeof(int));
  
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
    int mid = left + (right - left) / 2;

    merge_recursive(array, buffer, left, mid);
    merge_recursive(array, buffer, mid + 1, right);
    merge(array, buffer, left, mid, right);
  }
}

void mergeSortRecursive(int* array, size_t size) 
{
  int* buffer = (int*)calloc(size, sizeof(int));
  if (buffer == NULL)
  {
    exit(errMemory);
  }
  
  merge_recursive(array, buffer, 0, size - 1);

  free(buffer);
}
