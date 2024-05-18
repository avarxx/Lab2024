#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include "..\swap.h"

#include <stdlib.h>
#include <stdbool.h>

void siftDown       (int* array, size_t size, int index, int k);

void Build          (int* array, size_t n, int k);

void heapSort       (int* array, size_t n, int k);

int getChild        (int index, int childIndex, int k);

#endif // HEAP_H//