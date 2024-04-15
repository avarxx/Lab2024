#include <stdio.h>

#include "C:\algorithms\Lab2024\Stack\Dynamic\testDynamicArray.h"
#include "C:\algorithms\Lab2024\Stack\linked\testLinked.h"

int main(int argc, const char* argv[])
{
  printf("\nFirst test dynamic:\n");
  double first = dynamicFirstTest();
  printf("\nSecond test dynamic:\n");
  double second = dynamicSecondTest();
  printf("\nthird test dynamic:\n");
  double third = dynamicTestThee();
  printf("\nTime first test:  %f\n", first);
  printf("\nTime second test: %f\n", second);
  printf("\nTime third test:  %f\n", third);
  dynamicTestFour();


  printf("\nFirst test linked:\n");
  double firstL = linkedFirstTest();
  printf("\nSecond test linked:\n");
  double secondL = linkedSecondTest();
  printf("\nthird test linked:\n");
  double thirdL = linkedTestThee();
  printf("\nTime first test:  %f\n", firstL);
  printf("\nTime second test: %f\n", secondL);
  printf("\nTime third test:  %f\n", thirdL);
  linkedTestFour();

  return 0;
}


