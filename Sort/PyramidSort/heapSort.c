#include "heap.h"

int getChild(int index, int childIndex, int k) 
{
  return k * index + childIndex + 1;
}

void siftDown(int* array, size_t size, int index, int k)
{
  int max = index;
  while (true)
  {
    for (int i = 0; i < k; i++)
    {
      int child = getChild(index, i, k);
      if (child < size && array[child] > array[max])
        max = child;
    }

    if (max != index)
    {
      swap(array + index, array + max);
      index = max;
    }
    else
    {
      break;
    }
  }
}

void Build(int* array, size_t n, int k)
{
  for (int i = (n - 1) / k; i >= 0; i--)
  {
    siftDown(array, n, i, k);
  }
}

void heapSort(int* array, size_t n, int k)
{
  Build(array, n, k);

  for (int i = n - 1; i > 0; i--)
  {
    swap(array + 0, array + i);
    siftDown(array, i, 0, k);
  }
}
