#ifndef AVL_TREE_H_INCLUDED
#define AVL_TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <errno.h>
#include <time.h>

#define MAX_SIZE 1000000
#define NUM_TESTS 10
#define NUM_REPETITIONS 5

#define MAX(x, y) ((x) > (y) ? (x) : (y))

typedef struct Node 
{
  int value;
  int height;
  struct Node* left;
  struct Node* right;
} Node;

typedef struct 
{
  Node* root;
} AVL;

int getHeightAvl                   (Node* tree);

int getBalanceAvl                  (Node* tree);

Node* createNodeAvl                (int value);

Node* rotateLeftAvl                (Node* one);

Node* rotateRightAvl               (Node* one);

Node* balanceTreeAvl               (Node* tree);

Node* deleteNodeAvl                (Node* root, int value);

Node* insertAvl                    (Node* tree, int value);

Node* searchNodeAvl                (Node* node, int value);

Node* findMinAvl                   (Node* root); 

void addAvl                        (AVL* tree, int value);

void updateHeightAvl               (Node* tree);

void freeMemoryAvl                 (Node* tree);

void initBalancedAvl               (AVL* tree);

void destroyBalancedAvl            (AVL* tree);

void testRandomInsertions          (AVL* tree, int size);

void testDeletions                 (AVL* tree, int size);

void testSortedInsertions          (AVL* tree, int size);

void testSortedDeletions           (AVL* tree, int size);

double measureTime                 (void (*testFunction)(AVL*, int), AVL* tree, int size);


#endif