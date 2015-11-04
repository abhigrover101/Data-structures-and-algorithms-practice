#include<stdio.h>
char in[50][50];
int count[50][50],x,y;

void length(int i,int j)
{	
	if(in[i][j]-in[i][j-1]==-1 && j-1>=0 && count[i][j-1]==0)
	{
		count[i][j-1]=count[i][j]+1;
		length(i,j-1);
	}
	if(in[i][j]-in[i-1][j-1]==-1 && i-1>=0 && j-1>=0  && count[i-1][j-1]==0)
	{
		count[i-1][j-1]=count[i][j]+1;
		length(i-1,j-1);
	}
	if(in[i][j]-in[i-1][j]==-1 && i-1>=0 && count[i-1][j]==0)
	{
		count[i-1][j]=count[i][j]+1;
		length(i-1,j);
	}
	if(in[i][j]-in[i-1][j+1]==-1 && i-1>=0 &&  j+1<y && count[i-1][j+1]==0)
	{
		count[i-1][j+1]=count[i][j]+1;
		length(i-1,j+1);
	}
	if(in[i][j]-in[i][j+1]==-1 && j+1<y && count[i][j+1]==0)
	{
		count[i][j+1]=count[i][j]+1;
		length(i,j+1);
	}
	if(in[i][j]-in[i+1][j+1]==-1 && i+1<x && j+1<y && count[i+1][j+1]==0)
	{
		count[i+1][j+1]=count[i][j]+1;
		length(i+1,j+1);
	}
	if(in[i][j]-in[i+1][j]==-1 && i+1<x && count[i+1][j]==0)
	{
		count[i+1][j]=count[i][j]+1;
		length(i+1,j);
	}
	if(in[i][j]-in[i+1][j-1]==-1 && i+1<x && j-1>=0 && count[i+1][j-1]==0)
	{
		count[i+1][j-1]=count[i][j]+1;
		length(i+1,j-1);
	}
	return;
}
int main()
{	
	int i=0,j=0,c=0,max=0;
	char temp=0;
	while(1)
	{
		c++;
		max=0;
		for(i=0;i<50;i++)
			for(j=0;j<50;j++)
			{
				count[i][j]=0;
				in[i][j]=0;
			}

		scanf("%d%d",&x,&y);
		if(x==0 && y==0)
			return 0;

		for(i=0;i<x;i++)
			scanf("%s",in[i]);

		for(i=0;i<x;i++)
			for(j=0;j<y;j++)
				if(in[i][j]=='A')
				{
					count[i][j]=1;
					length(i,j);
				}
		for(i=0;i<x;i++)
			for(j=0;j<y;j++)
			{
				if(count[i][j]>=max)
				max=count[i][j];
			}

	printf("Case %d: %d\n",c,max);
	}
}

