#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    long long int N,k,i,count;
    while(T--)
    {
        count=0;
        scanf("%lld",&N);
        while(N>1)
        {
            count=count+N/5;
            N=N/5;
        }
        printf("%lld\n",count);
    }
    return 0;
}
