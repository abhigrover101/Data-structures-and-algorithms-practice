#include<cstdio>
#include<limits.h>
#include<algorithm>
using namespace std;

int main()
{
    long long int min=INT_MAX,a[5010],m;
    int T,N,i;
    scanf("%d",&T);
    while(T--)
    {
        min=INT_MAX;
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            scanf("%lld",&a[i]);
        }
        sort(&a[0],&a[N]);
        for(i=1;i<N;i++)
        {
            m=a[i]-a[i-1];
            if(m<min)
                min=m;
            //printf("%lld ",a[i]);
        }
        printf("%lld\n",min);
    }
    return 0;
}
