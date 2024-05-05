#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "..\SAVE_TO_FILE.h"

#define PRIME 2654435761U
#define numOfKeys 10000
#define mask 0xFFFFFFFF
#define mask2 0xFF
#define tableSize 10000

unsigned int hashFloatToInt(float key) 
{
  unsigned int hashValue = *((unsigned int*)(&key));
  return hashValue % tableSize;
}

unsigned int hashBitFloat(float key) 
{
  unsigned int value;
  memcpy(&value, &key, sizeof(float));
  return (value * PRIME) % tableSize;
}

unsigned int hashMantissa(float key) 
{
  unsigned int floatBits;
  memcpy(&floatBits, &key, sizeof(float));
  unsigned int mantissa = floatBits & ((1 << 23) - 1);
  return mantissa % tableSize;
}

unsigned int hashExponent(float key) 
{
  unsigned int floatBits;
  memcpy(&floatBits, &key, sizeof(float));
  unsigned int exponent = (floatBits >> 23) & 0xFF;
  return exponent % tableSize;
}

unsigned int hashMantissaExponent(float key) 
{
  unsigned int floatBits;
  memcpy(&floatBits, &key, sizeof(float));
  unsigned int mantissa = floatBits & ((1 << 23) - 1);
  unsigned int exponent = (floatBits >> 23) & 0xFF;
  return (mantissa * exponent) % tableSize;
}


void countCollisions(float *keys, int keysNum,
                     int* collisionsToInt,  int* collisionsBit, int* collisionsMantissa,
                     int* collisionsExponent, int* collisionsExponentMantissa) 
{
  assert(keys);
  assert(collisionsBit);
  assert(collisionsToInt);
  assert(collisionsMantissa);
  assert(collisionsExponent);
  assert(collisionsExponentMantissa);

  for (size_t i = 0; i < keysNum; i++) 
  {
    float key = keys[i];

    unsigned int indexToInt = hashFloatToInt(key); 
    collisionsToInt[indexToInt]++;

    unsigned int indexBit = hashBitFloat(key); 
    collisionsBit[indexBit]++;

    unsigned int indexMantissa = hashMantissa(key); 
    collisionsMantissa[indexMantissa]++;
    
    unsigned int indexExponent = hashExponent(key); 
    collisionsExponent[indexExponent]++;

    unsigned int indexExponentMantissa = hashMantissaExponent(key); 
    collisionsExponentMantissa[indexExponentMantissa]++;
  }
}

int main(int argc, const char* argv[])
{
  FILE *file = fopen("../Bash/float_keys.txt", "r");
  if (file == NULL) 
  {
    perror("Error opening the file");
    exit(errno);
  }
  float* keys = (float*)calloc(numOfKeys, sizeof(float));
  assert(keys);
  
  for (size_t i = 0; i < numOfKeys; i++)
  {
    if (fscanf(file, "%f", &keys[i]) != 1)
    {
      fclose(file);
      perror("Error reading the file");
      exit(errno);
    }
  }
  fclose(file);

  int* collisionsToInt            = (int*)calloc(tableSize, sizeof(int));
  int* collisionsBit              = (int*)calloc(tableSize, sizeof(int));
  int* collisionsMantissa         = (int*)calloc(tableSize, sizeof(int));
  int* collisionsExponent         = (int*)calloc(tableSize, sizeof(int));
  int* collisionsExponentMantissa = (int*)calloc(tableSize, sizeof(int));

  countCollisions(keys, numOfKeys, 
                  collisionsToInt, collisionsBit, collisionsMantissa,
                  collisionsExponent, collisionsExponentMantissa);

  writeAnswer("AnswerFloat/collisionsToInt.txt"            , collisionsToInt,            tableSize);
  writeAnswer("AnswerFloat/collisionsBit.txt"              , collisionsBit,              tableSize);
  writeAnswer("AnswerFloat/collisionsMantissa.txt"         , collisionsMantissa,         tableSize);
  writeAnswer("AnswerFloat/collisionsExponent.txt"         , collisionsExponent,         tableSize);
  writeAnswer("AnswerFloat/collisionsExponentMantissa.txt" , collisionsExponentMantissa, tableSize);
  
  free(keys);
  return 0;
}
