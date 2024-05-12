#include "searchTree.h"


BinaryTreeNode* newNodeCreate(int value) 
{
	BinaryTreeNode* newNode = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	newNode->key   = value;
	newNode->left  = NULL;
	newNode->right = NULL;
	return newNode;
}

BinaryTreeNode* searchNode(BinaryTreeNode* root, int value)
{
	if (root == NULL || root->key == value)
		return root;

	if (root->key < value)
		return searchNode(root->right, value);

	return searchNode(root->left, value);
}

BinaryTreeNode* insertNode(BinaryTreeNode* node, int value)
{
	if (node == NULL) 
		return newNodeCreate(value);

	if (value < node->key)
		node->left = insertNode(node->left, value);

	else if (value > node->key)
		node->right = insertNode(node->right, value);

	return node;
}

BinaryTreeNode* delete(BinaryTreeNode* root, int value) 
{
	if (root == NULL)
		return NULL;

	if (value > root->key)
		root->right = delete(root->right, value);
	else if (value < root->key)
		root->left = delete(root->left, value);
	else 
	{
		if (root->left == NULL && root->right == NULL) 
		{
			free(root);
			return NULL;
		} 
		else if (root->left == NULL) 
		{
			BinaryTreeNode* temp = root->right;
			if (temp != NULL) 
			{
				free(root);
				return temp;
			} else 
			{
				free(root);
				return NULL;
			}
		} 
		else if (root->right == NULL) 
		{
			BinaryTreeNode* temp = root->left;
			free(root);
			return temp;
		} 
		else 
		{
			BinaryTreeNode* temp = findMin(root->right);
			root->key = temp->key;
			root->right = delete(root->right, temp->key);
		}
	}
	return root;
}

BinaryTreeNode* findMin(BinaryTreeNode* root)
{
	if (root == NULL) 
  {
		return NULL;
	}
	else if (root->left != NULL) 
  {
		return findMin(root->left);
	}
	return root;
}

void freeMemory(BinaryTreeNode* root) 
{
	if (root != NULL) 
	{
		freeMemory(root->left);
		freeMemory(root->right);
		free(root);
	}
}

void testRandomInsertions(BinaryTreeNode** root, int size) 
{
	srand(time(NULL));
	for (int i = 0; i < size; i++) 
	{
		*root = insertNode(*root, rand() % MAX_SIZE);
	}
}

void testDeletions(BinaryTreeNode** root, int size) 
{
	srand(time(NULL));
	for (int i = 0; i < size / 2; i++) 
	{
		*root = delete(*root, rand() % MAX_SIZE);
	}
}

void testSortedInsertions(BinaryTreeNode** root, int size) 
{
	for (int i = 0; i < size; i++) 
	{
		*root = insertNode(*root, i + 10);
	}
}

void testSortedDeletions(BinaryTreeNode** root, int size) 
{
	for (int i = 0; i < size / 2; i++) 
	{
		*root = delete(*root, i + 10);
	}
}

double measureTime(void (*testFunction)(BinaryTreeNode**, int), BinaryTreeNode** root, int size) 
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
		printf("%d\n", size);
		double totalTime;

		totalTime = measureTime(testRandomInsertions, &root, size);
		fprintf(file1, "%d %.6f\n", size, totalTime);

		totalTime = measureTime(testDeletions, &root, size);
		fprintf(file2, "%d %.6f\n", size, totalTime);
		// free(root);
		// root = NULL;
		// totalTime = measureTime(testSortedInsertions, &root, size);
		// fprintf(file3, "%d %.6f\n", size, totalTime);

		// totalTime = measureTime(testSortedDeletions, &root, size);
		// fprintf(file4, "%d %.6f\n", size, totalTime);
	}

	fclose(file1);
	fclose(file2);
	fclose(file3);
	fclose(file4);

	return 0;
}

