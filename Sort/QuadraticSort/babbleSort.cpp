#include "quadraticSort.h"

void babbleSort(int* array, size_t size)
{
  assert(array != NULL);
  
  for(size_t i = 0; i < size - 1; ++i)
  {
    for (size_t j = 0; j < size - i - 1; j++)
    {
      if (array[j] > array[j + 1])
      {
        int tmp      = array[j];
        array[j]     = array[j + 1];
        array[j + 1] = tmp;
      }
    }
  }
}
