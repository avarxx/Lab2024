#include "searchTree.h"

void testRandomInsertionsSearch(BinaryTreeNode** root, int size) 
{
	srand(time(NULL));
	for (int i = 0; i < size; i++) 
	{
		*root = insertNode(*root, rand() % MAX_SIZE);
	}
}

void testDeletionsSearch(BinaryTreeNode** root, int size) 
{
	srand(time(NULL));
	for (int i = 0; i < size / 2; i++) 
	{
		*root = delete(*root, rand() % MAX_SIZE);
	}
}

void testSortedInsertionsSearch(BinaryTreeNode** root, int size) 
{
	for (int i = 0; i < size; i++) 
	{
		*root = insertNode(*root, i + 10);
	}
}

void testSortedDeletionsSearch(BinaryTreeNode** root, int size) 
{
	for (int i = 0; i < size / 2; i++) 
	{
		*root = delete(*root, i + 10);
	}
}

double measureTimeSearch(void (*testFunction)(BinaryTreeNode**, int), BinaryTreeNode** root, int size) 
{
	clock_t start, end;
	double time;

	start = clock();
	for (int i = 0; i < NUM_REPETITIONS; i++) 
	{
		testFunction(root, size);
		freeMemory(*root);
		*root = NULL;
	}
	end = clock();

	time = ((double)(end - start)) / CLOCKS_PER_SEC;
	return time / NUM_REPETITIONS;
}

int main() 
{
	BinaryTreeNode* root = NULL;
	FILE* file1 = fopen("bst_rand_insert.txt", "w");
	FILE* file2 = fopen("bst_rand_delete.txt", "w");
	FILE* file3 = fopen("bst_sort_insert.txt", "w");
	FILE* file4 = fopen("bst_sort_delete.txt", "w");

	for (int size = 100000; size <= MAX_SIZE; size += 100000) 
	{
		double totalTime;
    printf("size %d\n", size);
		totalTime = measureTimeSearch(testRandomInsertionsSearch, &root, size);
		fprintf(file1, "%d %.6f\n", size, totalTime);

		totalTime = measureTimeSearch(testDeletionsSearch, &root, size);
		fprintf(file2, "%d %.6f\n", size, totalTime);
	}

	fclose(file1);
	fclose(file2);
	fclose(file3);
	fclose(file4);
	return 0;
}