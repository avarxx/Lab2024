#ifndef SWAP_H_INCLUDED
#define SWAP_H_INCLUDED

void swap(int* first, int* second)
{
  int tmp = *first;
  *first  = *second;
  *second = tmp;
}

#endif