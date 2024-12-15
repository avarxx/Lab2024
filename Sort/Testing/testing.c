#include "testing.h"

void testing(const char* dir, void (*sort)(int* arr, size_t n), const char* results, size_t from, size_t to, size_t step, int numberOftest) 
{
  FILE* result = fopen(results, "w");
  assert(result);
  for (size_t i = from; i <= to; i += step) 
  {
    double time = 0;
    for (char j = 1; j <= numberOftest; j++) 
    {
      char* file_in  =  (char*)calloc(strlen(dir) + lenStr, sizeof(char));
      char* file_out =  (char*)calloc(strlen(dir) + lenStr, sizeof(char));
      char* num      =  (char*)calloc(8, sizeof(char));

      assert(file_in  != NULL);
      assert(file_out != NULL);
      assert(num      != NULL);

      sprintf(num, "%d", i);
      sprintf(file_in,  "%s\\%s_%d.%s", dir, num, j, "in" );
      sprintf(file_out, "%s\\%s_%d.%s", dir, num, j, "out");
      printf("%s\n %s\n", file_in, file_out);
      FILE* input = fopen(file_in, "r");
      assert(input);
      int* array  = (int*) calloc(i + 1, sizeof(int));
      assert(array);
      int size    = 0;
      
      if(fscanf(input, "%d", &size) != 1)
      {
        exit(errno);
      }
      for (size_t x = 0; x < i; x++) 
      {
        if(fscanf(input, "%d", array + x) != 1)
          exit(errno);
      }

      clock_t start = clock();
      (*sort)(array, i);
      clock_t finish = clock();
      time += (double) ((finish - start) / (double) CLOCKS_PER_SEC);

      FILE* output  = fopen(file_out, "r");
      assert(output);
      int   answer  = 0; 
      for (size_t x = 0; x < i; x++) 
      {
        if(fscanf(output, "%d", &answer) != 1)
          exit(errno);
        assert(array[x] == answer);
      }

      fclose (input);
      fclose (output);
      
      free   (file_in);
      free   (file_out);
      free   (array);
    }
    fprintf (result, "%d %2.5f\n", i, (time));
  }
  fclose(result);
}

int main(int argc, const char* argv[])
{
  testQuadratic();
  printf("Square sorting test has passed.  \n");
  testPyramid();
  printf("Pyramid sorting test has passed. \n");
  testMerge();
  printf("Merge sorting tests have passed  \n");
  testQsort();
  printf("The quick sort tests have passed \n");
  testQsort5();
  printf("The quick sort tests have passed \n");
  testSorting();
  printf("lsd msd sort tests have passed   \n");
  test9();
  printf("done\n");
  return 0; 
}

void testQuadratic(void)
{
  testing("..\\GenerateFile\\small_tests"   ,      bubbleSort,
          "..\\Answer\\BubbleSort.out"      ,50, 1000, 50, 5);
  testing("..\\GenerateFile\\small_tests"   ,   selectionSort,
          "..\\Answer\\selectionSort.out"   ,50, 1000, 50, 5);
  testing("..\\GenerateFile\\small_tests"   ,   insertionSort,
          "..\\Answer\\insertionSort.out"   ,50, 1000, 50, 5);
  testing("..\\GenerateFile\\small_tests"   ,       shellSort,
          "..\\Answer\\shellSort.out"       ,50, 1000, 50, 5);
}

void testPyramid(void)
{
  testing("..\\GenerateFile\\small_tests"   ,       heapSort1,
          "..\\Answer\\heapSort2.out"       ,50, 1000, 50, 5);
  testing("..\\GenerateFile\\small_tests"   ,       heapSort2,
          "..\\Answer\\heapSort3.out"       ,50, 1000, 50, 5);
  testing("..\\GenerateFile\\small_tests"   ,       heapSort3,
          "..\\Answer\\heapSort4.out"       ,50, 1000, 50, 5);
  testing("..\\GenerateFile\\small_tests"   ,       heapSort4,
          "..\\Answer\\heapSort4.out"       ,50, 1000, 50, 5);
}


void testMerge(void)
{
  testing("..\\GenerateFile\\big_tests"     ,       mergeSortIterative,
           "..\\Answer\\mergeIterative.out" ,10000, 1000000, 10000, 1);
  testing("..\\GenerateFile\\big_tests"     ,       mergeSortRecursive,
         "..\\Answer\\mergeRecursion.out"   ,10000, 1000000, 10000, 1);
}

void testQsort(void)
{
  testing("..\\GenerateFile\\big_tests"     ,              lomutoQsort,
          "..\\Answer\\lamutoQsort.out"     ,10000, 1000000, 10000, 1);
  testing("..\\GenerateFile\\big_tests"     ,                hoarQsort,
          "..\\Answer\\hoarQsort.out"       ,10000, 1000000, 10000, 1);
  testing("..\\GenerateFile\\big_tests"     ,                flagQsort,
          "..\\Answer\\flagQsort.out"       ,10000, 1000000, 10000, 1);
}

void testQsort5(void)
{
  testing("..\\GenerateFile\\big_tests"     ,              qsortMedian,
          "..\\Answer\\qsortMedian.out"     ,10000, 1000000, 10000, 1);
  testing("..\\GenerateFile\\big_tests"     ,                qsortRand,
          "..\\Answer\\qsortRand.out"       ,10000, 1000000, 10000, 1);
  testing("..\\GenerateFile\\big_tests"     ,                qsortElem,
          "..\\Answer\\qsortElem.out"       ,10000, 1000000, 10000, 1);
  testing("..\\GenerateFile\\big_tests"     ,             qsortMidRand,
          "..\\Answer\\qsortMidRand.out"    ,10000, 1000000, 10000, 1);
}

void testSorting(void)
{
  testing("..\\GenerateFile\\big_tests"     ,                  msdSort,
          "..\\Answer\\msdSort.out"         ,10000, 1000000, 10000, 1);
  testing("..\\GenerateFile\\big_tests"     ,                  lsdSort,
          "..\\Answer\\lsdSort.out"         ,10000, 1000000, 10000, 1); 


}

void test9(void)
{
  testing("..\\GenerateFile\\big_tests"     ,              insertionSort,
          "..\\Answer\\insertionSort.out"   ,100000, 1000000, 100000, 1);
  testing("..\\GenerateFile\\big_tests"     ,  	               heapSort4,
          "..\\Answer\\heapSort4.out"       ,100000, 1000000, 100000, 1);
  testing("..\\GenerateFile\\big_tests"     ,       mergeSortIterative,
           "..\\Answer\\mergeIterative.out" ,10000, 1000000, 10000, 1);
  testing("..\\GenerateFile\\big_tests"     ,                hoarQsort,
          "..\\Answer\\hoarQsort.out"       ,10000, 1000000, 10000, 1);
  testing("..\\GenerateFile\\big_tests"     ,                qsortElem,
          "..\\Answer\\qsortElem.out"       ,10000, 1000000, 10000, 1);
  testing("..\\GenerateFile\\big_tests"     ,                  lsdSort,
          "..\\Answer\\msdSort.out"         ,10000, 1000000, 10000, 1); 
}