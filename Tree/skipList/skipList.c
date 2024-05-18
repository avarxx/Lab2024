#include "skipList.h"

Node* createNodeSkipList(int key, int level) 
{
  Node *newNode    = (Node*) malloc(sizeof(Node));
  assert(newNode);
  newNode->key     = key;
  newNode->forward = (Node**) malloc(sizeof(Node*) * (level + 1));
  assert(newNode->forward);
  memset(newNode->forward, 0, sizeof(Node*) * (level + 1));
  return newNode;
}

SkipList* createSkipList(int MAXLVL, float P) 
{
  SkipList *list = (SkipList*) malloc(sizeof(SkipList));
  assert(list);
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
