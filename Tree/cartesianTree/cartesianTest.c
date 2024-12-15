#include "cartesianTree.h"

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
  int* dataRand       = randomData(numInsert);
  int* dataSort       = sortData(numInsert);
  double* inserts     = (double*)malloc(5 * sizeof(double));
  double* deletes     = (double*)malloc(5 * sizeof(double));
  double* insertsRand = (double*)malloc(5 * sizeof(double));
  double* deletesRand = (double*)malloc(5 * sizeof(double));
  assert(inserts);
  assert(deletes);
  assert(dataRand);
  assert(dataSort);
  assert(insertsRand);
  assert(deletesRand);

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
  FILE* fileInsert     = fopen("cartesian_insert_rand.txt", "w");
  FILE* fileDelete     = fopen("cartesian_delete_rand.txt", "w");
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
