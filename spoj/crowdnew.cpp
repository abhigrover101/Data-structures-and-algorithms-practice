#include<stdio.h>
#define mod 1000000007
#include<string.h>
using namespace std;

long long int ans[5][5];
long long int temp[5][5];
//long long int x[5][5];

void exp(long long int y)
{
    int i,j,k;
    long long int g,p;
    long long int x[5][5]={{2,0,0,-1,1},{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,0,2}};
    for(i=0;i<5;i++)
        for(k=0;k<5;k++)
            if(i==k)
                ans[i][k]=1;
            else
                ans[i][k]=0;


    while(y)
    {
        memset(temp,'\0',sizeof(temp));
        if(y%2==1)
        {
            for(i=0;i<5;i++)
                for(k=0;k<5;k++)
                    for(j=0;j<5;j++)
                    {
                        g=(ans[j][k]*x[i][j]);
                        if(g>mod)
                            g=g%mod;
                        else if(g<0)
                            g=g+mod;
                        p=(temp[i][k]+g);
                        if(p>mod)
                            p=p%mod;
                        else if(p<0)
                            p=p+mod;
                        temp[i][k]=p;
                    }
            memcpy(ans,temp,sizeof(ans));
        }
        memset(temp,'\0',sizeof(temp));

        for(i=0;i<5;i++)
            for(k=0;k<5;k++)
                for(j=0;j<5;j++)
                {
                       g=(x[j][k]*x[i][j]);
                        if(g>mod)
                            g=g%mod;
                        else if(g<0)
                            g=g+mod;
                        p=(temp[i][k]+g);
                        if(p>mod)
                            p=p%mod;
                        else if(p<0)
                            p=p+mod;
                    temp[i][k]=p;
                }
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
        exp(n-4);
        a=((ans[0][0]*3)%mod+(ans[0][1]) + (2*ans[0][4])%mod)%mod;
        printf("%lld\n",a);
    }
    return 0;
}

