#include "avlTree.h"

Node* createNodeAvl(int value)
{
  Node* node   = (Node*)malloc(sizeof(Node));
  assert(node);
  node->value  = value;
  node->height = 1;
  node->left   = NULL;
  node->right  = NULL;
  return node;
}

int getHeightAvl(Node* tree) 
{
  if (tree == NULL)
    return 0;
  return tree->height;
}

int getBalanceAvl(Node* tree) 
{
  if (tree == NULL) 
    return 0;
  return (getHeightAvl(tree->right) - getHeightAvl(tree->left));
}

void updateHeightAvl(Node* tree) 
{
  assert(tree);
  int leftHeight  = getHeightAvl(tree->left);
  int rightHeight = getHeightAvl(tree->right);
  tree->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

Node* rotateLeftAvl(Node* one) 
{
  assert(one);
  Node* two  = one->right;
  Node* temp = two->left;
  two->left  = one;
  one->right = temp;
  updateHeightAvl(one);
  updateHeightAvl(two);
  return two;
}

Node* rotateRightAvl(Node* one) 
{
  assert(one);
  Node* two  = one->left;
  Node* temp = two->right;
  two->right = one;
  one->left  = temp;
  updateHeightAvl(one);
  updateHeightAvl(two);
  return two;
}

Node* balanceTreeAvl(Node* tree) 
{
  updateHeightAvl(tree);

  int balance = getBalanceAvl(tree);

  if (balance > 1) 
  {
    if (getBalanceAvl(tree->right) < 0) 
    {
      tree->right = rotateRightAvl(tree->right);
    }
    return rotateLeftAvl(tree);
  }

  if (balance < -1) 
  { 
    if (getBalanceAvl(tree->left) > 0) 
    {
      tree->left = rotateLeftAvl(tree->left);
    }
    return rotateRightAvl(tree);
  }

  return tree;
}

Node* insertAvl(Node* tree, int value) 
{
  if (tree == NULL) 
  {
    return createNodeAvl(value);
  }
  if (value < tree->value)
  {
    tree->left = insertAvl(tree->left, value);
  } 
  else 
  {
    tree->right = insertAvl(tree->right, value);
  }
  return balanceTreeAvl(tree);
}

Node* deleteNodeAvl(Node* root, int value) 
{
  if (root == NULL)
    return root;

  if (value < root->value)
    root->left = deleteNodeAvl(root->left, value);
  else if (value > root->value)
    root->right = deleteNodeAvl(root->right, value);
  else 
  {
    if (root->left == NULL || root->right == NULL) 
    {
      Node* temp = root->left ? root->left : root->right;

      if (temp == NULL) 
      {
        temp = root;
        root = NULL;
      } 
      else 
      {
        *root = *temp;
      }

      free(temp);
    } 
    else
    {
      Node* temp  = findMinAvl(root->right);
      root->value = temp->value;
      root->right = deleteNodeAvl(root->right, temp->value);
    }
  }

  if (root == NULL)
    return root;

  root->height = 1 + MAX(getHeightAvl(root->left), getHeightAvl(root->right));

  return balanceTreeAvl(root);
}


Node* findMinAvl(Node* root) 
{
  if (root == NULL)
    return NULL;
  else if (root->left == NULL)
    return root;
  return findMinAvl(root->left);
}

Node* searchNodeAvl(Node* node, int value) 
{
  if (node == NULL || value == node->value) 
  {
    return node;
  }

  if (value < node->value) 
  {
    return searchNodeAvl(node->left, value);
  }
  return searchNodeAvl(node->right, value);
}

void addAvl(AVL* tree, int value) 
{
  if (searchNodeAvl(tree->root, value) == NULL) 
  {
    tree->root = insertAvl(tree->root, value);
  }
}

void freeMemoryAvl(Node* tree) 
{
  if (tree != NULL) 
  {
    freeMemoryAvl(tree->left);
    freeMemoryAvl(tree->right);
    free(tree);
  }
}

void initBalancedAvl(AVL* tree) 
{
  tree->root = NULL;
}

void destroyBalancedAvl(AVL* tree) 
{
  freeMemoryAvl(tree->root);
}



