#include<stdio.h>
int main()
{

    long long int c;
    int i,N,start,other,ans[10000],count,k;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%lld",&c);
        count=0;
        //k=c+1;

        while(c>=1)
        {
            if(c%2==0)
            {
                ans[count]=6;
                count++;
            }
            else
            {
                ans[count]=5;
                count++;
            }
            c=c-1;
            c=c/2;
        }
        for(i=count-1;i>=0;i--)
            printf("%d",ans[i]);
        printf("\n");
    }

    return 0;
}
