#include "quadraticSort.h"

void shellSort(int* array, size_t size)
{
  assert(array != NULL);
  
  size_t step = 1;
  while (step <= size / 9)
  {
    step = step * 3 + 1;
  }
  for (; step > 0; step /= 3)
  {
    for (size_t i = 0; i < size; i += step)
    {
      size_t j = i;
      int tmp = array[i];
      for (; j >= step && array[j - step] > tmp; j -= step)
      {
        array[j] = array[j - step];    
      }
      array[j] = tmp;
    }
  }  
}
