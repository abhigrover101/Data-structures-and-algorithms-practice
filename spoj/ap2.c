#include<stdio.h>
int main()
{
    long long int a,b,c,n,d,first,i;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        n=c*2/(a+b);
        if(n-5>0)
            d=(b-a)/(n-5);
        else
            d=b/2;
        first=a-2*d;
        printf("%lld\n",n);
        for(i=0;i<n;i++)
        {
            printf("%lld ",first);
            first+=d;
        }
        printf("\n");
    }
    return 0;
}
