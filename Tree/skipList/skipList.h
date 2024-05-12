#ifndef SKIP_LIST_INCLUDED_H
#define SKIP_LIST_INCLUDED_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <limits.h>
#include <errno.h>
#include <string.h>
#include <time.h>

enum ERRSKIP
{
  errKey = 11 // ключа нет в списке 
};
typedef struct Node 
{
  int key;
  struct Node **forward;
} Node;

typedef struct SkipList 
{
  int MAXLVL;
  int level;
  float P;
  Node *header;
} SkipList;


void removeElementSkipList(SkipList *list, int key);

void insertElementSkipList(SkipList *list, int key);

void displayList          (SkipList *list);

int randomLevelSkipList   (SkipList *list);

int* createArray          (int size);

double insertTime         (SkipList *list, int *values, int numInsertions);

double deleteTime         (SkipList *list, int *values, int numDeletions);

void runTest              (int numInsertions, int numDeletions, 
                           FILE* fileInsert, FILE* fileDelete);

SkipList* createSkipList  (int MAXLVL, float P);

Node* createNodeSkipList  (int key, int level);

#endif