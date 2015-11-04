#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int compare (const void * c, const void * d)
{
  return ( *(int*)d - *(int*)c );
}

int main()
{
    int N;
    int num=1,frnds,sum,f[1001],count=0,i=0,j;
    scanf("%d",&N);
    for(j=1;j<=N;j++)
    {
        num=0;
        frnds=0;
        sum=0;
        count=0;
        memset(f,'\0',sizeof(f));
        scanf("%d%d",&num,&frnds);
        for(i=0;i<frnds;i++)
            scanf("%d",&f[i]);

        qsort(f,frnds,sizeof(int),compare);
        while(num>0)
        {
            num=num-f[count];
            count++;
            if(count>frnds)
                {
                    printf("Scenario #%d:\nimpossible\n",j);
                    break;
                }
        }
        if(!(count>frnds))
            printf("Scenario #%d:\n%d\n",j,count);
    }
    return 0;
}
