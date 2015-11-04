#include<cstdio>
#include<string.h>
using namespace std;

void swap(char *s1,char *s2)
{
    *s1=*s2+*s1-(*s2=*s1);
}

void permut(char *s,int start,int end)
{
    if(start==end)
        printf("%s\n",s);
    int i;
    for(i=start;i<end;i++)
    {
        swap(&s[start],&s[i]);
        permut(s,start+1,end);
        swap(&s[start],&s[i]);
    }
    return;
}

int main()
{
    char s[100];
    printf("Enter string:\n");
    scanf("%s",s);
    permut(s,0,strlen(s));
    return 0;
}
