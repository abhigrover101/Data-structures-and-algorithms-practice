#include<stdio.h>
int main()
{
    int T,min,hours,i;
    long long int N;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%lld",&N);
        min=N%60;
        hours=(N%1440)/60;
        printf("Scenario #%d: %02d:%02d\n",i,(hours+9)%24,min);
    }
    return 0;
}
