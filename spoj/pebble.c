#include<stdio.h>
int main()
{
    char str[10000],temp=0;
    int count=0,length=0,game=0,c=0;
    while(scanf("%s",str)!=EOF)
    {
        count=0;
        temp='0';
        c=0;
        game++;
        while(str[c]!='\0')
        {
            if(str[c]==temp)
                c++;
            else
            {
                temp=str[c];
                count++;
                c++;
            }
        }
        printf("Game #%d: %d\n",game,count);
    }
    return 0;
}
