#ifndef MERGE_H_INCLUDED
#define MERGE_H_INCLUDED

#include <assert.h>
#include <stddef.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

enum err
{
  errMemory = 11
};


void mergeSortIterative(int* array, size_t size);

void mergeRecursive(int* array, int* buffer, int left, int mid, int right);

void merge_recursive(int* array, int* buffer, int left, int right);

void mergeSortRecursive(int* array, size_t size);
#endif /* MERGE_H */