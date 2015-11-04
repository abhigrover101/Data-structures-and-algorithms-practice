#include<stdio.h>
#include<map>
map<string,int> mymap;
int main()
{
    int n=5;
    char s[10];
    while(n--)
    {
        scanf("%s",s);
        mymap[s]=n;
        printf("%d\n",mymap[s]);
    }
    return 0;
}

