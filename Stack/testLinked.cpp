#include "testLinked.h"

void linkedRemoveElem(struct StackLinked* stack, int number)
{
    if (!checkStackLinked(stack) && stack->size < 0)
    {
        errorArguments
        return;
    }
    while (number > 0 && stack->size > 0)
    {
        linkedPop(stack);
        number--;
    }
}

void linkedAddElem(struct StackLinked * stack, int start, int end)
{
  if (!checkStackLinked(stack) && start > end)
  {
    exit(errArgument);
  }
  for (int i = start; i <= end; i++)
  {
    linkedPush(stack, &i);
  }
}

void removeHalfAddQuaterLinked(struct StackLinked* stack)
{
  if (!checkStackLinked(stack) && stack->size) 
  {
    exit(errArgument);
  }

  size_t prev_size = stack -> size;

  linkedRemoveElem(stack, prev_size / 2);

  int start = (int) stack -> size + 1;
  int end = (int) stack -> size + prev_size / 4;
  linkedAddElem(stack, start, end);
}

double linkedFirstTest(void)
{
  struct StackLinked* stack = stackCreatLinked();
  double time = 0.0;

  linkedAddElem(stack, 1, sizeTest);

  for (int i = 0; i < 9; i++)
  {
    clock_t start = clock();
    removeHalfAddQuaterLinked(stack);
    clock_t end = clock();
    double result = ((double)(end - start)) / CLOCKS_PER_SEC;
    time += result;
    printf("Number %d stack size %zu time %f seconds\n", i + 1, stack->size, result);
  }

  destructionStackLinked(stack);

  return time;
}

double linkedSecondTest(void)
{
  struct StackLinked* stack = stackCreatLinked();
  double time = 0.0;

  linkedAddElem(stack, 1, sizeTest);

  clock_t start = clock();
  for (int j = 0; j < 2; j++)
  {
    for (int i = 0; i < 100; i++)
    {
      if (j == 0)
      {
        linkedRemoveElem(stack, 10000);
      }
      else
        linkedAddElem(stack, stack->size + 1, (int) stack->size + 10000);
    }
  }
  clock_t end = clock();
  double result = ((double)(end - start)) / CLOCKS_PER_SEC;
  time += result;
  printf("Remove add 10000 elements 100 times %lg\n", result);

  start = clock();
  for (int i = 0; i < 9; i++)
  {
    removeHalfAddQuaterLinked(stack);
  }
  end = clock();
  result = ((double)(end - start)) / CLOCKS_PER_SEC;
  time += result;
  printf("after the analogy of the first test time %f size %zu\n", result, stack->size);
  
  start = clock();
  for (int j = 0; j < 2; j++)
  {
    for (int i = 0; i < 100; i++)
    {
      if (j == 0)
      {
        linkedRemoveElem(stack, 10000);
      }
      else
        linkedAddElem(stack, stack->size + 1, (int) stack->size + 10000);
    }
  }
  end = clock();
  result = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Remove add 10000 elements 100 times %f\n", result);
  time += result;

  destructionStackLinked(stack);

  return time;
}

double linkedTestThee(void)
{
  struct StackLinked* stack = stackCreatLinked();

  linkedAddElem(stack, 1, sizeTest);

  clock_t start = clock();
  for (int i = 0; i < sizeTest; i++)
  {
    int random = rand() % 2 + 1;
    if (random == 1)
    {
      linkedPush(stack, &random);
    }
    else  
      linkedPop(stack);
  }
  clock_t end = clock();
  double time = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Push and Pop 1000000 time in %f second\n", time);

  destructionStackLinked(stack);

  return time;
}

int linkedTestFour(void)
{
  struct StackLinked* stackLinked = stackCreatLinked();

  FILE* file = fopen("linkedData.txt", "w");
  if (file == NULL)
  {
    fprintf(file, "Error open file at %s:%d in function %s\n" , __FILE__, __LINE__, __func__);
    return 1;
  }

  for (int i = 1000; i < sizeTest; i += 1000)
  {
    clock_t start = clock();
    for (int j = 0; j < i ; j++)
    {
      linkedPush(stackLinked, &j);
    }
    clock_t end = clock();
    double result = ((double)(end - start)) / CLOCKS_PER_SEC;
    fprintf(file, "%d %f \n", i, result);

    while (stackLinked->size > 0)
    {
      linkedPop(stackLinked);
    }
  }
  destructionStackLinked(stackLinked);
  fclose(file);
  return 0;
} 