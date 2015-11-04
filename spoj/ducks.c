#include<stdio.h>
#include<string.h>
int main()
{
    int N=0,i=0;
    char s[256],c[10000];
    scanf("%d",&N);
    gets(c);
    while(N--)
    {
        i=0;
        s['D']=1;
        s['u']=1;
        s['c']=1;
        s['k']=1;
        s['y']=1;
        s['.']=5;
        gets(c);
        while(c[i]!='\0')
        {
            if(s[c[i]]==1)
                s[c[i]]++;
            else if(s[c[i]]==5);
            else if((s['D']==2 && s['u']==2 && s['c']==2 && s['c']==2 && s['k']==2 && s['y']==2))
                break;
            else
                break;
            i++;
        }
        if(s['D']==2 && s['u']==2 && s['c']==2 && s['c']==2 && s['k']==2 && s['y']==2)
            printf("DUCKY IS HERE!\n");
        else
            printf("NO DUCKY!\n");
    }
    return 0;
}
