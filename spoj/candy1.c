#include<stdio.h>
#include<string.h>
int main()
{
    int T=0,num[100000],sum,count,i,c,temp;
    while(T!=-1)
    {
        scanf("%d",&T);
        if(T==-1)
            break;
        count=T;
        sum=0;
        c=0;
        memset(num,'\0',sizeof(num));
        for(i=0;i<T;i++){
            scanf("%d",&num[i]);
            sum+=num[i];
        }
        if(sum%count==0)
        {
            temp=sum/count;
            for(i=0;i<T;i++)
                if(num[i]<temp)
                    c=c+(temp-num[i]);
            printf("%d\n",c);
        }
        else
            printf("-1\n");
    }
    return 0;
}
