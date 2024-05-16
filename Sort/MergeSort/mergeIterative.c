#include "merge.h"

#define min(a, b) (((a) < (b)) ? (a) : (b))

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

      int elemLeft = mid - left + 1;
      int elemRight = right - mid;

      memcpy(buffer, &array[left], elemLeft * sizeof(int));
      memcpy(&buffer[elemLeft], &array[mid + 1], elemRight * sizeof(int));

      size_t i = 0, j = elemLeft, k = left;
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
  }

  free(buffer);
}
