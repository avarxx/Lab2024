#ifndef DYNAMICARRAY_H_INCLUDED
#define DYNAMICARRAY_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

enum ERRDYNAMIC
{
  errCreating   = 10,     //Error with incorrect arguments to creating stack
  errMemory     = 11,     //Dynamic stack memory allocation failure
  errExpansion  = 12,     //An error occurred during stack expansion
  errArguments  = 13,     //Error with incorrect arguments in push to dynamicArray
  errDrain      = 14,     //An error occurred while reducing the drain
  errFile       = 15      //Error open file at tests
};

enum STATUS
{
  failure,
  success
};

struct Stack                       // Stack structure
{                                           
  void*   array;                   // Dynamic array 
  size_t  elemSize;                // Size of one element 
  size_t  capacity;                // Capacity of the stack 
  size_t  size;                    // Number of elements in the stack 
};

struct Stack* stackCreating(size_t size, size_t elemSize);          // Creates an array of the specified size, which will be dynamically resized during execution

struct Stack* destructionStack (struct Stack * stack);              // Destroys the container, freeing memory

int     dynamicPush (struct Stack* stack, void* buffer);            // Adds an element to the end of the container, returns 1 if successful, 0 otherwise

int     dynamicTop  (struct Stack* stack, void* buffer);            // Returns the last element

int     dynamicPop  (struct Stack* stack);                          // Removes the last element without returning it, returns 1 on success, 0 on failure

bool    checkStack  (struct Stack* stack);                          // Checks the arguments

#endif
