#include "splayTree.h"


double insertTimeSplay(Node* root, int numInserts) 
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

double deleteTimeSplay(Node* root, int numDeletes)
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

int main() 
{
  FILE* fileDelete = fopen("splay_delete.txt", "w");
  FILE* fileInsert = fopen("splay_insert.txt", "w");
  const int numTests = 10;
  const int numIterations = 5;

  for (int i = 0; i < numTests; i++) 
  {
    int size = (i + 1) * 100000;
    printf("%d\n", size);
    double totalInsertTime = 0.0, totalDeleteTime = 0.0;

    for (int j = 0; j < numIterations; j++) 
    {
      Node* root = NULL;
      double timeInsert = insertTimeSplay(root, size);
      double timeDelete = deleteTimeSplay(root, size /2);
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
