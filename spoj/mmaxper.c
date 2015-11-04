#include<stdio.h>
#include<string.h>
int main()
{
    int i,T,length=0,temp1=0,temp2=0,temp3=0,temp4=0;
    scanf("%d",&T);
    int a[1001][2],prevs=0,prevl=0,l=0,s=0;
    for(i=0;i<1001;i++)
        memset(a,'\0',sizeof(a[i]));
    for(i=0;i<T;i++)
    {
        scanf("%d%d",&a[i][0],&a[i][1]);
    }
    prevs=a[0][0]+a[0][1];
    prevl=a[0][0]+a[0][1];
    for(i=1;i<T;i++)
    {
        temp1=prevs+abs(a[i-1][0]-a[i][0])+a[i][1]+a[i][0]-a[i-1][0];
        temp2=prevl+abs(a[i-1][1]-a[i][0])+a[i][1]+a[i][0]-a[i-1][1];

        temp3=prevs+abs(a[i-1][0]-a[i][1])+a[i][0]+a[i][1]-a[i-1][0];
        temp4=prevl+abs(a[i-1][1]-a[i][1])+a[i][0]+a[i][1]-a[i-1][1];

        if(i==T-1)
        {
            temp1=temp1-a[i][0];
            temp2=temp2-a[i][0];

            temp3=temp3-a[i][1];
            temp4=temp4-a[i][1];

        }

        if(temp1>temp2)
            prevs=temp1;
        else
            prevs=temp2;

        if(temp3>temp4)
            prevl=temp3;
        else
            prevl=temp4;
    }
    if(prevs>prevl)
        printf("%d\n",prevs);
    else
        printf("%d\n",prevl);
    return 0;
}
