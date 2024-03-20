#include "dynamicArray.h"

struct Stack* stackCreating(size_t size, size_t elemSize)
{
  if (size == 0 || elemSize == 0)// Check arguments 
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
      free(stack); // Freeing allocated memory in case of error
      return NULL;
  }

  stack->capacity = size; // Initialization of stack structure fields
  stack->elemSize = elemSize;
  stack->size = 0;

  return stack; // Return a pointer to the created stack
}


bool checkStack (struct Stack* stack)// Function to check stack structure arguments 
{
  if (stack == NULL || stack->array == NULL || stack->capacity == 0 || stack->elemSize == 0)
    return false;
  else
    return true;
}

int stackReserve(struct Stack* stack)  // Reallocate memory
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

int dynamicPush (struct Stack* stack, void* buffer) 
{
  
  if (buffer == NULL || !checkStack(stack)) // Check arguments
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

int dynamicTop (struct Stack* stack, void* buffer)
{
  
  if (buffer == NULL || !checkStack(stack))// Check arguments
  {
    exit(errArguments);
  } 
  
  memcpy(buffer, (char *)stack->array + (stack->size - 1) * stack->elemSize, stack->elemSize);// Copy the last element of the stack into the buffer
  return success;
}

int dynamicPop (struct Stack* stack)
{
  
  if (!checkStack(stack))// Check arguments
  {
    exit(errArguments);
  }
  
  stack->size--;// Decrease stack size
  
  if (stack->size <= stack->capacity / 4 && stack->capacity >= 2)// Decrease capacity if necessary
  {
    size_t capacityNew = stack->capacity / 2;
    void* arrayNew = realloc(stack->array, capacityNew * stack->elemSize);
    if (arrayNew == NULL) // Check for memory reallocation
    {
      exit(errDrain);
    }
    else // Redefine stack parameters
    {
      stack->array = arrayNew;
      stack->capacity = capacityNew;
    }
  }
  return success;
}

struct Stack * destructionStack(struct Stack * stack) 
{ 
  if (checkStack(stack)) // Check stack arguments
  {
    free(stack->array);
    free(stack);
  }
  return NULL; // Return NULL after destroying the stack
}
