#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include "..\Qsort4\qsort.h"

void siftDown       (int* array, size_t size, int index, int k);

void Build          (int* array, size_t n, int k);

void heapSort       (int* array, size_t n, int k);

void heapSort2      (int* array, size_t n);

void heapSort3      (int* array, size_t n);

void heapSort4      (int* array, size_t n);

#endif // HEAP_H//