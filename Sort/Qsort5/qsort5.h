#ifndef QSORT5_H_INCLUDED
#define QSORT5_H_INCLUDED

#include <assert.h>
#include <stddef.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "..\swap.h"

int partition       (int* array, int left, int right, int mid);

void qsortMedian    (int* array, size_t size);

void qmedian        (int* array, int low, int high);

void qrand          (int* array, int low, int high);

void qsortRand      (int* array, size_t size);

void qelem          (int* array, int low, int high);

void qsortElem      (int* array, size_t size);

void qmidRand       (int* array, int low, int high);

void qsortMidRand   (int* array, size_t size);

#endif /* QSORT5_H */