#include "singlyLinked.h"

// Creating a new node of the linked list
struct Node* creatingNode(void * data, size_t elemSize) 
{ 
    if (data == NULL)
    {
      exit(errMemoryLinked);
    }
    // Memory allocation for the linked list node structure
    struct Node* node = (struct Node *) malloc(sizeof(struct Node));
    if (node == NULL) 
    {
        printf("Memory allocation error in creatingNode");
        return NULL;
    }

    node->data = malloc(elemSize);
    if (node->data == NULL) 
    {
        printf("Memory allocation error in creatingNode");
        free(node); 
        return NULL;    
    // Return NULL in case of memory allocation error
    }

    memcpy(node->data, data, elemSize);
    node->next = NULL;  
    // Set the pointer to the next element of the list to NULL
    return node; 
}

// Destroying a node of the linked list
void destructioNode (struct Node * node) 
{
    if (node != NULL) 
    {
        free(node -> data); // Free the memory allocated for the node's data
        free(node);         // Free the memory allocated for the node
    }
}


// Creating a stack based on a singly linked list
struct StackLinked * stackCreatLinked(void) 
{
    struct StackLinked * stack = (struct StackLinked *) malloc(sizeof(struct StackLinked));
    if (stack == NULL) 
    {
        printf("Linked stack memory allocation failure\n");
        return NULL; 
    }

    stack->head = NULL; // Initializing the pointer to the stack top (head of the list)
    stack->size = 0;    // Initializing the size of the stack (number of elements)
    return stack;       // Returning a pointer to the created stack
}

bool checkStackLinked(struct StackLinked* stack) 
{
    if (stack == NULL)
        return false;
    else
        return true;
}



// Adding an element to the stack
int pushLinked(struct StackLinked * stack, void * data) 
{
    if (!checkStackLinked(stack) || data == NULL)
    {
      exit(errArgument);
    }
    // Creating a new node of the linked list to store data
    struct Node * nodeNew = creatingNode(data, sizeof(data));
    if (nodeNew == NULL) 
    {
      exit(errMemoryLinked);
    }

    // Setting the pointer to the next element of the new node to the current stack top
    nodeNew->next = stack->head;
    // Updating the pointer to the stack top
    stack->head = nodeNew;
    // Increasing the size of the stack
    stack->size++;
    return success;
}


// Returning the top element of the stack based on a singly linked list
int topLinked(struct StackLinked * stack, void * buffer) 
{
  if (!checkStackLinked(stack) || stack->size == 0 || buffer == NULL) 
  {
    exit(errInitializing);
  }
  memcpy(buffer, stack->head->data, sizeof(stack->head->data));
  return success;
}


// Removing the top element of the stack based on a singly linked list
int popLinked(struct StackLinked * stack) 
{
  if (!checkStackLinked(stack) || stack->size == 0) 
  {
    exit(errArgument);
  }

  struct Node *temp = stack->head;    // Saving the pointer to the stack top
  stack->head = stack->head->next;    // Updating the pointer to the stack top to the next element
  destructioNode(temp);               
  stack->size--;                      
  return success; 
}

// Destroying the stack based on a singly linked list
struct StackLinked * destructionStackLinked(struct StackLinked * stack) 
{
  if (!checkStackLinked(stack))
  {
    exit(errArgument);
  }

  while (stack->head != NULL) 
  {
      struct Node *temp = stack->head; // Saving the pointer to the stack top
      stack->head = stack->head->next; // Updating the pointer to the stack top to the next element
      destructioNode(temp); 
  }

  free(stack); // Freeing the memory allocated for the stack structure
}