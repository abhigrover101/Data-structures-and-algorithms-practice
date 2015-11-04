#include<stdio.h>
#include<vector>
#define mod 1000000007
#include<string.h>
using namespace std;

long long int ans[3][3];
long long int temp[3][3];
//long long int x[5][5];
long long int exp1(long long int x,long long int y)
{
    long long int ans=1;
    while(y)
    {
        if(y%2==1)
            ans=(ans*x)%mod;
        x=(x*x)%mod;
        y=y/2;
    }
    return ans;
}

void exp(long long int y)
{
    int i,j,k;
    long long int x[3][3]={{1,1,1},{1,0,0},{0,1,0}};
    for(i=0;i<3;i++)
        for(k=0;k<3;k++)
            if(i==k)
                ans[i][k]=1;
            else
                ans[i][k]=0;


    while(y)
    {
        memset(temp,'\0',sizeof(temp));
        if(y%2==1)
        {
            for(i=0;i<3;i++)
                for(k=0;k<3;k++)
                    for(j=0;j<3;j++)
                        temp[i][k]=((temp[i][k]+(ans[j][k]*x[i][j])%mod)%mod);
            memcpy(ans,temp,sizeof(ans));
        }
        memset(temp,'\0',sizeof(temp));

        for(i=0;i<3;i++)
            for(k=0;k<3;k++)
                for(j=0;j<3;j++)
                    temp[i][k]=((temp[i][k]+(x[i][j]*x[j][k])%mod)%mod);
        memcpy(x,temp,sizeof(x));
        //printf("ans %lld\n",x[0][0]);
        y=y/2;
    }
}
int main()
{
    long long int n,temp,a;
    int T;
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
        exp(n-3);
        a=(exp1(2,n)-((7*ans[0][0])%mod+(4*ans[0][1])%mod + (2*ans[0][2])%mod)%mod + mod)%mod;
        printf("%lld\n",a);
    }
    return 0;
}

