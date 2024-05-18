#include "avlTree.h"


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