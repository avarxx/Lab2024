#ifndef DYNAMICARRAY_H_INCLUDED
#define DYNAMICARRAY_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

#include "C:\algorithms\Lab2024\Stack\enum.h"

struct Stack                       // Stack structure
{                                           
  void*   array;                   // Dynamic array 
  size_t  elemSize;                // Size of one element 
  size_t  capacity;                // Capacity of the stack 
  size_t  size;                    // Number of elements in the stack 
};

struct Stack* stackCreating(size_t size, size_t elemSize);          // Creates an array of the specified size, which will be dynamically resized during execution

struct Stack* destructionStack (struct Stack * stack);              // Destroys the container, freeing memory

int     pushArray (struct Stack* stack, void* buffer);            // Adds an element to the end of the container, returns 1 if successful, 0 otherwise

int     topArray  (struct Stack* stack, void* buffer);            // Returns the last element

int     popArray  (struct Stack* stack);                          // Removes the last element without returning it, returns 1 on success, 0 on failure

bool    checkStack  (struct Stack* stack);                          // Checks the arguments

#endif
