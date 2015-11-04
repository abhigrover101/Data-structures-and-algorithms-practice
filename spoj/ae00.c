#include<stdio.h>
int main()
{
    int i=0,N=0,count=0,j=0,k=0;
    scanf("%d",&N);

    for(i=1;i<=N;i++)
    {
        if(i*(i)<=N)
            count=count+(int)(N/i)-(i-1);
    }
    printf("%d\n",count);
    return 0;
}
