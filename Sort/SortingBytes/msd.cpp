#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

const int SIZE = 256;

void msd(int* array, int size, size_t shift)
{
  if (size == 0) 
    return;

  unsigned int mask = 255 << shift;
  int* sorted = (int*) calloc(size, sizeof(int));
  int* count  = (int*)calloc(SIZE,sizeof(int));

  for (int i = 0; i < size; i++)
    count[(array[i] & mask) >> shift]++;

  for (int i = 1; i < 256; i++)
    count[i] += count[i - 1];

  for (int i = 0; i < size; i++)
      sorted[--count[(array[size - 1 - i] & mask) >> shift]] = array[size - 1 - i];

  memcpy(array, sorted, size * sizeof(int));

  if (shift > 0)
  {
    msd(array, count[0], shift - 8);

    for (int i = 1; i < 256; i++)
        msd(array + count[i - 1], count[i] - count[i - 1], shift - 8);
  }

  free(sorted);
}

void msdSort(int* array, size_t size) 
{
  msd(array, size, 8 * (sizeof(int) - 1));
}

