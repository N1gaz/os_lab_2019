#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    printf("I hope, this nightmare is gonna be over now\n");
    execv("sequential_min_max.exe",argv);

    return 0;
}