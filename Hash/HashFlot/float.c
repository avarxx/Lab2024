#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <errno.h>

#define numOfKeys 1000000
#define mask  0xFFFFFFFF
#define mask2 0xFF

enum ERROR
{
  errScanf  = 10
};

unsigned int hashFloatToInt(float key) 
{
  unsigned int value;
  memcpy(&value, &key, sizeof(float));
  return value;
}

unsigned int hashBitFloat(float key) 
{
  unsigned int value;
  memcpy(&value, &key, sizeof(float));
  return value & mask;
}

unsigned int hashMantissa(float key) 
{
  unsigned int floatBits;
  memcpy(&floatBits, &key, sizeof(float));
  unsigned int mantissa = floatBits & ((1 << 23) - 1);
  return mantissa;
}

unsigned int hashExponent(float key) 
{
  unsigned int floatBits;
  memcpy(&floatBits, &key, sizeof(float));
  unsigned int exponent = (floatBits >> 23) & 0xFF;
  return exponent;
}

unsigned int hashMantissaExponent(float key) 
{
  unsigned int floatBits;
  memcpy(&floatBits, &key, sizeof(float));
  unsigned int mantissa = floatBits & ((1 << 23) - 1);
  unsigned int exponent = (floatBits >> 23) & mask2;
  return mantissa * exponent;
}

void countCollisions(unsigned int *keys, int keysNum,
                     int* collisionsToInt,  int* collisionsBit, int* collisionsMantissa,
                     int* collisionsExponent, int* collisionsExponentMantissa) 
{
  assert(keys);
  assert(collisionsBit);
  assert(collisionsToInt);
  assert(collisionsMantissa);
  assert(collisionsExponent);
  assert(collisionsExponentMantissa);

  for (int i = 0; i < keysNum; i++) 
  {
    unsigned int key = keys[i];

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
  FILE *file = fopen("../Bash/float_keys.txt", "r");
  float* keys = (float*)calloc(numOfKeys, sizeof(float));
  assert(file);
  assert(keys);
  
  for (size_t i = 0; i < numOfKeys; i++)
  {
    if (fscanf(file, "%u", &keys[i]) != 1)
    {
      perror("Ошибка при открытии файла");
      exit(errScanf);
    }
  }
  fclose(file);

  int* collisionsBit            = (int*)calloc(tableSize, sizeof(int));
  int* collisionsRemainder      = (int*)calloc(tableSize, sizeof(int));
  int* collisionsMultiplication = (int*)calloc(tableSize, sizeof(int));
  int* collisionsRemainder      = (int*)calloc(tableSize, sizeof(int));
  int* collisionsMultiplication = (int*)calloc(tableSize, sizeof(int));

  countCollisions(keys, numOfKeys, 
                  collisionsRemainder, collisionsBit, collisionsMultiplication);

  writeAnswer("AnswerInt/collisions_bit.txt"            , collisionsBit, tableSize);
  writeAnswer("AnswerInt/collisions_remainder.txt"      , collisionsRemainder, tableSize);
  writeAnswer("AnswerInt/collisions_multiplication.txt" , collisionsMultiplication, tableSize);
  writeAnswer("AnswerInt/collisions_remainder.txt"      , collisionsRemainder, tableSize);
  writeAnswer("AnswerInt/collisions_multiplication.txt" , collisionsMultiplication, tableSize);
  
  free(keys);
  return 0;
}

