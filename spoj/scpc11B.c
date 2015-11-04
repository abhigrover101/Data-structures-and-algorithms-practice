#include<stdio.h>
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int main()
{
    int dis[1433];
    int N,i,flag=0;
    while(1)
    {
        flag=0;
        //memset(dis,'\0',sizeof(dis));
        scanf("%d",&N);
        if(N==0)
            return 0;
        for(i=0;i<N;i++)
            scanf("%d",&dis[i]);

        qsort(dis,N,sizeof(int),compare);

        if((2*(1422-dis[N-1])>200))
           {
               printf("IMPOSSIBLE\n");
               continue;
           }

        for(i=1;i<N;i++)
        {
            if(dis[i]-dis[i-1]>200)
            {
                printf("IMPOSSIBLE\n");
                flag=1;
                break;
            }
        }
        if(flag==0)
            printf("POSSIBLE\n");
    }
    return 0;
}
