//2 find max in subarrays of size k
#include<cstdio>
#include<string.h>
int main()
{
    printf("Enter number of integers and integers itself\n");
    int n,start=0,end=0,i,s;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter windowsize\n");
    scanf("%d",&s);
    int q[10000];
    memset(q,sizeof(int),'\0');
    for(i=0;i<n;i++)
    {
        while(end>0 && end>start && a[i]>q[end-1])
            end--;
        q[end]=a[i];
        end++;
        if(end-start>s)
            start++;
        if(i>=s-1)
            printf("%d\n",q[start]);
    }
    return 0;
}
