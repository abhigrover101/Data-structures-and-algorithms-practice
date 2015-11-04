#include<stdio.h>
#include<string.h>
int main()
{
    long long int arr[100100];
    //memset(sum,'\0',sizeof(sum));
    int T,N,C,i,a=0,b=0,c=0,d=0;
    long long int sum;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&C);
        memset(arr,'\0',sizeof(long long int)*(N+1));
        while(C--){
        sum=0;
        scanf("%d",&a);
        if(a==0)
            scanf("%d%d%d",&b,&c,&d);
        else
            scanf("%d%d",&b,&c);
        if(a==0)
        {
            for(i=b;i<=c;i++)
                arr[i]=arr[i]+d;
        }
        else if(a==1)
        {
            for(i=b;i<=c;i++)
                sum=sum+arr[i];
            printf("%lld\n",sum);
        }
        }
    }
    return 0;
}

