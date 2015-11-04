#include<stdio.h>
#include <stdlib.h>
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main()
{

    int T,l=0,i;
    scanf("%d",&T);
    int N,count=0;
    int in[105];
    int out[105];
    int max=0;
    while(T--)
    {
        l=0;
        count=0;
        max=0;
        scanf("%d",&N);
        for(i=0;i<N;i++)
            scanf("%d%d",&in[i],&out[i]);
        qsort (in, N, sizeof(int), compare);
        qsort (out, N, sizeof(int), compare);
        for(i=0;i<N;i++)
        {
            while(in[i]>out[l])
            {
                count--;
                l++;
            }
            count++;
            if(count>max)
                    max=count;
        }
        printf("%d\n",max);
    }
}
