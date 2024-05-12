#include "avlTree.h"

Node* createNodeAvl(int value)
{
  Node* node   = (Node*)malloc(sizeof(Node));
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
  int leftHeight  = getHeightAvl(tree->left);
  int rightHeight = getHeightAvl(tree->right);
  tree->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

Node* rotateLeftAvl(Node* one) 
{
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

  int balance = getBalanceAvl(root);

  if (balance > 1 && getBalanceAvl(root->left) >= 0)
    return rotateRightAvl(root);

  if (balance > 1 && getBalanceAvl(root->left) < 0) 
  {
    root->left = rotateLeftAvl(root->left);
    return rotateRightAvl(root);
  }

  if (balance < -1 && getBalanceAvl(root->right) <= 0)
    return rotateLeftAvl(root);

  if (balance < -1 && getBalanceAvl(root->right) > 0) 
  {
    root->right = rotateRightAvl(root->right);
    return rotateLeftAvl(root);
  }

  return root;
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

int main(int argc, const char* argv[]) 
{
  AVL avlTree;
  initBalancedAvl(&avlTree);
  FILE *file1 = fopen("avl_rand_insert.txt", "w");
  for (int size = 100000; size <= MAX_SIZE; size += 100000) 
  {
    double totalTime = measureTime(testRandomInsertions, &avlTree, size);
    fprintf(file1,"%d %.6f\n", size, totalTime);
  }
  fclose(file1);
  initBalancedAvl(&avlTree);
  FILE* file2 = fopen("avl_rand_delete.txt", "w");
  for (int size = 100000; size <= MAX_SIZE; size += 100000) 
  {
    double totalTime = measureTime(testDeletions, &avlTree, size);
    fprintf(file2,"%d %.6f\n", size, totalTime);
  }
  fclose(file2);
  destroyBalancedAvl(&avlTree);
  initBalancedAvl(&avlTree);
  FILE* file3 = fopen("avl_sort_insert.txt", "w");
  for (int size = 100000; size <= MAX_SIZE; size += 100000) 
  {
    double totalTime = measureTime(testSortedInsertions, &avlTree, size);
    fprintf(file3,"%d %.6f\n", size, totalTime);
  }
  fclose(file3);
  initBalancedAvl(&avlTree);
  FILE* file4 = fopen("avl_sort_delete.txt", "w");
  for (int size = 100000; size <= MAX_SIZE; size += 100000) 
  {
    double totalTime = measureTime(testSortedDeletions, &avlTree, size);
    fprintf(file4,"%d %.6f\n", size, totalTime);
  }
  fclose(file4);
  destroyBalancedAvl(&avlTree);
  return 0;
}

void testRandomInsertions(AVL* tree, int size) 
{
  srand(time(NULL));
  for (int i = 0; i < size; i++) 
  {
    addAvl(tree, rand());
  }
}

void testDeletions(AVL* tree, int size) 
{
  srand(time(NULL));
  for (int i = 0; i < size / 2; i++) 
  {
    deleteNodeAvl(tree->root, rand());
  }
}

void testSortedInsertions(AVL* tree, int size) 
{
  for (int i = 0; i < size; i++) 
  {
    addAvl(tree, i);
  }
}

void testSortedDeletions(AVL* tree, int size) 
{
  srand(time(NULL));
  for (int i = 0; i < size / 2; i++) 
  {
    deleteNodeAvl(tree->root, i);
  }
}

double measureTime(void (*testFunction)(AVL*, int), AVL* tree, int size) 
{
  clock_t start, end;
  double time;
  start = clock();
  for (int i = 0; i < NUM_REPETITIONS; i++) 
  {
    testFunction(tree, size);
  }
  end = clock();
  time = ((double) (end - start)) / CLOCKS_PER_SEC;
  return time;
}

