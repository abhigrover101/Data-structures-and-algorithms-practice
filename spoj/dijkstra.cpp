#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
typedef pair<int,int> pp;

//#define ver 10001
//int amat[ver][ver],check[ver][ver];

vector< pair<int,int> > amat[10001];

int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		int i=0,vert=0,edges=0,x=0,y=0,weight=0,A=0,B=0;
		scanf("%d%d",&vert,&edges);
		for(i=0;i<edges;i++)
		{
			scanf("%d%d%d",&x,&y,&weight);
			amat[x-1].push_back(pp(y-1,weight));
			//amat[y-1].push_back(pp(x-1,weight));
		}
		scanf("%d%d",&A,&B);
		A=A-1;
		B=B-1;
		int dis[vert],visited[vert];
		for(i=0;i<vert;i++)
			dis[i]=10000;
		memset(visited,0,sizeof(visited));

		dis[A]=0;

		priority_queue <pp,vector< pp >,greater< pp > > pq;
		pq.push(pp(dis[A],A));

		while(pq.empty()==false)
		{
			pp q=pq.top();
			pq.pop();
			if(visited[q.second]==1)
				continue;
			else
				visited[q.second]=1;

			for(i=0;i<amat[q.second].size();i++)
			{
				if(amat[q.second][i].second + q.first< dis[amat[q.second][i].first])
				{
					dis[amat[q.second][i].first]=amat[q.second][i].second+q.first;
					pq.push(pp(dis[amat[q.second][i].first],amat[q.second][i].first));
				}
			}

			if(visited[B]==1)
				break;
		}
		if(visited[B]==1)
			printf("%d\n",dis[B]);
		else
			printf("NO\n");

		for(i=0;i<sizeof(10001);i++)
			amat[i].clear();
	}

	return 0;
}
