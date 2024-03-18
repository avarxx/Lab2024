#ifndef TESTDYNAMICARRAY_H_INCLUDED
#define TESTDYNAMICARRAY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "dynamicArray.h"

#define errorArguments printf("Error with incorrect arguments at %s:%d in function %s\n", __FILE__, __LINE__, __func__);
#define sizeTest 1000000

void dynamicRemoveHalf  (struct Stack* stack);                      //Удаляет половину стека 

void dynamicRemoveElem  (struct Stack* stack, int number);          //Удаляет определеннное колличество элементов стека 

void dynamicAddQuarter  (struct Stack* stack);                      //Добавляет в стек четверть от размера 

void dynamicAddElem     (struct Stack * stack, int start, int end); //Добавляет в стек определенное количество в интервале от start до end 

double dynamicFirstTest (void);

double dynamicSecondTest(void);

double dynamicTestThee  (void);

int    dynamicTestFour  (void);
#endif