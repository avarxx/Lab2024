#include <stdio.h>
#include <stdlib.h>

#define KmaxByte 255
#define KoneByte 8
#define Ksize    256

int takeByte(int var, int position) 
{
  return ((var >> (KoneByte * position)) & KmaxByte);
}

void stableSort(int* array, int size, int* bts, int byte) 
{
  int* answer = (int*)malloc((size + 1) * sizeof(long long));
  for (int tmp = 1; tmp < Ksize; tmp++) 
  {
    bts[tmp] += bts[tmp - 1];
  }
  for (int tmp = size; tmp > 0; tmp--) 
  {
    answer[bts[takeByte(array[tmp], byte)]] = array[tmp];
    --bts[takeByte(array[tmp], byte)];
  }
  for (int tmp = 1; tmp <= size; tmp++) 
  {
    array[tmp] = answer[tmp];
  }
  free(answer);
}

void lsdSort(int* array, size_t size) 
{
  int* bytes = (int*)calloc(Ksize, sizeof(int));
  for (int iter = 0; iter < KoneByte; ++iter) 
  {
    for (int tmp = 1; tmp <= size; ++tmp) 
    {
      bytes[takeByte(array[tmp], iter)]++;
    }
    stableSort(array, size, bytes, iter);
    for (int tmp = 0; tmp < Ksize; tmp++) 
    {
      bytes[tmp] = 0;
    }
  }
  free(bytes);
}

