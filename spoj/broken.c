#include<stdio.h>
#include<string.h>
int main()
{
    long long int T=0,submax=0,max=0,count=0,head,tail,len;
    char str[1000000];
    long long int ch[129];
    long long int i=0;
    while(1)
    {
        head=0;
        tail=0;
        count=0;
        memset(ch,'\0',sizeof(ch));
        max=0;
        scanf("%lld",&T);
        if(T==0)
            return 0;
        scanf("\n%[^\n]",str);
        len=strlen(str);
        if(len<=T)
            printf("%lld",len);
        while(tail!=len)
        {
            if(ch[str[tail]]==0 && count<=T)
            {
                ch[str[tail]]++;
                count++;
                tail++;
            }
            else if(ch[str[tail]]!=0 && count<=T)
            {
                ch[str[tail]]++;
                tail++;
            }
            else if(ch[str[head]]==1)
            {
                ch[str[head]]=0;
                head++;
                count--;
            }
            else if(ch[str[head]]!=1)
            {
                ch[str[head]]--;
                head++;
            }
            if(max<tail-head && count<=T)
                max=tail-head;
        }

        /*for(i=0;i<strlen(str);i++)
        {
            if(ch[str[i]]!=0)
            {
                //printf("%c",str[i]);
                ch[str[i]]++;
                submax++;
                if(max<submax && count)
                    max=submax;
            }
            else if(ch[str[i]]==0)
            {
                ch[str[i]]++;
                count++;
                while(1)
                {
                    if(i-submax>=0)
                        ch[str[i-submax]]--;
                    else
                        break;
                    if(ch[str[i-submax]]==0)
                        break;
                    else
                        submax--;
                }
            }
        }*/
        printf("%lld\n",max);
    }
    return 0;
}
