#ifndef QSORT5_H_INCLUDED
#define QSORT5_H_INCLUDED

#include <assert.h>
#include <stddef.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int partition       (int* array, int left, int right, int mid);

void swap           (int* first, int* second);

void qsortMedian    (int* array, size_t size);

void qsort_median   (int* array, int low, int high);

void qsort_rand     (int* array, int low, int high);

void qsortRand      (int* array, size_t size);

void qsort_elem     (int* array, int low, int high);

void qsortElem      (int* array, size_t size);

void qsort_mid_rand (int* array, int low, int high);

void qsortMidRand   (int* array, size_t size);

void swap2(int* first, int* second)
{
  int tmp = *first;
  *first = *second;
  *second = tmp;
}

int partition(int* array, int left, int right, int mid)
{
  while( left <= right )
  {
    while( array[left] < mid )
        left++;

    while( array[right] > mid )
      right--;

    if (left >= right) 
      break;

    int temp = array[right];
    array[right] = array[left];
    array[left] = temp;
    left++;
    right--;
  }
  return right;
}

#endif /* QSORT5_H */