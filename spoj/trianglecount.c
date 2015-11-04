#include<stdio.h>
int main()
{
    int T;
    int n;
    long long int k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        k=(n)*(n + 2)*(2*n + 1)/8;
        printf("%lld\n",k);
    }
    return 0;
}
