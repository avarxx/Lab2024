#include "splayTree.h"

Node* newNodeSplay(int key) 
{
  Node* node  = (Node*)malloc(sizeof(Node));
  node->key   = key;
  node->left  = NULL;
  node->right = NULL;
  return node;
}

Node* rightRotateSplay(Node* x) 
{
  Node* y  = x->left;
  x->left  = y->right;
  y->right = x;
  return y;
}

Node* leftRotateSplay(Node* x) 
{
  Node* y  = x->right;
  x->right = y->left;
  y->left  = x;
  return y;
}

Node* splay(Node* root, int key) 
{
  if (root == NULL || root->key == key)
    return root;

  if (root->key > key) 
  {
    if (root->left == NULL)
        return root;

      if (root->left->key > key) 
      {
        root->left->left = splay(root->left->left, key);
        root = rightRotateSplay(root);
      } 
      else 
      {
        root->left = splay(root->left, key);
      }

    return (root->left == NULL) ? root : rightRotateSplay(root);
  } 
  else 
  {
    if (root->right == NULL)
      return root;

    if (root->right->key < key) 
    {
      root->right->right = splay(root->right->right, key);
      root = leftRotateSplay(root);
    } else 
    {
      root->right = splay(root->right, key);
    }

    return (root->right == NULL) ? root : leftRotateSplay(root);
  }
}

Node* insertSplay(Node* root, int key) 
{
  if (root == NULL)
    return newNodeSplay(key);

  root = splay(root, key);

  if (root->key == key)
    return root;

  Node* node = newNodeSplay(key);

  if (root->key > key) 
  {
    node->right = root;
    node->left  = root->left;
    root->left  = NULL;
  } 
  else
  {
    node->left  = root;
    node->right = root->right;
    root->right = NULL;
  }

  return node;
}

Node* deleteSplay(Node* root, int key) 
{
  if (root == NULL) return root;
  root = splay(root, key);
  if (root->key != key) return root;
  if (root->left == NULL && root->right == NULL) 
  {
    free(root);
    return NULL;
  }
  if (root->left == NULL) 
  {
    Node* temp = root->right;
    free(root);
    return temp;
  } else if (root->right == NULL) 
  {
    Node* temp = root->left;
    free(root);
    return temp;
  }
  Node* temp = root->left;
  while (temp->right != NULL) 
  {
    temp = temp->right;
  }
  root->key = temp->key;
  root->left = deleteSplay(root->left, temp->key);

  return root;
}

double insertTime(Node* root, int numInserts) 
{
  clock_t start, end;
  double insertTime = 0.0;

  start = clock();
  for (int i = 0; i < numInserts; i++) 
  {
    root = insertSplay(root, rand());
  }
  end = clock();
  insertTime = ((double)(end - start)) / CLOCKS_PER_SEC;
  return insertTime;
}

double deleteTime (Node* root, int numDeletes)
{
  clock_t start, end;
  double deleteTime = 0.0;
  start = clock();
  for (int i = 0; i < numDeletes; i++) 
  {
    root = deleteSplay(root, rand());
  }
  end = clock();
  deleteTime = ((double)(end - start)) / CLOCKS_PER_SEC;

  return deleteTime;
}

int main(int argc, const char* argv[]) 
{
  FILE* fileDelete = fopen("splay_delete.txt", "w");
  FILE* fileInsert = fopen("splay_insert.txt", "w");
  const int numTests = 10;
  const int maxSize = 1000000;
  const int numIterations = 5;

  for (int i = 0; i < numTests; i++) 
  {
    int size = (i + 1) * 100000;
    printf("%d\n", size);
    double totalInsertTime = 0.0, totalDeleteTime = 0.0;

    for (int j = 0; j < numIterations; j++) 
    {
      Node* root = NULL;
      double timeInsert = insertTime(root, size);
      double timeDelete = deleteTime(root, size /2);
      totalInsertTime += timeInsert;
      totalDeleteTime += timeDelete;
    }
    fprintf(fileInsert, "%d %0.6f\n", size,  totalInsertTime / numIterations);
    fprintf(fileDelete, "%d %0.6f\n", size,  totalDeleteTime / numIterations);
  }
  fclose(fileInsert);
  fclose(fileDelete);
  return 0;
}