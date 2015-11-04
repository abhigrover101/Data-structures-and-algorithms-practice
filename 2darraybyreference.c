#include<stdio.h>
void array(char a[][10],int i)
{
    if(i>0)
        array(&a[0],i-1);
    a[i][0]++;
    //printf("%d\n",a[i][0]);
    return;
}
int main()
{
    char a[10][10],i;
    //array(&a[0][0],10);
    a[0][0]=0;
    a[1][0]=1;
    a[2][0]=2;
    a[3][0]=3;
    a[4][0]=4;
    a[5][0]=5;
    a[6][0]=6;
    a[7][0]=7;
    a[8][0]=8;
    a[9][0]=9;
    array(&a[0],9);
    for(i=0;i<10;i++)
    printf("%d\n",a[i][0]);
}
