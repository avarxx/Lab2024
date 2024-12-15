#ifndef TESTLINKED_H_INCLUDED
#define TESTLINKED_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "singlyLinked.h"

#define errorArguments printf("Error with incorrect arguments at %s:%d in function %s\n", __FILE__, __LINE__, __func__);
#define sizeTest 1000000


void    linkedRemoveHalf    (struct StackLinked* stack);                        // Removes half of the stack 

void    linkedRemoveElem    (struct StackLinked* stack, int number);            // Removes a specified number of elements from the stack 

void    linkedAddQuarter    (struct StackLinked* stack);                        // Adds a quarter of the size to the stack 

void    linkedAddElem       (struct StackLinked* stack, int start, int end);    // Adds a specific number of elements to the stack within the range from start to end 

double  linkedFirstTest     (void);

double  linkedSecondTest    (void);

double  linkedTestThee      (void);

int     linkedTestFour      (void);
#endif
