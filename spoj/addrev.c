#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int rev(char *num)
{
	int i=strlen(num)-1,j=0;
	char revno[10];
	for(;i>=0;i--)
		revno[j++]=num[i];
	revno[j]='\0';
	return atoi(revno);
}

int main()
{
	int i=0,N=0,sum=0;
	char num1[10],num2[10];
	scanf("%d",&N);
	while(N--)
	{
		scanf("%s%s",num1,num2);
		sum=rev(num1)+rev(num2);
		sprintf(num1,"%d",sum);
		sum=rev(num1);
		printf("%d\n",sum);
	}
	return 0;
}
		
