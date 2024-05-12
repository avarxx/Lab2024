#include "skipList.h"

Node* createNodeSkipList(int key, int level) 
{
  Node *newNode    = (Node*) malloc(sizeof(Node));
  newNode->key     = key;
  newNode->forward = (Node**) malloc(sizeof(Node*) * (level + 1));
  memset(newNode->forward, 0, sizeof(Node*) * (level + 1));
  return newNode;
}

SkipList* createSkipList(int MAXLVL, float P) 
{
  SkipList *list = (SkipList*) malloc(sizeof(SkipList));
  list->MAXLVL   = MAXLVL;
  list->P        = P;
  list->level    = 0;
  list->header   = createNodeSkipList(-1, MAXLVL);
  return list;
}

int randomLevelSkipList(SkipList *list) 
{
  assert(list);
  float r = (float)rand() / RAND_MAX;
  int level = 0;
  while (r < list->P && level < list->MAXLVL) 
  {
    level++;
    r = (float)rand() / RAND_MAX;
  }
  return level;
}

void insertElementSkipList(SkipList *list, int key) 
{
  assert(list);
  Node *current = list->header;
  Node *update[list->MAXLVL + 1];
  memset(update, 0, sizeof(Node*) * (list->MAXLVL + 1));

  for (int i = list->level; i >= 0; i--) 
  {
    while (current->forward[i] != NULL && current->forward[i]->key < key) 
    {
      current = current->forward[i];
    }
    update[i] = current;
  }

  current = current->forward[0];

  if (current == NULL || current->key != key) 
  {
    int rlevel = randomLevelSkipList(list);

    if (rlevel > list->level) 
    {
      for (int i = list->level + 1; i < rlevel + 1; i++) 
      {
        update[i] = list->header;
      }
      list->level = rlevel;
    }

    Node* newNode = createNodeSkipList(key, rlevel);

    for (int i = 0; i <= rlevel; i++) 
    {
      newNode->forward[i] = update[i]->forward[i];
      update[i]->forward[i] = newNode;
    }
  }
}

void removeElementSkipList(SkipList *list, int key) 
{
  assert(list);
  Node *current = list->header;
  Node *update[list->MAXLVL + 1];
  memset(update, 0, sizeof(Node*) * (list->MAXLVL + 1));

  for (int i = list->level; i >= 0; i--) 
  {
    while (current->forward[i] != NULL && current->forward[i]->key < key) 
    {
      current = current->forward[i];
    }
    update[i] = current;
  }
  current = current->forward[0];

  if (current != NULL && current->key == key) 
  {
    for (int i = 0; i <= list->level; i++) 
    {
      if (update[i]->forward[i] != current) 
      {
        break;
      }
      update[i]->forward[i] = current->forward[i];
    }

    while (list->level > 0 && list->header->forward[list->level] == NULL) 
    {
      list->level--;
    }

    free(current);
  } 
  else 
  {
    exit(errKey);
  }
}

void displayList(SkipList *list) 
{
  assert(list);
  printf("\n*****Skip List*****\n");
  for (int i = 0; i <= list->level; i++) 
  {
    Node *node = list->header->forward[i];
    printf("Level %d: ", i);
    while (node != NULL) 
    {
      printf("%d ", node->key);
      node = node->forward[i];
    }
    printf("\n");
  }
}


int* createArray(int size) 
{
  int* array = malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++) 
  {
    array[i] = i + 1; 
  }
  return array;
}

double insertTime(SkipList *list, int *values, int numInsertions) 
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

double deleteTime(SkipList *list, int *values, int numDeletions) 
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
void runTest(int numInsertions, int numDeletions, 
             FILE* fileInsert, FILE* fileDelete) 
{
  const int numberOfTest  = 5;
  double* insertTimes = (double*)calloc(numberOfTest, sizeof(double));
  double* deleteTimes = (double*)calloc(numberOfTest, sizeof(double));

  for (int i = 0; i < numberOfTest; i++) 
  {
    SkipList *list = createSkipList(10, 0.5);
    int *values    = createArray(numInsertions);
    insertTimes[i] = insertTime(list, values, numInsertions);
    deleteTimes[i] = deleteTime(list, values, numDeletions);
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

int main(int argc, const char* argv) 
{
  const int minSize = 100000;
  const int maxSize = 1000000;
  const int step    = 100000;
  FILE* fileInsert = fopen("skip_list_insert.txt", "w");
  FILE* fileDelete = fopen("skip_list_delete.txt", "w");
  for (int size = minSize; size <= maxSize; size += step) 
  { 
    printf("size %d\n", size);
    runTest(size, size / 2, fileInsert, fileDelete);
  }
  fclose(fileDelete);
  fclose(fileInsert);
  return 0;
}
