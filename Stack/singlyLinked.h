#ifndef SINGLTLINKED_H_INCLUDED
#define SINGLTLINKED_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

enum ERRLINKED
{
  errInitializing = 21,     //There is currently no data available for initializing a new node
  errArgument     = 22,     //Error with incorrect arguments to function linked
  errMemory       = 23      //Memory allocation errors for a new node
};

enum STATUS
{
  failure,
  success
};

struct Node             // Structure to represent a linked list element
{
  void * data;          // Pointer to data 
  struct Node * next;   // Pointer to the next element
};



struct StackLinked            // Structure to represent a stack based on a singly linked list
{
  struct Node * head;         // Pointer to the stack top
  size_t size;                // Current size of the stack
};

struct Node  * creatingNode(void * data, size_t elemSize);                        // Creating a new node of the list

struct StackLinked * stackCreatLinked(void);                                      // Creating a stack

struct StackLinked * destructionStackLinked(struct StackLinked * stack);          // Destroying the stack

int     linkedPush  (struct StackLinked * stack, void * data);                    // Adding an element to the stack

int     linkedTop   (struct StackLinked * stack, void * buffer);                  // Returning the top element of the stack

int     linkedPop   (struct StackLinked * stack);                                 // Removing the top element of the stack

bool    checkStackLinked   (struct StackLinked * stack);                          // Checking stack parameters

void    destructioNode     (struct Node * node);                                  // Destroying a list node

#endif
