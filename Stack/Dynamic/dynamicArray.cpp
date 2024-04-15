#include "dynamicArray.h"

struct Stack* stackCreating(size_t size, size_t elemSize)
{
  if (size == 0 || elemSize == 0)
  {
    exit(errCreating);
  }

  struct Stack * stack = (struct Stack *) malloc(sizeof(struct Stack));// Memory allocation for the structure 
  if (stack == NULL) 
  {
    exit(errMemory);
  }

  stack->array = malloc(size * elemSize);// Memory allocation for the array of elements
  if (stack->array == NULL) 
  {
      free(stack); 
      return NULL;
  }

  stack->capacity = size; 
  stack->elemSize = elemSize;
  stack->size = 0;

  return stack; // Return a pointer to the created stack
}


bool checkStack(struct Stack* stack)// Function to check stack structure arguments 
{
  if (stack == NULL || stack->array == NULL || stack->capacity == 0 || stack->elemSize == 0)
    return false;
  else
    return true;
}

int stackReserve(struct Stack* stack) 
{
  size_t capacityNew = (stack->capacity == 0) ? 1 : stack->capacity * 2;
  void * arrayNew = realloc(stack->array, capacityNew * stack->elemSize);
  if (arrayNew == NULL) 
  {
    exit(errExpansion);
  }
  stack->array = arrayNew;
  stack->capacity = capacityNew;
  return success;
}

int pushArray(struct Stack* stack, void* buffer) 
{
  
  if (buffer == NULL || !checkStack(stack))
  {
    exit(errArguments);
  }
  
  if (stack->size >= stack->capacity) // Check for space availability in the stack
  {
    if (!stackReserve(stack))
      return failure;
  }

  memcpy((char *)stack->array + stack->size * stack->elemSize, buffer, stack->elemSize); // Copying the element into the stack
  stack->size++;
  return success;
}

int topArray(struct Stack* stack, void* buffer)
{
  
  if (buffer == NULL || !checkStack(stack))
  {
    exit(errArguments);
  } 
  
  memcpy(buffer, (char *)stack->array + (stack->size - 1) * stack->elemSize, stack->elemSize);// Copy the last element of the stack into the buffer
  return success;
}

int popArray(struct Stack* stack)
{
  
  if (!checkStack(stack))
  {
    exit(errArguments);
  }
  
  stack->size--;
  
  if (stack->size <= stack->capacity / 4 && stack->capacity >= 2)// Decrease capacity if necessary
  {
    size_t capacityNew = stack->capacity / 2;
    void* arrayNew = realloc(stack->array, capacityNew * stack->elemSize);
    if (arrayNew == NULL) 
    {
      exit(errDrain);
    }
    else 
    {
      stack->array = arrayNew;
      stack->capacity = capacityNew;
    }
  }
  return success;
}

struct Stack * destructionStack(struct Stack * stack) 
{ 
  if (checkStack(stack)) 
  {
    free(stack->array);
    free(stack);
  }
  return NULL; // Return NULL after destroying the stack
}
