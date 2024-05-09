#include "..\SAVE_TO_FILE.h"

#define numOfKeys 1000000
#define tableSize 5000
#define lengthString 20
#define CRC32_POLYNOMIAL 0xEDB88320


unsigned int hashStringLength(const char *string) 
{
  return strlen(string) % tableSize;
}

unsigned int hashSumLetters(const char *string)
{
  unsigned int sum = 0;
  for (int i = 0; string[i] != '\0'; ++i) 
  {
    sum += string[i];
  }
  return sum % tableSize;
}

unsigned int hashPolynomial(const char *string) 
{
  unsigned int hash = 0;
  while (*string) 
  {
    hash = (hash << 5) + *string++;
  }
  return (hash & 0x7FFFFFFF) % tableSize;
}

void crc32Table(unsigned int *crc32Table) 
{
  static int tableInitialized = 0;
  if (!tableInitialized) 
  {
    for (unsigned int i = 0; i < 256; i++) 
    {
      unsigned int crc = i;
      for (int j = 0; j < 8; j++) 
      {
        if (crc & 1) 
        {
          crc = (crc >> 1) ^ CRC32_POLYNOMIAL;
        } 
        else 
        {
          crc >>= 1;
        }
      }
      crc32Table[i] = crc;
    }
    tableInitialized = 1;
  }
}

unsigned int hashcrc32String(const char *string) 
{
  static unsigned int table[256];
  crc32Table(table);

  unsigned int crc = 0xFFFFFFFF;
  size_t len = strlen(string);
  for (size_t i = 0; i < len; i++) 
  {
      crc = (crc >> 8) ^ table[(crc ^ string[i]) & 0xFF];
  }
  return ~crc % tableSize;
}

void countCollisions(char** keys, int keysNum, int* collisionsLength, 
                     int* collisionsSum, int* collisionsPolynomial, int* collisionsCrc32)
{
  assert(keys);
  assert(collisionsSum);
  assert(collisionsCrc32);
  assert(collisionsLength);
  assert(collisionsPolynomial);

  for (size_t i = 0; i < keysNum; i++)
  {
    char* key = keys[i];
     unsigned int indexLenght = hashStringLength(key);
     collisionsLength[indexLenght]++;

     unsigned int indexSum = hashSumLetters(key);
     collisionsSum[indexSum]++;

     unsigned int indexPolynomial = hashPolynomial(key);
     collisionsPolynomial[indexPolynomial]++;

     unsigned int indexCrc = hashcrc32String(key);
     collisionsCrc32[indexCrc]++;
  }
}

int main(int argc, const char* argv[]) 
{
  FILE *file = fopen("../Bash/string_keys.txt", "r");
  if (file == NULL) 
  {
    perror("Error opening the file");
    exit(errno);
  }

  char **keys = (char**)calloc(numOfKeys, sizeof(char*));
  if (keys == NULL) 
  {
    perror("Error creating array keys");
    exit(errno);
  }

  for (int i = 0; i < numOfKeys; i++) 
  {
    keys[i] = (char*)calloc(lengthString, sizeof(char));
    if (keys[i] == NULL) 
    {
      perror("Error creating string");
      exit(errno);
    }
  }

  for (size_t i = 0; i < numOfKeys; i++)
  {
    fscanf(file, "%s", keys[i]);
  }
  fclose(file);

  int* collisionsLength     = (int*)calloc(tableSize, sizeof(int));
  int* collisionsSum        = (int*)calloc(tableSize, sizeof(int));
  int* collisionsPolynomial = (int*)calloc(tableSize, sizeof(int));
  int* collisionsCrc32      = (int*)calloc(tableSize, sizeof(int));

  countCollisions(keys, numOfKeys, collisionsLength, collisionsSum,
                  collisionsPolynomial, collisionsCrc32);

  writeAnswer("AnswerString/collisionsSum.txt"        , collisionsSum,       tableSize);
  writeAnswer("AnswerString/collisionsLength.txt"     , collisionsLength,    tableSize);
  writeAnswer("AnswerString/collisionsPolynomial.txt" , collisionsPolynomial,tableSize);
  writeAnswer("AnswerString/collisionsCrc32.txt"      , collisionsCrc32,     tableSize);

  for (int i = 0; i < numOfKeys; i++) 
  {
    free(keys[i]);
  }
  free(keys);
  return 0;
}
