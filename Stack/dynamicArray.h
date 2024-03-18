#ifndef DYNAMICARRAY_H_INCLUDED
#define DYNAMICARRAY_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

struct Stack                         //Структура стека 
{                                           
  void*   array;                   //Динамический массив 
  size_t  elemSize;                //Размер одного элемента 
  size_t  capacity;                //Вместимость стека 
  size_t  size;                    //Колличество элементов в стеке 
};

struct Stack* stackCreating(size_t size, size_t elemSize);          //создает массив заданного размера, который потом будет изменяться в ходе исполнения 

struct Stack* destructionStack (struct Stack * stack);              //Уничтожает контейнер, освобождая память

int     dynamicPush (struct Stack* stack, void* buffer);            //Добавляет элемент в конец контейнера, возвращает 1 если добавление успешно, 0 - не успешно

int     dynamicTop  (struct Stack* stack, void* buffer);            //Возвращает последний элемент

int     dynamicPop  (struct Stack* stack);                          // Удаляет последний элемент, не возвращая его, возвращает 1 - если успех, 0 - если ошибка

bool    checkStack  (struct Stack* stack);                          //Проверяет аргумент


#endif