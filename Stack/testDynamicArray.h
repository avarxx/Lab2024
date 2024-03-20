#ifndef TESTDYNAMICARRAY_H_INCLUDED
#define TESTDYNAMICARRAY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "dynamicArray.h"

#define errorArguments printf("Error with incorrect arguments at %s:%d in function %s\n", __FILE__, __LINE__, __func__);
#define sizeTest 1000000

void    dynamicRemoveHalf   (struct Stack* stack);                      // Removes half of the stack

void    dynamicRemoveElem   (struct Stack* stack, int number);          // Removes a specified number of elements from the stack

void    dynamicAddQuarter   (struct Stack* stack);                      // Adds a quarter of the size to the stack

void    dynamicAddElem      (struct Stack * stack, int start, int end); // Adds a specific number of elements to the stack within the range from start to end

double  dynamicFirstTest    (void);

double  dynamicSecondTest   (void);

double  dynamicTestThee     (void);

int     dynamicTestFour     (void);
#endif
