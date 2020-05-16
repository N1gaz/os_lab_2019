#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
void GenerateArray(int *array, unsigned int array_size, unsigned int seed) {
  srand(seed);

    int i = 0;

    while(i < array_size)
    {
        array[i] = rand();

        i++;
    }
}
