#ifndef QUADRATIC_SORT_H
#define QUADRATIC_SORT_H

#include <assert.h>
#include <stddef.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

#include "..\Qsort4\qsort.h"

void insertionSort  (int* array, size_t size);

void selectionSort  (int* array, size_t size);

void bubbleSort     (int* array, size_t size);

void shellSort      (int* array, size_t size);

#endif /* QUADRATIC_SORT_H */