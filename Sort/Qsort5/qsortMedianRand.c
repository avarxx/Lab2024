#include "qsort5.h"

void qsortMidRand(int* array, size_t size)
{
    qsort_mid_rand(array, 0, size - 1);
}

void qsort_mid_rand(int* array, int low, int high)
{
  srand(time(NULL)); 
  if (low > high - 1) 
    return;
  int range = high - low;
  int first  = low + rand() % (range);
  int second = low + rand() % (range);
  int third  = low + rand() % (range);

  if (array[first]  > array[second])   
    swap(array + first , array + second);
  if (array[first]  > array[third])    
    swap(array + first , array + third);
  if (array[second] > array[third])    
    swap(array + second, array + third);


  int midIndex = partition(array, low, high, array[second]);

  qsort_mid_rand (array, low, midIndex);
  qsort_mid_rand (array, midIndex + 1 , high);
}
