#include<cstdio>
int bsearch(int *lis,int n,int length)
{
    int l,r,m=0;
    l=0;
    r=length-1;
    while(l<r)
    {
        m=l+(r-l+1)/2;
        if(lis[m]>n)
        {
            r=m-1;
        }
        else
        {
            l=m;
        }
    }
    m=l+(r-l+1)/2;
    //lis[m]=n;
    return m;
}

int main()
{
    int lis[1000]={0},i=0,length=0,a[1000]={0},n,m[1000]={0},p[1000]={0},temp=0;
    printf("Enter Size of array and Numbers\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    lis[0]=a[0];
    m[0]=0;
    p[0]=-1;
    length++;
    for(i=1;i<n;i++)
    {
        if(a[i]>lis[length-1])
        {
            lis[length]=a[i];
            m[length]=i;
            p[i]=m[length-1];
            length++;
        }
        else if(a[i]<lis[length-1])
        {
            temp=bsearch(&lis[0],a[i],length);
            lis[temp]=a[i];
            m[temp]=i;
            if(temp==0)
                p[i]=-1;
            else
                p[i]=m[temp-1];
        }
    }
    printf("%d\n",length);
    temp=m[length-1];
    while(1)
    {
        printf("%d ",a[temp]);
        temp=p[temp];
        if(temp<0)
            break;
    }
    return 0;
}
