#include<stdio.h>
#include<string.h>
int main()
{
    char s[100],a[100],b[100],c[100],ans[100];
    int k1=1,k2=1,k3=1,c1=0,c2=0,c3=0,p=0,q=0,r=0,i=0;
    while(1)
    {
        c1=0;c2=0;c3=0;

        scanf("%d%d%d",&k1,&k2,&k3);
        if(k1==0 && k2==0 && k3==0)
            break;
        scanf("%s",s);
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]>='a' && s[i]<='i')
                a[c1++]=s[i];
            else if(s[i]>='j' && s[i]<='r')
                b[c2++]=s[i];
            else if((s[i]>='s' && s[i]<='z') || s[i]=='_')
                c[c3++]=s[i];
        }

        if(c1>0)
            p=(c1-k1%(c1));
        if(c2>0)
            q=(c2-k2%(c2));
        if(c3>0)
            r=(c3-k3%(c3));
        for(i=0;i<strlen(s);i++)
        {
            if(c1>0)
                p=p%(c1);
            if(c2>0)
                q=q%(c2);
            if(c3>0)
                r=r%(c3);
            if(s[i]>='a' && s[i]<='i')
                ans[i]=a[p++];
            else if(s[i]>='j' && s[i]<='r')
                ans[i]=b[q++];
            else if((s[i]>='s' && s[i]<='z') || s[i]=='_')
                ans[i]=c[r++];
        }
        for(i=0;i<strlen(s);i++)
        {
            printf("%c",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
