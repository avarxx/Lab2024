#include "merge.h"

#define min(a, b) (((a) < (b)) ? (a) : (b))

void merge_iterative(int* array, int* buffer, int left, int mid, int right)
{
  int elemLeft = mid - left + 1;
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
}

void mergeSortIterative(int* array, size_t size)
{
  int* buffer = (int*)calloc(size, sizeof(int));
  if (buffer == NULL)
  {
    exit(errMemory);
  }

  for (int currSize = 1; currSize <= size - 1; currSize *= 2)
  {
    for (int leftStart = 0; leftStart < size - 1; leftStart += 2 * currSize)
    {
      int mid = min(leftStart + currSize - 1, size - 1);
      int rightEnd = min(leftStart + 2 * currSize - 1, size - 1);

      merge_iterative(array, buffer, leftStart, mid, rightEnd);
    }
  }

  free(buffer);
}
