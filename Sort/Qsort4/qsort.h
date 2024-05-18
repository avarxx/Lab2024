#ifndef QSORT_H_INCLUDED
#define QSORT_H_INCLUDED

#include <assert.h>
#include <stddef.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int   lomutoPartition (int* array, int left, int right);

void  qsortLomuto     (int* array, int low, int high); 

void  lomutoQsort     (int* array, size_t size);

int   hoarPartition   (int* array, int left, int right);

void  qsortHoar       (int* array, int low, int higt);

void  hoarQsort       (int* array, size_t size);

void flagPartition    (int* array, int left, int right, int* equalsFrom, int* equalsTo);

void flagQsort        (int* array, size_t size);

void qsortFlag        (int* array, int low, int higt);

#endif /* QSORT_H */