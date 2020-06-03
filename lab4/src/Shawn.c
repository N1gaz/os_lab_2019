#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    pid_t pid;

    pid = fork();
    if(pid > 0)
    {
        printf("My name is Shawn. My pid is %d\n",pid);
        sleep(100);
    }
    else
        return 1;
    return 0;
}