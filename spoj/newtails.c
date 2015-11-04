#include<stdio.h>
int main()
{
	int count=0,i,count1=0;
	int coin[20],coin1[20];
	for(i=0;i<20;i++)
	{
		scanf("%d",&coin[i]);
		coin1[i]=coin[i];
	}
	for(i=1;i<20;i++)
	{
		if(coin[i-1]==1)
		{
			count++;
			coin[i-1]=0;
			coin[i]=!coin[i];
			if(i+1<20)
				coin[i+1]=!(coin[i+1]);
		}
	}
	for(i=0;i<20;i++)
	{
		if(i==0)
		{
			count1++;
			coin1[i]=!coin1[i];
			coin1[i+1]=!coin1[i+1];
		}
		else if(coin1[i-1]==1)
		{
			count1++;
			coin1[i-1]=0;
			coin1[i]=!coin1[i];
			if(i+1<20)
				coin1[i+1]=!(coin1[i+1]);
		}
	}
	if(count1<count)
		count=count1;
	printf("%d\n",count);
	return 0;
}
