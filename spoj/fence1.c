#include<stdio.h>
#include<math.h>
int main()
{
    long long int T=1;
    double ans;
    while(1)
    {
        ans=0;
        scanf("%lld",&T);
        if(T==0)
            break;
        ans=(double)(1/(2*acos(-1)))*T*T;
        printf("%.2lf\n",ans);
    }
    return 0;
}
