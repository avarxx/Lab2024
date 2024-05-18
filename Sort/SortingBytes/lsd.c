#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 256

void lsd(int* array, int* res, size_t n) 
{
  assert(array);
  assert(res);

  for (unsigned int mask = 0xff, shift = 0; mask > 0; mask <<= 8, shift += 8) 
  {
    unsigned int pref_cnt[MAX];
    memset(pref_cnt, 0, sizeof(pref_cnt));
    
    for (size_t i = 0; i < n; ++i) 
    {
      pref_cnt[(array[i] & mask) >> shift]++;
    }
    
    for (size_t i = 1; i < MAX; ++i) 
    {
      pref_cnt[i] += pref_cnt[i - 1];
    }
    
    for (int i = (int)n - 1; i >= 0; --i) 
    {
      res[--pref_cnt[(array[i] & mask) >> shift]] = array[i];
    }
    
    memcpy(array, res, sizeof(int) * n); 
  }
}

void lsdSort(int* array, size_t size) 
{
  int* res = (int*)malloc(size * sizeof(int));
  assert(res   != NULL);
  assert(array != NULL);
  lsd(array, res, size);
  free(res);
}