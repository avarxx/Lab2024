#ifndef QSORT5_H_INCLUDED
#define QSORT5_H_INCLUDED

#include <assert.h>
#include <stddef.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "..\swap.h"


void qsortMedian    (int* array, size_t size);

void qsortRand      (int* array, size_t size);

void qsortElem      (int* array, size_t size);

void qsortMidRand   (int* array, size_t size);

int partition       (int* array, int left, int right, int mid);

#endif /* QSORT5_H */