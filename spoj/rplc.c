#include<stdio.h>
int main()
{
    long long int a;
    int N,c=0,i=0;
    long long int sum=0,min;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        sum=0;
        min=0;
        scanf("%d",&c);
        while(c--)
        {
            scanf("%lld",&a);
            sum=sum+a;
            if(sum<0 && min>sum)
                min=sum;
        }
        if(min<0)
            printf("Scenario #%d: %lld\n",i+1,min*-1+1);
        else
            printf("Scenario #%d: 1\n",i+1);
    }
    return 0;
}
