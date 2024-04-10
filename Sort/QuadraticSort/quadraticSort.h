#ifndef QUADRATIC_SORT_H
#define QUADRATIC_SORT_H

#include <assert.h>
#include <stddef.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

#include "C:\algorithms\Lab2024\Sort\Qsort4\qsort.h"

void insertionSort  (int* array, size_t size);

void selectionSort  (int* array, size_t size);

void babbleSort     (int* array, size_t size);

void shellSort      (int* array, size_t size);

#endif /* QUADRATIC_SORT_H */