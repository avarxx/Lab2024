#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define tableSize 1000000
#define remainder 1000
#define numOfKeys 1000000

enum ERROR
{
  errScanf  = 10
};

unsigned int hashRemainder(unsigned int key)
{
  return key % remainder;
}

unsigned int hashBit(unsigned int key)
{
  unsigned int hashValue = 0;
  unsigned int mask = tableSize - 1;
  while (key > 0) 
  {
    hashValue ^= key & mask; 
    key >>= 8; 
  }

  return hashValue % tableSize;
}

unsigned int hashMultiplication(unsigned int key) 
{
  double A = 0.6180339887;
  double scaled = key * A;
  double fractional = scaled - (unsigned int)scaled;
  return (unsigned int)(tableSize * fractional);
}

void countCollisions(unsigned int *keys, int keysNum,
                     int *collisionsRemainder, int *collisionsBit, int *collisionsMultiplication) 
{
  assert(keys);
  assert(collisionsBit);
  assert(collisionsRemainder);
  assert(collisionsMultiplication);

  for (int i = 0; i < keysNum; i++) 
  {
    unsigned int key = keys[i];

    unsigned int indexRemainder = hashRemainder(key);
    collisionsRemainder[indexRemainder]++;

    unsigned int indexBit = hashBit(key);
    collisionsBit[indexBit]++;

    unsigned int indexMultiplication = hashMultiplication(key);
    collisionsMultiplication[indexMultiplication]++;
  }
}

void writeAnswer(const char* fileName, int* collisions, int size)
{
  FILE* file = fopen(fileName, "w");
  assert(file);  
  assert(collisions);

  for (size_t i = 0; i < size; i++)
  {
    fprintf(file, "%d %d\n",i, collisions[i]);
  }
  
  fclose(file);
  free(collisions);
}

int main(int argc, const char* argv[])
{
  FILE *file = fopen("../Bash/unsigned_int_keys.txt", "r");
  unsigned int* keys = (unsigned int*)calloc(numOfKeys, sizeof(unsigned int));
  assert(file);
  assert(keys);
  
  for (size_t i = 0; i < numOfKeys; i++)
  {
    if (fscanf(file, "%u", &keys[i]) != 1)
    {
      fclose(file);
      exit(errScanf);
    }
  }
  fclose(file);

  int* collisionsBit            = (int*)calloc(tableSize, sizeof(int));
  int* collisionsRemainder      = (int*)calloc(tableSize, sizeof(int));
  int* collisionsMultiplication = (int*)calloc(tableSize, sizeof(int));

  countCollisions(keys, numOfKeys, 
                  collisionsRemainder, collisionsBit, collisionsMultiplication);

  writeAnswer("AnswerInt/collisions_bit.txt"            , collisionsBit, tableSize);
  writeAnswer("AnswerInt/collisions_remainder.txt"      , collisionsRemainder, tableSize);
  writeAnswer("AnswerInt/collisions_multiplication.txt" , collisionsMultiplication, tableSize);
  
  free(keys);
  return 0;
}
