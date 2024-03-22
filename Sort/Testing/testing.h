#ifndef TESTING_H_INCLUDED
#define TESTING_H_INCLUDED

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "C:\algorithms\My\QuadraticSort\quadraticSort.h"

#include "C:\algorithms\My\QuadraticSort\babbleSort.cpp"
#include "C:\algorithms\My\QuadraticSort\insertionSort.cpp"
#include "C:\algorithms\My\QuadraticSort\selectionSort.cpp"
#include "C:\algorithms\My\QuadraticSort\shell.cpp"

#include "C:\algorithms\My\MergeSort\merge.h"

#include "C:\algorithms\My\MergeSort\mergeIterative.cpp"
#include "C:\algorithms\My\MergeSort\mergeRecursion.cpp"

#include "C:\algorithms\My\Qsort4\qsort.h"

#include "C:\algorithms\My\Qsort4\qsortFlag.cpp"
#include "C:\algorithms\My\Qsort4\qsortHoara.cpp"
#include "C:\algorithms\My\Qsort4\qsortLamuto.cpp"

#include "C:\algorithms\My\Qsort5\qsort5.h"

#include "C:\algorithms\My\Qsort5\qsortElem.cpp"
#include "C:\algorithms\My\Qsort5\qsortMedian.cpp"
#include "C:\algorithms\My\Qsort5\qsortMedianRand.cpp"
#include "C:\algorithms\My\Qsort5\qsortRand.cpp"

#include "C:\algorithms\My\PyramidSort\heapSort.cpp"

#include "C:\algorithms\My\SortingBytes\lsd.cpp"
#include "C:\algorithms\My\SortingBytes\msd.cpp"

#define lenStr 40

void testing        (char* dir, void (*sort)(int* arr, size_t n), const char* results, size_t from, size_t to, size_t step);

void testQuadratic  (void);

void testMerge      (void);

void testQsort      (void);

void testQsort5     (void);

void testPyramid    (void);

void testSorting    (void);

void test9          (void);

#endif // TESTING_H//