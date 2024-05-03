#include "hashComparison.h"

NodeChains* createNode(int key, int value) 
{
  NodeChains* newNode = (NodeChains*)malloc(sizeof(NodeChains));
  if (newNode == NULL) 
  {
    perror("Memory allocation failed\n");
    exit(errno);
  }
  newNode->key   = key;
  newNode->value = value;
  newNode->next  = NULL;
  return newNode;
}

hashTableChains* createHashTable(size_t size) 
{
  hashTableChains* table = (hashTableChains*)malloc(sizeof(hashTableChains));
  if (table == NULL) 
  {
    perror("Memory allocation failed\n");
    exit(errno);
  }
  table->size  = size;
  table->array = (NodeChains**)malloc(size * sizeof(NodeChains*));
  if (table->array == NULL) 
  {
  perror("Memory allocation failed\n");
  exit(errno);
  }

  for (int i = 0; i < size; i++) 
  {
    table->array[i] = NULL;
  }
  return table;
}

int chainsHash(int key, int size) 
{
  return key % size;
}

void clainsInsert(hashTableChains* table, int key, int value) 
{
  int index     = chainsHash(key, table->size);
  NodeChains* newNode = createNode(key, value);
  newNode->next = table->array[index];
  table->array[index] = newNode;
}

NodeChains* chainsSearch(hashTableChains* table, int key)
{
  int index = chainsHash(key, table->size);
  NodeChains* current = table->array[index];
  while (current != NULL)
  {
    if (current->key == key)
    {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

void chainsDelete(hashTableChains* table, int key) 
{
  int index = chainsHash(key, table->size);
  NodeChains* current = table->array[index];
  NodeChains* prev = NULL;
  while (current != NULL && current->key != key) 
  {
    prev    = current;
    current = current->next;
  }
  if (current == NULL) 
  {
    return;
  }
  if (prev == NULL) 
  {
    table->array[index] = current->next;
  } else 
  {
    prev->next = current->next;
  }
  free(current);
}

void freeHashTable(hashTableChains* table) 
{
  if (table == NULL) 
    return;
  for (int i = 0; i < table->size; i++) 
  {
    NodeChains* current = table->array[i];
    while (current != NULL) 
    {
      NodeChains* temp = current;
      current = current->next;
      free(temp);
    }
  }
  free(table->array);
  free(table);
}
