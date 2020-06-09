#include "sum.h"

int Sum(const struct SumArgs *args) {
  int sum = 0;
  // TODO: your code here 

  for(int i = args->begin;i < args->end;i++)
  {
      sum += args->array[i];
  }

  return sum;
}

void *ThreadSum(void *args) {
  struct SumArgs *sum_args = (struct SumArgs *)args;
  return (void *)(unsigned int)Sum(sum_args);
}