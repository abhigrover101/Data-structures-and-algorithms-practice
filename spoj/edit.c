#include<stdio.h>
#define caps 1
#define small 0
#include<string.h>
int main()
{
    char str[1002];
    int flag=3,k,count,i,ebig,esmall,obig,osmall;
    while(scanf("%s",str)!=EOF)
    {
        ebig=0;
        esmall=0;
        obig=0;
        osmall=0;

        k=strlen(str);

        for(i=0;i<k;i++)
        {
            if(str[i]>='A' && str[i]<='Z' && i%2==0)
                ebig++;
            else if(str[i]>='a' && str[i]<='z' && i%2==0)
                esmall++;
            else if(str[i]>='A' && str[i]<='Z' && i%2!=0)
                obig++;
            else if(str[i]>='a' && str[i]<='z' && i%2!=0)
                osmall++;
        }

        if(ebig+osmall>=esmall+obig)
            printf("%d\n",esmall+obig);
        else
            printf("%d\n",ebig+osmall);
    }
    return 0;
}
