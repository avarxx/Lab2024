#ifndef SEARCH_TREE_H_INCLUDED
#define SEARCH_TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <limits.h>
#include <time.h>
#include <errno.h>

#define MAX_SIZE 1000000
#define NUM_REPETITIONS 5

typedef struct BinaryTreeNode
{
	int key;
	struct BinaryTreeNode *left, *right;
}BinaryTreeNode;

BinaryTreeNode* searchNode			(BinaryTreeNode* root, int value);

BinaryTreeNode* insertNode			(BinaryTreeNode* node, int value);

BinaryTreeNode* delete    			(BinaryTreeNode* root,	int x);

BinaryTreeNode* findMin   			(BinaryTreeNode* root);

BinaryTreeNode* newNodeCreate 	(int value);

void freeMemory									(BinaryTreeNode* root);
#endif