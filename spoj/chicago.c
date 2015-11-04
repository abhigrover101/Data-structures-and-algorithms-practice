#include<stdio.h>
#include<string.h>
int stack[10000];
int end;
int start;

int pop()
{
	int temp=stack[start];
	start++;
	return temp;
}

void push(int number)
{
	stack[end]=number;
	end++;
	return;
}

int main()
{
	int n=1,m=0,i=0,end1=0,end2=0,j=0,e1=1,e2;
    double per=0;
	while(1)
	{

		n=0;
		m=0;
		i=0;
		per=0;
		e1=0;
		e2=0;

		scanf("%d",&n);
		start=0;
		end=0;
		if(n==0)
			break;

		scanf("%d",&m);
		double adj[n][n];
		int visited[n];
		double cost[n];
		for(i=0;i<n;i++)
		{
			memset(adj[i],'\0',sizeof(adj[i]));
			cost[i]=0;
			visited[i]=0;
		}

		for(i=0;i<m;i++)
		{
			scanf("%d%d%lf",&end1,&end2,&per);
			adj[end1-1][end2-1]=per;
			adj[end2-1][end1-1]=per;
		}

		cost[0]=1;
		push(0);
		visited[0]=1;
		while(1)
		{

			e1=pop();
			visited[e1]=1;

			for(i=0;i<n;i++)
			{
				if(adj[e1][i]!=0)
				{
			//		if(visited[i]==0)
					if(cost[i] < cost[e1]*adj[e1][i]/100.0)
					{
						cost[i]=cost[e1]*adj[e1][i]/100.0;
						push(i);
					}
				}
			}
			if(start==end)
				break;
		}
		printf("%.6lf percent\n",cost[n-1]*100);
	}

	return 0;
}
