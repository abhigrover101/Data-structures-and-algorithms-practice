#include<cstdio>
#include<unistd.h>
#include<cstring>
#include<stdlib.h>
int main()
{
    int p[2];
    int a;
    p[0]=2;
    p[1]=10;
    a=2;
    printf("%d %d\n",++a * a++,++a);
    return 0;
}
