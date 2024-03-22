#ifndef MERGE_H_INCLUDED
#define MERGE_H_INCLUDED

#include <assert.h>
#include <stddef.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>


void mergeSortInteractive(int* array, size_t size);

void merge_interactive(int* array, int left, int right);

void mergeInteractive(int* array, int left, int mid, int right);

void mergeRecursive(int* array, int left, int mid, int right);

void merge_recursive(int* array, int left, int right);

void mergeSortRecursive(int* array, size_t size);
#endif /* MERGE_H */