#include "skipList.h"


int* createArraySkip(int size) 
{
  int* array = malloc(sizeof(int) * size);
  assert(array);
  for (int i = 0; i < size; i++) 
  {
    array[i] = i + 1; 
  }
  return array;
}

double insertTimeSkip(SkipList *list, int *values, int numInsertions) 
{
  assert(list);
  assert(values);
  clock_t start = clock();
  for (int i = 0; i < numInsertions; i++) 
  {
    insertElementSkipList(list, values[i]);
  }
  clock_t end = clock();
  return ((double)(end - start)) / CLOCKS_PER_SEC;
}

double deleteTimeSkip(SkipList *list, int *values, int numDeletions) 
{
  assert(list);
  assert(values);
  clock_t start = clock();
  for (int i = 0; i < numDeletions; i++) 
  {
    removeElementSkipList(list, values[i]);
  }
  clock_t end = clock();
  return ((double)(end - start)) / CLOCKS_PER_SEC;
}
void testSkipList(int numInsertions, int numDeletions, 
             FILE* fileInsert, FILE* fileDelete) 
{
  const int numberOfTest  = 5;
  double* insertTimes = (double*)calloc(numberOfTest, sizeof(double));
  double* deleteTimes = (double*)calloc(numberOfTest, sizeof(double));
  assert(insertTimes);
  assert(deleteTimes);
  for (int i = 0; i < numberOfTest; i++) 
  {
    SkipList *list = createSkipList(10, 0.5);
    int *values    = createArraySkip(numInsertions);
    insertTimes[i] = insertTimeSkip(list, values, numInsertions);
    deleteTimes[i] = deleteTimeSkip(list, values, numDeletions);
    free(values);
    free(list);
  }
  double avgInsertTime = 0.0;
  double avgDeleteTime = 0.0;

  for (int i = 0; i < numberOfTest; i++) 
  {
    avgInsertTime += insertTimes[i];
    avgDeleteTime += deleteTimes[i];
  }
  fprintf(fileInsert, "%d %0.6f\n", numInsertions, avgInsertTime /= numberOfTest);
  fprintf(fileDelete, "%d %0.6f\n", numDeletions,  avgDeleteTime /= numberOfTest);
}

int main() 
{
  const int minSize = 100000;
  const int maxSize = 1000000;
  const int step    = 100000;
  FILE* fileInsert = fopen("skip_list_insert.txt", "w");
  FILE* fileDelete = fopen("skip_list_delete.txt", "w");
  for (int size = minSize; size <= maxSize; size += step) 
  { 
    printf("size %d\n", size);
    testSkipList(size, size / 2, fileInsert, fileDelete);
  }
  fclose(fileDelete);
  fclose(fileInsert);
  return 0;
}
