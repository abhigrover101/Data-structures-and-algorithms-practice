#include<stdio.h>
#include<vector>
#define mod 1000000007
using namespace std;

long long int ans;
long long int exp(long long int x,long long int y)
{
    ans=1;
    while(y)
    {
        if(y%2==1)
            ans=(ans*x)%mod;
        x=(x*x)%mod;
        y=y/2;
    }
    return ans;
}
int main()
{
    long long int n,temp,i;
    int T;
    vector <long long int> a;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        if(n==1)
            {printf("0\n");continue;}
        if(n==2)
            {printf("0\n");continue;}
        if(n==3)
            {printf("1\n");continue;}
        if(n==4)
            {printf("3\n");continue;}
        a.push_back(0);
        a.push_back(0);
        a.push_back(1);
        a.push_back(3);
        for(i=5;i<=n;i++)
        {
        temp=(2*a[3]%mod+exp(2,i-4)-a[0])%mod;
        a.erase(a.begin());
        a.push_back(temp);
        }
        printf("%lld\n",a[3]);
        a.clear();
    }
}
