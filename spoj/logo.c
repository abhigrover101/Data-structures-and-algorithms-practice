#include<stdio.h>
#include<string.h>
int main()
{
	char dir[1000];
	int grid[500][500]={0,0};
	int x,y,count,i=0,j=0;
	while(1)
	{
		for(i=0;i<500;i++)
			for(j=0;j<500;j++)
				grid[i][j]=0;
		i=0;
		x=250;
		y=250;
		count=0;
		grid[x][y]=1;
		scanf("%s",dir);
		if(strcmp(dir,"Q")==0)
			return 0;
		for(i=0;i<strlen(dir);i++)
		{
			if(dir[i]=='U')
			{
				y++;
				if(grid[x][y]==1)
					count++;
				grid[x][y]=1;
			}
			else if(dir[i]=='D')
			{
				y--;
				if(grid[x][y]==1)
					count++;
				grid[x][y]=1;
			}
			else if(dir[i]=='R')
			{
				x++;
				if(grid[x][y]==1)
					count++;
				grid[x][y]=1;
			}
			else if(dir[i]=='L')
			{
				x--;
				if(grid[x][y]==1)
					count++;
				grid[x][y]=1;
			}
			else if(dir[i]=='Q')
				break;
		}
		printf("%d\n",count);
	}
		return 0;
}
