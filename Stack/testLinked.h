#ifndef TESTLINKED_H_INCLUDED
#define TESTLINKED_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "singlyLinked.h"

#define errorArguments printf("Error with incorrect arguments at %s:%d in function %s\n", __FILE__, __LINE__, __func__);
#define sizeTest 1000000


void linkedRemoveHalf  (struct StackLinked* stack);                      //Удаляет половину стека 

void linkedRemoveElem  (struct StackLinked* stack, int number);          //Удаляет определеннное колличество элементов стека 

void linkedAddQuarter  (struct StackLinked* stack);                      //Добавляет в стек четверть от размера 

void linkedAddElem     (struct StackLinked* stack, int start, int end); //Добавляет в стек определенное количество в интервале от start до end 

double linkedFirstTest (void);

double linkedSecondTest(void);

double linkedTestThee  (void);

int    linkedTestFour  (void);
#endif