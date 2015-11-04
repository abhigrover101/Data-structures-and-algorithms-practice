#include<stdio.h>
int main()
{
	int num[10000],i=0;
	while(1)
	{
		scanf("%d",&num[i++]);
		if(num[i-1]==42)
			break;
		printf("%d\n",num[i-1]);
	}
	return 0;
}
