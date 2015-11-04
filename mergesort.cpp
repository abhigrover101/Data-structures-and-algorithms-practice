#include<cstdio>
#include<stdlib.h>
#include<string>
using namespace std;

void merge(int *a,int start1,int end1,int start2,int end2);

void mergesort(int *a,int start,int end)
{
    //printf("%d %d %d\n",start,end,a[0]);
    //scanf("%*c");
    if(start>=end)
        return;
    mergesort(a,start,(start+end)/2);
    mergesort(a,(start+end)/2+1,end);
    merge(a,start,(start+end)/2,(start+end)/2+1,end);
    return;
}

void merge(int *a,int start1,int end1,int start2,int end2)
{
    int b[end2-start1+1];
    int s=start1;
    int count=0;
    while(start1<=end1 || start2<=end2)
    {
        if(a[start1]<=a[start2] && start1<=end1 && start2<=end2)
        {
            b[count]=a[start1];
            count++;
            start1++;
        }
        else if(a[start1]>a[start2] && start2<=end2 && start1<=end1)
        {
            b[count]=a[start2];
            count++;
            start2++;
        }
        else if(start1>end1)
            b[count++]=a[start2++];
        else if(start2>end2)
            b[count++]=a[start1++];


    }
    count=0;

    int i;
    for(i=s;i<=end2;i++)
    {
        a[i]=b[count++];
    }
    //printf("end %d\n",end2);
    return;
}




int main()
{
    int a[100];
    printf("Enter N followed by numbers\n");
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    mergesort(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
