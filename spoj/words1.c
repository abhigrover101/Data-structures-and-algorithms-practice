#include<stdio.h>
#include<string.h>
int main()
{
    int N,n,start[26],end[26],count=0,i=0,flag=0,same[26];
    char str[1001];
    scanf("%d",&N);
    while(N--)
    {
        flag=0;
        count=0;
        memset(start,'\0',sizeof(start));
        memset(end,'\0',sizeof(end));
        memset(same,'\0',sizeof(same));
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s",str);
            if(str[0]!=str[strlen(str)-1])
            {
                start[str[0]-97]++;
                end[str[strlen(str)-1]-97]++;
            }
            else
                same[str[0]-97]++;
        }

        for(i=0;i<26;i++)
        {
            if(same[i]!=0 && end[i]==0)
            {
                printf("The door cannot be opened.\n");
                flag=1;
                break;
            }
            count+=abs(start[i]-end[i]);
        }
        if(flag==1);
        else if(count==0 || count==2)
            printf("Ordering is possible.\n");
        else
            printf("The door cannot be opened.\n");
    }
    return 0;
}
