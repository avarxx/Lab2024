#ifndef ENUM_H
#define ENUM_H

enum STATUS 
{
  failure,
  success
};

enum ERROR
{
  errInitializing = 21,     //There is currently no data available for initializing a new node
  errArgument     = 22,     //Error with incorrect arguments to function linked
  errMemoryLinked = 23,      //Memory allocation errors for a new node
  errCreating     = 10,     //Error with incorrect arguments to creating stack
  errMemory       = 11,     //Dynamic stack memory allocation failure
  errExpansion    = 12,     //An error occurred during stack expansion
  errArguments    = 13,     //Error with incorrect arguments in push to dynamicArray
  errDrain        = 14,     //An error occurred while reducing the drain
  errFile         = 15,      //Error open file at tests
};

#endif /* ENUM__H */
