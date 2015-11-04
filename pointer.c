#include<stdio.h>
void main()
{
	int *temp,**ipp;
	int x=25,p=100;
	*temp=x;
	ipp=&temp;
	*ipp=&p;
	printf("%d,%d\n",x,*temp);
}
