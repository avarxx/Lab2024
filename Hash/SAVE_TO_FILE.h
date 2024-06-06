#ifndef HSAVE_TO_FILE_H_INCLUDED
#define HSAVE_TO_FILE_H_INCLUDED

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void writeAnswer(const char* fileName, int* collisions, int size)
{
  FILE* file = fopen(fileName, "w+");
  assert(file != NULL); 
  assert(collisions);

  for (size_t i = 0; i < size; i++)
  {
    fprintf(file, "%lu %d\n",i, collisions[i]);
  }
  
  fclose(file);
  free(collisions);
}

#endif // HSAVE_TO_FILE_H//
