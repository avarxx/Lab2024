#ifndef TESTING_H_INCLUDED
#define TESTING_H_INCLUDED

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


#include "C:\algorithms\Lab2024\Sort\QuadraticSort\quadraticSort.h"

#include "C:\algorithms\Lab2024\Sort\QuadraticSort\bubbleSort.c"
#include "C:\algorithms\Lab2024\Sort\QuadraticSort\insertionSort.c"
#include "C:\algorithms\Lab2024\Sort\QuadraticSort\selectionSort.c"
#include "C:\algorithms\Lab2024\Sort\QuadraticSort\shell.c"

#include "C:\algorithms\Lab2024\Sort\MergeSort\merge.h"

#include "C:\algorithms\Lab2024\Sort\MergeSort\mergeIterative.c"
#include "C:\algorithms\Lab2024\Sort\MergeSort\mergeRecursion.c"

#include "C:\algorithms\Lab2024\Sort\Qsort4\qsort.h"

#include "C:\algorithms\Lab2024\Sort\Qsort4\qsortFlag.c"
#include "C:\algorithms\Lab2024\Sort\Qsort4\qsortHoara.c"
#include "C:\algorithms\Lab2024\Sort\Qsort4\qsortLamuto.c"

#include "C:\algorithms\Lab2024\Sort\Qsort5\qsort5.h"

#include "C:\algorithms\Lab2024\Sort\Qsort5\qsortElem.c"
#include "C:\algorithms\Lab2024\Sort\Qsort5\qsortMedian.c"
#include "C:\algorithms\Lab2024\Sort\Qsort5\qsortMedianRand.c"
#include "C:\algorithms\Lab2024\Sort\Qsort5\qsortRand.c"

#include "C:\algorithms\Lab2024\Sort\PyramidSort\heapSort.c"

#include "C:\algorithms\Lab2024\Sort\SortingBytes\lsd.c"
#include "C:\algorithms\Lab2024\Sort\SortingBytes\msd.c"

#define lenStr 40

void testing        (const char* dir, void (*sort)(int* arr, size_t n), const char* results, size_t from, size_t to, size_t step, int numberOftest);

void testQuadratic  (void);

void testMerge      (void);

void testQsort      (void);

void testQsort5     (void);

void testPyramid    (void);

void testSorting    (void);

void test9          (void);

#endif // TESTING_H//