#include<stdio.h>
#include<string.h>
int main()
{
    int N,s[27],count=0,i=0,flag=0,a[27][27],start=0,visited[27],e[27],que[100000],chk[27];
    long long int n=0;
    char str[1001];
    scanf("%d",&N);
    while(N--)
    {
        i=0;
        start=0;
        flag=0;
        count=0;
        n=0;
        memset(s,'\0',sizeof(s));
        memset(e,'\0',sizeof(e));
        memset(visited,'\0',sizeof(visited));
        memset(a,'\0',sizeof(a));
        memset(que,'\0',sizeof(que));
        memset(chk,'\0',sizeof(chk));
        scanf("%lld",&n);
        while(n--)
        {
            scanf("%s",str);
//            if(str[0]!=str[strlen(str)-1])
            chk[str[0]-97]++;
            chk[str[strlen(str)-1]-97]++;
            s[str[0]-97]++;
            e[str[strlen(str)-1]-97]++;
            a[str[strlen(str)-1]-97][str[0]-97]++;
            a[str[0]-97][str[strlen(str)-1]-97]++;
        }

        que[0]=str[0]-97;
        count++;
        //printf("%d",que[0]);

        while(count!=0)
        {
            start=que[count-1];
            count--;
            visited[start]=1;

            for(i=0;i<26;i++)
                if((a[start][i]>0 || a[i][start]>0) && visited[i]==0)
                    {
                        //visited[i]=1;
                        que[count]=i;
                        count++;
                        //printf("%d\n",i);
                    }

        }

        for(i=0;i<26;i++)
        {
            if(chk[i] && !visited[i])
            {
                printf("The door cannot be opened.\n");
                flag=1;
                break;
            }
        }

        if(flag==0)
            for(i=0;i<26;i++)
                count=count + abs(s[i]-e[i]);

        if((count==0 || count==2) && flag==0)
            printf("Ordering is possible.\n");
        else if(flag==0)
            printf("The door cannot be opened.\n");
    }
    return 0;
}
