#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    char one[100],two[100];
    char *endptr;
    int flag=0;
    double dis=0;
    double a=0,b=0,pa=0,pb=0;
    while(scanf("%*[^'(']%*c%[^',']%*c%*c%[^')']%*c%*c",one,two)!=EOF)
    {
        a=strtod(one,&endptr);
        b=strtod(two,&endptr);
        if(flag!=0)
            dis+=sqrt((pa-a)*(pa-a)+(pb-b)*(pb-b));

        pa=a;
        pb=b;
        if(flag!=0)
            printf("The salesman has traveled a total of %.3lf kilometers.\n",dis);
        flag=1;
        //printf("%lf",b);
    }
    return 0;
}
