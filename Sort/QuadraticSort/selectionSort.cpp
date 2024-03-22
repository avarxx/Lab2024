#include "quadraticSort.h"

void selectionSort(int* array, size_t size) 
{
  assert(array != NULL);
  for (size_t i = 0; i < size - 1; i++) 
  {
    size_t minIndex = i;
    for (size_t j = i + 1; j < size; j++) 
    {
      if (array[j] < array[minIndex]) 
      {
        minIndex = j;
      }
    }
    int temp        = array[i];
    array[i]        = array[minIndex];
    array[minIndex] = temp;
  }
}
