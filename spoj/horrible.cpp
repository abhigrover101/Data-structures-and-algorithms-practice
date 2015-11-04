#include<stdio.h>
#include<string.h>
using namespace std;
long long int arr[100100][2];

void update(long long int a,long long int num,long long int N,long long int k)
{
    while(a<=100100)
    {
        arr[a][0]+=num;
        arr[a][1]+=num*k;
        a+=(a&-a);
    }
}

long long int read(long long int num,int bit)
{
    long long int sum=0;
    while(num>0)
    {
        sum+=arr[num][bit];
        num-=(num & -num);
    }
    return sum;
}

int main()
{
    long long int T,N,C,i,a=0,b=0,c=0,d=0,k=0;
    long long int sum;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&N,&C);
        memset(arr,'\0',sizeof(arr));
        while(C--){
        sum=0;
        scanf("%lld",&a);
        if(a==0)
            scanf("%lld%lld%lld",&b,&c,&d);
        else
            scanf("%lld%lld",&b,&c);
        if(a==0)
        {
            update(b,d,N,(b-1));
            update(c+1,-d,N,c);
        }
        if(a==1)
        {
            sum=(read(c,0)*c-read(c,1))-(read(b-1,0)*(b-1)-read(b-1,1));
            printf("%lld\n",sum);
        }
        }
    }
    return 0;
}
