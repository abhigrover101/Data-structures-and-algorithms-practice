#include<cstdio>
using namespace std;

int median(int a[],int b[],int start1,int end1,int start2,int end2)
{
    int mid1=start1+(end1-start1)/2;
    int mid2=start2+(end2-start2)/2;

    if(a[mid1]==b[mid2])
        return a[mid1];

    if(end1==start1)
        return a[end1]>b[end2]? b[end2] : a[end1];

    if(end1-start1==1)
        return (a[end1]+b[start2])/2;

    if(a[mid1]>b[mid2])
    {
        return median(a,b,start1,mid1,mid2+1,end2);
    }
    else if(b[mid2]>a[mid1])
    {
        return median(a,b,mid1+1,end1,start2,mid2);
    }
}


int main()
{
    printf("Enter length of array followed by 2*N numbers\n");
    int n,a[100],b[100],i,ans;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }

    printf("%d\n",median(a,b,0,n-1,0,n-1));
    return 0;
}
