#include<stdio.h>
long long int count;
int k[200000];
void merge_sort(int *a,int start1,int end1,int start2,int end2)
{
    //printf("%d %d\n",start1,end1);
    //printf("%d %d\n",start2,end2);

    int i,j,aa,b;
    if(end1-start1>=1)
        merge_sort(&a[0],start1,(start1+end1)/2,(start1+end1)/2+1,end1);
    if(end2-start2>=1)
        merge_sort(&a[0],start2,(start2+end2)/2,(start2+end2)/2+1,end2);
    i=start1;
    j=start2;
    aa=start1;
    b=end2;
    while(i<=end1 || j<=end2)
    {
        if(a[i]<a[j] && i<=end1 && j<=end2)
        {
            k[start1++]=a[i];
            i++;
        }
        else if(a[i]>a[j] && i<=end1 && j<=end2)
        {
            k[start1++]=a[j];
            count=count+end1-i+1;
            j++;
        }
        else if(i>end1)
        {
            k[start1++]=a[j];
            j++;
        }
        else if(j>end2)
        {
            k[start1++]=a[i];
            i++;
        }
    }
    for(i=aa;i<=b;i++)
        a[i]=k[i];
    return;
}

int main()
{
    int T;
    int N,a[200000],i;
    scanf("%d",&T);
    while(T--)
    {
        count=0;
        scanf("%d",&N);
        for(i=0;i<N;i++)
            scanf("%d",&a[i]);
        merge_sort(&a[0],0,(N-1)/2,(N+1)/2,N-1);
        printf("%lld\n",count);
       // merge_sort(&a[0],N/2+1,N);
    }
    return 0;
}
