#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

enum status
{
  OK,
  ERROR,
};


int validateArguments(int argument_count, char *arguments[], int *array_size, int *max_value) 
{
  if (argument_count != 3) 
  {
    fprintf(stderr, "Usage: %s <array_length> <maximum_value>\n", arguments[0]);
    return ERROR;
  }

  char *endptr;

  long temp_array_size = strtol(arguments[1], &endptr, 10);
  long temp_max_value  = strtol(arguments[2], &endptr, 10);

  *array_size = (int)temp_array_size;
  *max_value  = (int)temp_max_value;

  return OK;
}

int getRandom(int max_value) 
{
  return rand() % max_value + 1;
}

void printArray(int array_size, int max_value) 
{
  printf("%d\n", array_size);

  for (int i = 0; i < array_size; i++) 
  {
    printf("%d ", getRandom(max_value));
  }
  printf("\n");
}

int main(int argc, char *argv[]) 
{
  int array_size, max_value;
  srand(time(NULL));

  if (validateArguments(argc, argv, &array_size, &max_value) != 0) 
  {
    return ERROR;
  }

  printArray(array_size, max_value);
  return OK;
}
