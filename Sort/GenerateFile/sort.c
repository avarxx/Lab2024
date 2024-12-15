#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int compare(const void *a, const void *b) 
{
  return (*(int *)a - *(int *)b);
}

int main() 
{
  int size = 0;
  FILE *input_file = stdin;
  assert(input_file);
  fscanf(input_file, "%d", &size);

  int *array = (int *)malloc(size * sizeof(int));
  if (array == NULL) 
  {
      fprintf(stderr, "Error: Memory allocation failed.\n");
      exit(EXIT_FAILURE);
  }

  for (int i = 0; i < size; i++) 
  {
    fscanf(input_file, "%d", &array[i]);
  }
  fclose(input_file);

  qsort(array, size, sizeof(int), compare);

  for (int i = 0; i < size; i++) 
  {
    printf("%d ", array[i]);
  }
  printf("\n");

  free(array);
  return 0;
}
