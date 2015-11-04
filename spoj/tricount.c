#include<stdio.h>
int main()
{
    int T;
    long long int n;
    long long int k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        k=((n)*(n + 2)*(2*n + 1));
        printf("%lld\n",k/8);
    }
    return 0;
}
