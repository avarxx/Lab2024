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
    
    int first  = low + rand() % (high - low);
    int second = low + rand() % (high - low);
    int third  = low + rand() % (high - low);

    if (array[first]  > array[second])   
      swap2(array + first , array + second);
    if (array[first]  > array[third])    
      swap2(array + first , array + third);
    if (array[second] > array[third])    
      swap2(array + second, array + third);


    int midIndex = partition(array, low, high, array[second]);

    qsort_mid_rand (array, low, midIndex);
    qsort_mid_rand (array, midIndex + 1 , high);
}
