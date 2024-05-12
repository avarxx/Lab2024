#include "cartesianTree.h"

Node* createNodeCartesian(int value) 
{
  Node* newNode = (Node*)malloc(sizeof(Node));
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
  for (size_t i = 0; i < size; i++) 
  {
    data[i] = rand();
  }
  return data;
}

int* sortData(size_t size) 
{
  int* data = (int*)malloc(size * sizeof(int));
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

double insertTime(Node* root, int* data, int numInsert) 
{
  clock_t start = clock();
  for (int i = 0; i < numInsert; i++) 
  {
    root = insertNodeCartesian(root, data[i]);
  }
  clock_t end = clock();
  double time = ((double)(end - start)) / CLOCKS_PER_SEC;
  return time;
}

double deleteTime(Node* root, int* data, int numDelete) 
{
  clock_t start = clock();
  for (int i = 0; i < numDelete; i++) 
  {
      root = deleteNodeCartesian(root, data[i]);
  }
  clock_t end = clock();
  double time = ((double)(end - start)) / CLOCKS_PER_SEC;
  return time;
}

void tests(int numInsert, int numDelete, FILE* fileInsert, FILE* fileDelete,
           FILE* fileInsertSort, FILE* fileDeleteSort) 
{
  int* dataRand = randomData(numInsert);
  int* dataSort = sortData(numInsert);
  double* inserts = (double*)malloc(5 * sizeof(double));
  double* deletes = (double*)malloc(5 * sizeof(double));
  double* insertsRand = (double*)malloc(5 * sizeof(double));
  double* deletesRand = (double*)malloc(5 * sizeof(double));

  for (int i = 0; i < 5; i++) 
  {
    Node* root = NULL;
    insertsRand[i] = insertTime(root, dataRand, numInsert);
    for (int j = 0; j < numInsert; j++) 
    {
      root = insertNodeCartesian(root, dataRand[j]);
    }
    deletesRand[i] = deleteTime(root, dataRand, numDelete);
    free(root);
    root = NULL;
    inserts[i] = insertTime(root, dataSort, numInsert);
    for (int j = 0; j < numInsert; j++) 
    {
      root = insertNodeCartesian(root, dataSort[j]);
    }
    deletes[i] = deleteTime(root, dataSort, numDelete);
    free(root);
  }
  double avgInsertRand = 0.0, avgDeleteRand = 0.0,
          avgInsertSort = 0.0, avgDeleteSort = 0.0;

  for (int i = 0; i < 5; i++) 
  {
    avgInsertRand += insertsRand[i];
    avgDeleteRand += deletesRand[i];
    avgInsertSort += inserts[i];
    avgDeleteSort += deletes[i];
  }
  fprintf(fileInsert, "%d %0.6f\n", numInsert,  avgInsertRand / 5);
  fprintf(fileDelete, "%d %0.6f\n", numDelete,  avgDeleteRand / 5);
  fprintf(fileInsertSort, "%d %0.6f\n", numInsert,  avgInsertSort / 5);
  fprintf(fileDeleteSort, "%d %0.6f\n", numDelete,  avgDeleteSort / 5);

  free(deletes);
  free(inserts);
  free(deletesRand);
  free(insertsRand);
  free(dataSort);
  free(dataRand);
}

int main(int argc, const char* argv[]) 
{
  srand(time(NULL));
  const int minSize = 10000;
  const int maxSize = 100000;
  const int step    = 10000;
  FILE* fileInsert = fopen("cartesian_insert_rand.txt", "w");
  FILE* fileDelete = fopen("cartesian_delete_rand.txt", "w");
  FILE* fileInsertSort = fopen("cartesian_insert_sort.txt", "w");
  FILE* fileDeleteSort = fopen("cartesian_delete_sort.txt", "w");
  for (int size = minSize; size <= maxSize; size += step) 
  {
    printf("size %d\n", size);
    tests(size, size / 2, fileInsert, fileDelete, fileInsertSort, fileDeleteSort);
  }
  fclose(fileDelete);
  fclose(fileInsert);
  fclose(fileInsertSort);
  fclose(fileDeleteSort);
  return 0;
}
