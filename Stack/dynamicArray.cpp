#include "dynamicArray.h"

struct Stack* stackCreating(size_t size, size_t elemSize)
{
  //Проверка аргументов 
  if (size == 0 || elemSize == 0)
  {
      printf("Error with incorrect arguments to creating stack.\n");
      return NULL;
  }
  
  //Выделение памяяти под структуру 
  struct Stack * stack = (struct Stack *) malloc(sizeof(struct Stack));
  if (stack == NULL) 
  {
      printf("Dynamic stack memory allocation failure.\n");
      return NULL;
  }

  //Выделение памяти под массив элементов
  stack->array = malloc(size * elemSize);
  if (stack->array == NULL) 
  {
      free(stack);//Очистка выделеной памяти при возникновении ошибки
      return NULL;
  }

  // Инициализация полей структуры стека
  stack->capacity = size; 
  stack->elemSize = elemSize;
  stack->size = 0;

  return stack; // Возвращаем указатель на созданный стек
}

// Функция проверки аргументов структуры 
bool checkStack (struct Stack* stack)
{
  if (stack == NULL || stack->array == NULL || stack->capacity == 0 || stack->elemSize == 0)
      return false;
  else
      return true;
}

int dynamicPush (struct Stack* stack, void* buffer)
{
  //Проверка аргументов
  if (buffer == NULL || !checkStack(stack))
  {
      printf("Error with incorrect arguments in push to dynamicArray.\n");
      return 0;
  }
  //Проверка наличия места в стеке
  if (stack->size >= stack->capacity)
  {
      //Перевыделение памяти
      size_t capacityNew = (stack->capacity == 0) ? 1 : stack->capacity * 2;
      void * arrayNew = realloc(stack->array, capacityNew * stack->elemSize);
      if (arrayNew == NULL)
      {
          printf("An error occurred during stack expansion\n");
          return 0;
      }
      stack->array = arrayNew;
      stack->capacity = capacityNew;
  }
  //копирование элемента в стек
  memcpy((char *)stack->array + stack->size * stack->elemSize, buffer, stack->elemSize);
  stack->size++;
  return 1;
}

int dynamicTop (struct Stack* stack, void* buffer)
{
  //Проверка аргументов
  if (buffer == NULL || !checkStack(stack))
  {
      printf("Error with incorrect arguments in top to dynamicArray.\n");
      return 0;
  } 
  // Копируем последний элемент стека в буфер
  memcpy(buffer, (char *)stack->array + (stack->size - 1) * stack->elemSize, stack->elemSize);
  return 1;
}

int dynamicPop (struct Stack* stack)
{
  //Проверка аргументов
  if (!checkStack(stack))
  {
      printf("Error with incorrect arguments in pop to dynamicArray.\n");
      return 0;
  }
  //Уменшение размера стека
  stack->size--;
  //Уменьшение емкости при необходимости
  if (stack->size <= stack->capacity / 2 && stack->capacity >= 2)
  {
      size_t capacityNew = stack->capacity / 2;
      void* arrayNew = realloc(stack->array, capacityNew * stack->elemSize);
      if (arrayNew == NULL)//проверка перевыделения памяти
      {
          printf("An error occurred while reducing the drain\n");
          return 0;
      }
      else //Переопределение параметров стека
      {
          stack->array = arrayNew;
          stack->capacity = capacityNew;
      }
  }
  return 1;
}

struct Stack * destructionStack(struct Stack * stack) 
{ // Проверка аргументов стека
  if (checkStack(stack)) 
  {
      // Освобождение памяти, выделенной для массива стека и самого стека
      free(stack->array);
      free(stack);
  }
  return NULL; // Возвращаем NULL после уничтожения стека
}
