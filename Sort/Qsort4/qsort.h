#ifndef QSORT_H_INCLUDED
#define QSORT_H_INCLUDED

#include <assert.h>
#include <stddef.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void swap(int* first, int* second)
{
  int tmp = *first;
  *first  = *second;
  *second = tmp;
}

int   lomutoPartition (int* array, int left, int right);

void  qsortLamuto     (int* array, int low, int high); 

void  lamutoQsort     (int* array, size_t size);

int   hoarPartition   (int* array, int left, int right);

void  qsortHoar       (int* array, int low, int higt);

void  hoarQsort       (int* array, size_t size);

void flagPartition    (int* array, int left, int right, int* equalsFrom, int* equalsTo);

void flagQsort        (int* array, size_t size);

void qsortFlag        (int* array, int low, int higt);
#endif /* QSORT_H */