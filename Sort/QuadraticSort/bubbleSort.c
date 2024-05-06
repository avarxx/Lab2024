#include "quadraticSort.h"

void bubbleSort(int* array, size_t size)
{
  assert(array != NULL);
  
  for(size_t i = 0; i < size - 1; ++i)
  {
    for (size_t j = 0; j < size - i - 1; j++)
    {
      if (array[j] > array[j + 1])
      {
        swap(array + j, array + j + 1);
      }
    }
  }
}
