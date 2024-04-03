#include <stdlib.h>

void swap3(int* first, int* second)
{
  int tmp = *first;
  *first = *second;
  *second = tmp;
}

int getChild(int index, int childIndex, int k) 
{
  return k * index + childIndex + 1;
}

void siftDown(int* array, int size, int index, int k)
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
      swap3(array + index, array + max);
      index = max;
    }
    else
    {
      break;
    }
  }
}

void Build(int* array, int n, int k)
{
  for (int i = (n - 1) / k; i >= 0; i--)
  {
      siftDown(array, n, i, k);
  }
}

void heapSort(int* array, int n, int k)
{
    Build(array, n, k);

    for (int i = n - 1; i > 0; i--)
    {
        swap3(array + 0, array + i);
        siftDown(array, i, 0, k);
    }
}

void heapSort5(int* array, size_t n)
{
    int k = 5;
    heapSort(array, n, k);
}

void heapSort2(int* array, size_t n)
{
    int k = 2;
    heapSort(array, n, k);
}

void heapSort3(int* array, size_t n)
{
    int k = 3;
    heapSort(array, n, k);
}

void heapSort4(int* array, size_t n)
{
    int k = 4;
    heapSort(array, n, k);
}
