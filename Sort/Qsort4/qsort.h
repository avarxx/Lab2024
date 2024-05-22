#ifndef QSORT_H_INCLUDED
#define QSORT_H_INCLUDED

#include <assert.h>
#include <stddef.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void  lomutoQsort     (int* array, size_t size);

void  hoarQsort       (int* array, size_t size);

void  flagQsort       (int* array, size_t size);


#endif /* QSORT_H */