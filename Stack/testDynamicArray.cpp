#include "testDynamicArray.h"

void dynamicRemoveElem(struct Stack* stack, int number)
{
  if (!checkStack(stack) && stack->size < 0)
  {
    exit(errArguments);
  }
  while (number > 0 && stack->size > 0)
  {
    dynamicPop(stack);
    number--;
  }
}

void dynamicAddElem(struct Stack * stack, int start, int end)
{
  if (!checkStack(stack) && start > end)
  {
    exit(errArguments);
  }
  for (int i = start; i <= end; i++)
  {
    dynamicPush(stack, &i);
  }
    
}

void removeHalfAddQuater(struct Stack* stack)
{
  if (!checkStack(stack) && stack->size) 
  {
    exit(errArguments);
  }

  size_t prev_size = stack -> size;

  dynamicRemoveElem(stack, prev_size / 2);

  int start = (int) stack -> size + 1;
  int end = (int) stack -> size + prev_size / 4;
  dynamicAddElem(stack, start, end);
}

double dynamicFirstTest(void)
{
  struct Stack* stack = stackCreating(sizeTest, sizeof(int));
  double time = 0.0;

  dynamicAddElem(stack, 1, sizeTest);

  for (int i = 0; i < 9; i++)
  {
    clock_t start = clock();
    removeHalfAddQuater(stack);
    clock_t end = clock();
    double result = ((double)(end - start)) / CLOCKS_PER_SEC;
    time += result;
    printf("Number run test %d stack size: %zu time %f seconds\n", i + 1, stack->size, result);
  }

    destructionStack(stack);

    return time;
}

double dynamicSecondTest(void)
{
  struct Stack* stack = stackCreating(sizeTest, sizeof(int));
  double time = 0.0;

  dynamicAddElem(stack, 1, sizeTest);

  clock_t start = clock();
  for (int j = 0; j < 2; j++)
  {
    for (int i = 0; i < 100; i++)
    {
      if (j == 0)
      {
        dynamicRemoveElem(stack, 10000);
      }
      else
        dynamicAddElem(stack, stack->size + 1, (int) stack->size + 10000);
    }
  }
  clock_t end = clock();
  double result = ((double)(end - start)) / CLOCKS_PER_SEC;
  time += result;
  printf("Remove add 10000 elements 100 times in %f second\n", result);

  start = clock();
  for (int i = 0; i < 9; i++)
  {
    removeHalfAddQuater(stack);
  }
  end = clock();
  result = ((double)(end - start)) / CLOCKS_PER_SEC;
  time += result;
  printf("after the analogy of the first test time %f size %zu \n", result, stack->size);
  
  start = clock();
  for (int j = 0; j < 2; j++)
  {
    for (int i = 0; i < 100; i++)
    {
      if (j == 0)
      {
        dynamicRemoveElem(stack, 10000);
      }
      else
        dynamicAddElem(stack, stack->size + 1, (int) stack->size + 10000);
    }
  }
  end = clock();
  result = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Remove add 10000 elements 100 times %f\n", result);
  time += result;

  destructionStack(stack);

  return time;
}

double dynamicTestThee(void)
{
  struct Stack* stack = stackCreating(sizeTest, sizeof(int));
  srand(time(NULL));
  dynamicAddElem(stack, 1, sizeTest);

  clock_t start = clock();
  for (int i = 0; i < sizeTest; i++)
  {
    int random = rand() % 2 + 1;
    if (random == 1)
    {
      dynamicPush(stack, &random);
    }
    else if(random == 2) 
      dynamicPop(stack);
  }
  clock_t end = clock();
  double time = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Push and Pop 1000000 time in %f second\n\n", time);

  destructionStack(stack);

  return time;
}

int dynamicTestFour(void)
{
  struct Stack* stack = stackCreating(sizeTest, sizeof(int));

  FILE* file = fopen("dynamicData.txt", "w");
  if (file == NULL)
  {
    exit(errFile);
  }

  for (int i = 1000; i < sizeTest; i += 1000)
  {
    clock_t start = clock();
    for (int j = 0; j < i ; j++)
    {
      dynamicPush(stack, &j);
    }
    clock_t end = clock();
    double result = ((double)(end - start)) / CLOCKS_PER_SEC;
    fprintf(file, "%d %f\n", i, result);

    while (stack->size > 0)
    {
      dynamicPop(stack);
    }
  }
  destructionStack(stack);
  fclose(file);
  return 0;
} 