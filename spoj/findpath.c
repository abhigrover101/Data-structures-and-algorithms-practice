#include<stdio.h>
//#include<math.h>
#include<string.h>
#include<stdlib.h>
int a[25],path;
long long int b[100][100];
int sum,count,path;

int compare (const void * c, const void * d)
{
  return ( *(int*)c - *(int*)d );
}

int findpath(long long int num,int m)
{
    int i,k=0;
    if(num==1)
    {
        sum=1;
        b[path][count]=sum;
        count++;
        //printf("%d ",sum);
        return 1;
    }
    for(i=m-1;i>=0;i--)
        {
            if(num%a[i]==0 && a[i]!=0 && a[i]!=1)
                k=findpath(num/a[i],i+1);
            if(k==1)
                {
                    sum=sum*a[i];
                    b[path][count]=sum;
                    count++;
                    //printf("%d ",sum);
                    return 1;
                }
        }
        return 0;
}
int main()
{
    long long int n;
    int m,i,k,temp=1000,temppath=0,c1,c[25];
    while(scanf("%lld%d",&n,&m)!=EOF)
    {
        sum=1;
        count=0;
        path=0;
        temp=1000;
        temppath=0;
        c1=0;

        memset(a,'\0',sizeof(a));
        memset(b,'\0',sizeof(b));
        for(i=0;i<m;i++)
        {
            scanf("%d",&c[i]);
            if(n%c[i]==0  && c[i]!=1)             //consider only factors of n so creating new array
            {
                a[c1]=c[i];
                c1++;
            }

        }

        qsort(a,c1,sizeof(int),compare);
        for(i=c1-1;i>=0;i--)                            // considering all paths with a[i] as the largest element in the path hence sending elements in findpath() till i+1 only
        {
            if(n%a[i]==0 && a[i]!=0 && a[i]!=1)
                {
                    k=findpath(n/a[i],i+1);                //
                    if(count<temp && count!=0 && k==1)     //if k==1 means path exists..putting last element in b[path][count]
                    {
                        b[path][count]=n;
                        temp=count;
                        count=0;
                        temppath=path;
                        sum=1;
                    }
                }
                if(k==1)
                {
                    path++;
                    k=0;
                }
        }

        if(temp!=1000)
        {
            printf("%d\n",temp);
            for(i=0;i<=temp;i++)
                {
                    printf("%d",b[temppath][i]);
                    if(i!=temp)
                        printf(" ");
                    else
                        printf("\n");
                }
        }

        if(temp==1000)
            printf("-1\n");
    }
    return 0;
}
