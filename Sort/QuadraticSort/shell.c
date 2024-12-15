#include "quadraticSort.h"

#define INITIAL_STEP 1
#define STEP_MULTIPLIER 3
#define STEP_DIVISOR 9

void shellSort(int* array, size_t size)
{
  assert(array != NULL);
  size_t step = INITIAL_STEP;
  while (step <= size / STEP_DIVISOR)
  {
    step = step * STEP_MULTIPLIER + INITIAL_STEP;
  }
  for (; step > 0; step /= STEP_MULTIPLIER)
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
