#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 256

void lsdSort(int *array, size_t size) 
{
  for (unsigned int mask = 0xff, shift = 0; mask > 0; mask <<= 8, shift += 8) 
  {
    int *prefix_cnt = (int*)calloc(MAX_SIZE, sizeof(int));
    assert(prefix_cnt != NULL);
    
    for (int i = 0; i < size; ++i) 
    {
      prefix_cnt[(array[i] & mask) >> shift]++;
    }
    for (int i = 1; i < MAX_SIZE; ++i) 
    {
      prefix_cnt[i] += prefix_cnt[i - 1];
    }
    
    int *res = (int*)malloc(size * sizeof(int));
    assert(res != NULL);
    
    for (int i = size - 1; i >= 0; --i) 
    {
      res[--prefix_cnt[(array[i] & mask) >> shift]] = array[i];
    }
    memcpy(array, res, sizeof(int) * size);
    
    free(prefix_cnt);
    free(res);
  }
}
