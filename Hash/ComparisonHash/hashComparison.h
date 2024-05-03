#ifndef HASH_COMPARISON_H_INCLUDED
#define HASH_COMPARISON_H_INCLUDED

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <assert.h>

typedef struct 
{
  int key;
  int value;
  struct NodeChains* next;
}NodeChains;

typedef struct 
{
  int size;     
  NodeChains** array;
} hashTableChains;

hashTableChains* createHashTable  (size_t size);

int chainsHash                    (int key, int size);

NodeChains* createNode            (int key, int value);

void freeHashTable                (hashTableChains* table);

NodeChains* chainsSearch          (hashTableChains* table, int key);

void chainsDelete                 (hashTableChains* table, int key);

void clainsInsert                 (hashTableChains* table, int key, int value);



#endif // HASH_COMPARISON_H//