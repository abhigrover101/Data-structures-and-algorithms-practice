#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int k = 5;

    pid_t pid = fork();

    if(pid)
    {
        printf("Parent k : %d\n",k);
    }
    else
    {
        printf("Child k : %d\n",k);
    }
    return 0;
}
