#ifndef SPLAY_TREE_H_INCLUDED
#define SPLAY_TREE_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <errno.h>
#include <time.h>

typedef struct Node 
{
  int key;
  struct Node* left;
  struct Node* right;
} Node;

Node* insertSplay(Node* root, int key);

Node* splay(Node* root, int key);

Node* leftRotateSplay(Node* x);

Node* rightRotateSplay(Node* x);

Node* newNodeSplay(int key);

Node* splay(Node* root, int key);

Node* deleteSplay(Node* root, int key);


#endif