#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    long long int a,b,c;
    while(T--)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        printf("%lld\n",a*a-2*b);
    }
    return 0;
}
