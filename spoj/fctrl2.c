#include<stdio.h>
#include<string.h>
void factorial(int *f,int N)
{
    //printf("%d",N);
    int carry=0,num=0,i=0;
    if(N<=1)
        return;
    if(N>1)
        factorial(&f[0],N-1);
    for(i=0;i<500;i++)
    {
        num=f[i]*N+carry;
        f[i]=num%10;
        carry=num/10;
        //printf("%d",f[i]);
    }
    //printf("\n");
    return;
}
int main()
{
    int T,N,fac[500],i,flag=0;
    scanf("%d",&T);
    while(T--)
    {
        memset(fac,'\0',sizeof(fac));
        fac[0]=1;
        flag=0;
        scanf("%d",&N);
        factorial(&fac[0],N);
        for(i=499;i>=0;i--)
        {
            if(flag==0 && fac[i]==0)
                continue;
            else
                flag=1;
            printf("%d",fac[i]);
        }
        printf("\n");
    }
    return 0;
}
