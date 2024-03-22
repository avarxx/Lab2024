#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

void swap3          (int* first, int* second);

void siftDown       (int* array, int size, int index, int k);

void Build          (int* array, int n, int k);

void heapSort       (int* array, int n, int k);

void heapSort2      (int* array, int n);

void heapSort3      (int* array, int n);

void heapSort4      (int* array, int n);
#endif // HEAP_H//