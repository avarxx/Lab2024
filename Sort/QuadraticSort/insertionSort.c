#include "quadraticSort.h"

void insertionSort(int* array, size_t size)
{
	assert(array != NULL);

	for (size_t i = 1; i < size; i++) 
	{
		int key = array[i];
		int j   = i - 1;
		while (j >= 0 && array[j] > key) 
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
}
