#ifndef MERGE_H_INCLUDED
#define MERGE_H_INCLUDED

#include <assert.h>
#include <stddef.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

enum err
{
  errMemory = 11
};

void merge             (int* array, int* buffer, int left, int mid, int right);

void mergeSortIterative(int* array, size_t size);

void mergeSortRecursive(int* array, size_t size);

#endif /* MERGE_H */