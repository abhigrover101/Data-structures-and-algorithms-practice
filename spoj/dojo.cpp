#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
    int T;
    int a,b,x,y;
    char s1[2010],s2[2010];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%s%d%s",&a,s1,&x,s2);
        b=s1[strlen(s1)-1]-'0';
        y=s2[strlen(s2)-1]-'0';
        if((a%2==1 && b%2==1) && (x%2==y%2))
            printf("Possible.\n");
        else
            printf("Impossible.\n");
    }
    return 0;
}
