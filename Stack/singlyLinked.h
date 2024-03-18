#ifndef SINGLTLINKED_H_INCLUDED
#define SINGLTLINKED_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


struct Node             // Структура для представления элемента списка
{
  void * data;          //Указатель на данные 
  struct Node * next;   //Указатель на следующий эллкмент
};



struct StackLinked            // Структура для представления стека на основе односвязного списка
{
  struct Node * head;         // Указатель на вершину стека
  size_t size;                // Текущий размер стека
};

struct Node  * creatingNode(void * data, size_t elemSize);                        // Создание нового узла списка

struct StackLinked * stackCreatLinked(void);                                      // Создание стека

struct StackLinked * destructionStackLinked(struct StackLinked * stack);          // Уничтожение стека

int     linkedPush  (struct StackLinked * stack, void * data);                    // Добавление элемента в стек

int     linkedTop   (struct StackLinked * stack, void * buffer);                  // Возвращает последний элемент стека

int     linkedPop   (struct StackLinked * stack);                                 // Удаляет последний элемент стека

bool    checkStackLinked   (struct StackLinked * stack);                          // Проверка параметров стека

void    destructioNode     (struct Node * node);                                  // Уничтожение узла списка

#endif