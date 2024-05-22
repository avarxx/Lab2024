#include "qsort5.h"

void qmidRand(int* array, int low, int high)
{
  srand(time(NULL)); 
  if (low > high - 1) 
    return;
  int range  = high - low;
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

  qmidRand (array, low, midIndex);
  qmidRand (array, midIndex + 1 , high);
}


void qsortMidRand(int* array, size_t size)
{
  qmidRand(array, 0, size - 1);
}