#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int const count = 1000000;

unsigned int generateUnsignedInt(void) 
{
  return rand() % (RAND_MAX + 1);
}

float generateFloat(void) 
{
  return -10 + (float)rand() / RAND_MAX * 20;
}

void generateString(char *str, int length) 
{
  static const char charset[] = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0; i < length; ++i) 
  {
    int index = rand() % (sizeof(charset) - 1);
    str[i] = charset[index];
  }
  str[length] = '\0';
}

int main(int argc, const char* argv[]) 
{
  srand(42);

  FILE *unsignedIntFile = fopen("unsigned_int_keys.txt", "w");
  FILE *floatFile       = fopen("float_keys.txt"       , "w");
  FILE *stringFile      = fopen("string_keys.txt"      , "w");

  if (unsignedIntFile == NULL || floatFile == NULL || stringFile == NULL)
    return 1;

  for (int i = 0; i < count; ++i) 
  {
    fprintf(unsignedIntFile, "%u "  , generateUnsignedInt());
    fprintf(floatFile,       "%.5f ", generateFloat());

    char randomString[21];
    generateString(randomString, 5 + rand() % 16);
    fprintf(stringFile, "%s ", randomString);
  }

  fclose(unsignedIntFile);
  fclose(floatFile);
  fclose(stringFile);
  
  return 0;
}
