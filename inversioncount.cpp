#include<cstdio>
using namespace std;

void merge(int *a,int start1,int end1,int start2,int end2,int *ans)
{
    int b[end2-start1+1],i=0;
    int start=start1;
    int end=end2;
    int count=start1;
    while(start1<=end1 && start2<=end2)
    {
        if(a[start1]>a[start2])
        {
            b[count++]=a[start2];
            *ans+=(end1-start1)+1;
            start2++;
        }
        else
        {
            b[count++]=a[start1++];
        }
    }
    while(start1<=end1)
    {
        b[count++]=a[start1++];
    }
    while(start2<=end2)
    {
        b[count++]=a[start2++];
    }

    for(i=start;i<=end;i++)
        a[i]=b[i];
}

void invcount(int *a,int start,int end,int *ans)
{
    if(start>=end)
        return;
    int mid=(start+end)/2;
    invcount(a,start,mid,ans);
    invcount(a,mid+1,end,ans);
    merge(a,start,mid,mid+1,end,ans);
}

int main()
{
    printf("Enter n and elements:\n");
    int n,i,a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    int ans=0;
    invcount(a,0,n-1,&ans);
    printf("%d\n",ans);
}
