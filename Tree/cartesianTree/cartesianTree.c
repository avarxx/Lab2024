#include "cartesianTree.h"

Node* createNodeCartesian(int value) 
{
  Node* newNode = (Node*)malloc(sizeof(Node));
  assert(newNode);
  newNode->value = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node* insertNodeCartesian(Node* root, int value) 
{
  if (root == NULL)
    return createNodeCartesian(value);

  Node* current = root;
  Node* parent = NULL;
  while (current != NULL) 
  {
    parent = current;
    if (value < current->value)
      current = current->left;
    else
      current = current->right;
  }
  if (value < parent->value)
    parent->left = createNodeCartesian(value);
  else
    parent->right = createNodeCartesian(value);
  return root;
}

Node* findMinimumCartesian(Node* root) 
{
  if (root == NULL)
    return NULL;

  Node* current = root;
  while (current->left != NULL)
    current = current->left;
  return current;
}

Node* deleteNodeCartesian(Node* root, int value) 
{
  if (root == NULL)
    return NULL;

  Node* current = root;
  Node* parent = NULL;
  while (current != NULL && current->value != value) 
  {
    parent = current;
    if (value < current->value)
      current = current->left;
    else
      current = current->right;
  }

  if (current == NULL)
    return root;

  if (current->left == NULL && current->right == NULL) 
  {
    if (current == root)
      return NULL;
    if (current == parent->left)
      parent->left = NULL;
    else
      parent->right = NULL;
    free(current);
  } 
  else if (current->left == NULL) 
  {
    if (current == root)
      return root->right;
    if (current == parent->left)
      parent->left = current->right;
    else
      parent->right = current->right;
    free(current);
  } 
  else if (current->right == NULL) 
  {
    if (current == root)
      return root->left;
    if (current == parent->left)
      parent->left = current->left;
    else
      parent->right = current->left;
    free(current);
  } 
  else 
  {
    Node* minNode = findMinimumCartesian(current->right);
    current->value = minNode->value;
    current->right = deleteNodeCartesian(current->right, minNode->value);
  }

  return root;
}

int* randomData(size_t size) 
{
  int* data = (int*)malloc(size * sizeof(int));
  assert(data);
  for (size_t i = 0; i < size; i++) 
  {
    data[i] = rand();
  }
  return data;
}

int* sortData(size_t size) 
{
  int* data = (int*)malloc(size * sizeof(int));
  assert(data);
  for (size_t i = 0; i < size; i++) 
  {
    data[i] = i + 1;
  }
  return data;
}

void printTree(Node* root) 
{
  if (root == NULL)
    return;
  printTree(root->left);
  printf("%d ", root->value);
  printTree(root->right);
}

