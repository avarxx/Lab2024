#include "searchTree.h"


BinaryTreeNode* newNodeCreate(int value) 
{
	BinaryTreeNode* newNode = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	assert(newNode);
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



