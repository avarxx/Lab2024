#include "TESTING.h"

void testing(const char* dir, void (*sort)(int* arr, size_t n), const char* results, size_t from, size_t to, size_t step, int numberOftest) 
{
  FILE* result = fopen(results, "w");
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
      int* array  = (int*) calloc(i + 1, sizeof(int));
      int size    = 0;
      
      fscanf(input, "%d", &size);
      for (size_t x = 0; x < i; x++) 
      {
        fscanf(input, "%d", array + x);
      }

      clock_t start = clock();
      (*sort)(array, i);
      clock_t finish = clock();
      time += (double) ((finish - start) / (double) CLOCKS_PER_SEC);

      FILE* output  = fopen(file_out, "r");
      int   answer  = 0; 
      for (size_t x = 0; x < i; x++) 
      {
        fscanf(output, "%d", &answer);
        // printf("%d %d\n", array[x], answer);
        // assert(array[x] == answer);
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
  // testQuadratic();
  // printf("Square sorting test has passed.  \n");
  // testPyramid();
  // printf("Pyramid sorting tests have passed\n");
  // testMerge();
  // printf("Merge sorting tests have passed  \n");
  // testQsort();
  // printf("The quick sort tests have passed \n");
  // testQsort5();
  // printf("The quick sort tests have passed \n");
  testSorting();
  printf("lsd msd sort tests have passed   \n");
  test9();
  printf("done\n");
  return 0; 
}

void testQuadratic(void)
{
  testing("C:\\algorithms\\My\\GenerateFile\\small_tests"   ,      babbleSort,
          "C:\\algorithms\\MY\\Answer\\BubbleSort.out"      ,50, 1000, 50, 5);
  testing("C:\\algorithms\\MY\\GenerateFile\\small_tests"   ,   selectionSort,
          "C:\\algorithms\\MY\\Answer\\selectionSort.out"   ,50, 1000, 50, 5);
  testing("C:\\algorithms\\My\\GenerateFile\\small_tests"   ,   insertionSort,
          "C:\\algorithms\\MY\\Answer\\insertionSort.out"   ,50, 1000, 50, 5);
  testing("C:\\algorithms\\My\\GenerateFile\\small_tests"   ,   	  shellSort,
          "C:\\algorithms\\MY\\Answer\\shellSort.out"       ,50, 1000, 50, 5);
}

void testPyramid(void)
{
  testing("C:\\algorithms\\MY\\GenerateFile\\small_tests"   ,       heapSort2,
          "C:\\algorithms\\MY\\Answer\\heapSort2.out"       ,50, 1000, 50, 5);
  testing("C:\\algorithms\\My\\GenerateFile\\small_tests"   ,       heapSort3,
          "C:\\algorithms\\MY\\Answer\\heapSort3.out"       ,50, 1000, 50, 5);
  testing("C:\\algorithms\\My\\GenerateFile\\small_tests"   ,   	  heapSort4,
          "C:\\algorithms\\MY\\Answer\\heapSort4.out"       ,50, 1000, 50, 5);
}

void testMerge(void)
{
  testing("C:\\algorithms\\My\\GenerateFile\\big_tests"     ,     mergeSortInteractive,
           "C:\\algorithms\\MY\\Answer\\mergeIterative.out" ,10000, 1000000, 10000, 1);
  testing("C:\\algorithms\\MY\\GenerateFile\\big_tests"     ,       mergeSortRecursive,
         "C:\\algorithms\\MY\\Answer\\mergeRecursion.out"   ,10000, 1000000, 10000, 1);
}

void testQsort(void)
{
  testing("C:\\algorithms\\My\\GenerateFile\\big_tests"     ,              lamutoQsort,
          "C:\\algorithms\\MY\\Answer\\lamutoQsort.out"     ,10000, 1000000, 10000, 1);
  testing("C:\\algorithms\\MY\\GenerateFile\\big_tests"     ,                hoarQsort,
          "C:\\algorithms\\MY\\Answer\\hoarQsort.out"       ,10000, 1000000, 10000, 1);
  testing("C:\\algorithms\\MY\\GenerateFile\\big_tests"     ,                flagQsort,
          "C:\\algorithms\\MY\\Answer\\flagQsort.out"       ,10000, 1000000, 10000, 1);
}

void testQsort5(void)
{
  testing("C:\\algorithms\\My\\GenerateFile\\big_tests"     ,              qsortMedian,
          "C:\\algorithms\\MY\\Answer\\qsortMedian.out"     ,10000, 1000000, 10000, 1);
  testing("C:\\algorithms\\MY\\GenerateFile\\big_tests"     ,                qsortRand,
          "C:\\algorithms\\MY\\Answer\\qsortRand.out"       ,10000, 1000000, 10000, 1);
  testing("C:\\algorithms\\MY\\GenerateFile\\big_tests"     ,                qsortElem,
          "C:\\algorithms\\MY\\Answer\\qsortElem.out"       ,10000, 1000000, 10000, 1);
  testing("C:\\algorithms\\MY\\GenerateFile\\big_tests"     ,             qsortMidRand,
          "C:\\algorithms\\MY\\Answer\\qsortMidRand.out"    ,10000, 1000000, 10000, 1);
}

void testSorting(void)
{
  testing("C:\\algorithms\\MY\\GenerateFile\\big_tests"     ,                  msdSort,
          "C:\\algorithms\\MY\\Answer\\msdSort.out"         ,10000, 1000000, 10000, 1);
  testing("C:\\algorithms\\MY\\GenerateFile\\big_tests"     ,                  lsdSort,
          "C:\\algorithms\\MY\\Answer\\lsdSort.out"         ,10000, 1000000, 10000, 1); 
}

void test9(void)
{
  testing("C:\\algorithms\\My\\GenerateFile\\big_tests"     ,           insertionSort,
          "C:\\algorithms\\MY\\Answer\\insertionSort.out"   , 200000, 1000, 200000, 1);
  testing("C:\\algorithms\\My\\GenerateFile\\big_tests"     ,  	             heapSort4,
          "C:\\algorithms\\MY\\Answer\\heapSort4.out"       , 200000, 1000, 200000, 1);
  testing("C:\\algorithms\\My\\GenerateFile\\big_tests"     ,     mergeSortInteractive,
           "C:\\algorithms\\MY\\Answer\\mergeIterative.out" ,10000, 1000000, 10000, 1);
  testing("C:\\algorithms\\MY\\GenerateFile\\big_tests"     ,                hoarQsort,
          "C:\\algorithms\\MY\\Answer\\hoarQsort.out"       ,10000, 1000000, 10000, 1);
  testing("C:\\algorithms\\MY\\GenerateFile\\big_tests"     ,                qsortElem,
          "C:\\algorithms\\MY\\Answer\\qsortElem.out"       ,10000, 1000000, 10000, 1);
  testing("C:\\algorithms\\MY\\GenerateFile\\big_tests"     ,                  lsdSort,
          "C:\\algorithms\\MY\\Answer\\lsdSort.out"         ,10000, 1000000, 10000, 1); 
}