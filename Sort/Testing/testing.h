#ifndef TESTING_H_INCLUDED
#define TESTING_H_INCLUDED

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <errno.h>


#include "..\QuadraticSort\quadraticSort.h"

#include "..\QuadraticSort\bubbleSort.c"
#include "..\QuadraticSort\insertionSort.c"
#include "..\QuadraticSort\selectionSort.c"
#include "..\QuadraticSort\shell.c"

#include "..\MergeSort\merge.h"

#include "..\MergeSort\mergeIterative.c"
#include "..\MergeSort\mergeRecursion.c"

#include "..\Qsort4\qsort.h"

#include "..\Qsort4\qsortFlag.c"
#include "..\Qsort4\qsortHoara.c"
#include "..\Qsort4\qsortLamuto.c"

#include "..\Qsort5\qsort5.h"

#include "..\Qsort5\qsortElem.c"
#include "..\Qsort5\qsortMedian.c"
#include "..\Qsort5\qsortMedianRand.c"
#include "..\Qsort5\qsortRand.c"

#include "..\PyramidSort\heapSort.c"

#include "..\SortingBytes\lsd.c"
#include "..\SortingBytes\msd.c"

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