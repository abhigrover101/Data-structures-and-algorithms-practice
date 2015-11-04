#include<stdio.h>
int main()
{
    int N=0,n=0,height=0,diff=0,i=0;
    scanf("%d",&N);
    while(N--)
    {
        height=0;
        diff=0;
        scanf("%d",&n);
        height=(n+1)/2;
        diff=n-1;
        for(i=0;i<n;i++)
            {
                if(i<n-1)
                    printf("%d ",height);
                if(i==n-1)
                    printf("%d\n",height);
                height=height+diff;
                diff=-1*diff-1;
            }
    }
    return 0;
}
