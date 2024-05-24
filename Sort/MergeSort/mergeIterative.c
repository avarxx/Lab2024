#include "merge.h"
#include <stdlib.h>
#include <string.h>

void mergeSortIterative(int* array, size_t size)
{
  int* buffer = (int*)calloc(size, sizeof(int));
  if (buffer == NULL)
  {
    exit(errMemory);
  }

  for (size_t currSize = 1; currSize <= size - 1; currSize *= 2)
  {
    for (size_t left = 0; left < size - 1; left += 2 * currSize)
    {
      int mid = min(left + currSize - 1, size - 1);
      int right = min(left + 2 * currSize - 1, size - 1);

      merge(array, buffer, left, mid, right);
    }
  }

  free(buffer);
}
