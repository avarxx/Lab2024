#ifndef CARTESIAN_TREE_H_INCLUDED
#define CARTESIAN_TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <errno.h>
#include <time.h>

typedef struct Node 
{
  int value;
  struct Node* left;
  struct Node* right;
} Node;


Node* deleteNodeCartesian   (Node* root, int value);

Node* findMinimumCartesian  (Node* root);

Node* insertNodeCartesian   (Node* root, int value);

Node* createNodeCartesian   (int value); 

int*  randomData            (size_t size);

int*  sortData              (size_t size);

double insertTime           (Node* root, int* data, int numInsert);

double deleteTime           (Node* root, int* data, int numDelete);

void tests(int numInsert, int numDelete, FILE* file1, FILE* file2, FILE* file3, FILE* file4);

#endif