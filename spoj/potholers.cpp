// This aint working

#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;

vector<int> adj[300];
int parent[300];
int temp;

int reachable(int s,int t)
{

    int i,src,flag=0;
    queue<int> q;
    q.push(s);
    memset(parent,255,sizeof(parent));
    parent[s]=s;
    while(!q.empty() && flag!=1)
    {
        src=q.front();
        q.pop();

        for(i=0;i<adj[src].size();i++)
        {
            if(parent[adj[src][i]]==-1)
            {
                q.push(adj[src][i]);
                parent[adj[src][i]]=src;
                //printf("%d ",parent[adj[src][i]]);
                if(adj[src][i]==t)
                {
          //          printf("pppdest %d ",parent[11]);
                    flag=1;
                    break;
                }
            }
        }
        //scanf("%d",&temp);
    }
    while(!q.empty())
        q.pop();

    if(flag==1)
        return 1;
    else
        return 0;
}

int maxflow(int s,int t)
{
    int dest,i,flag;
    int src=s,flow=0;
    //parent[s]=s;

    while((reachable(s,t))==1)
    {
        flag=0;
        dest=t;
        //printf("zzzdest %d ",dest);
        while(parent[dest]!=dest)
        {
            //printf("pdest %d ",parent[dest]);
            if(dest==t || parent[dest]==s)
            {
                for(i=0;i<adj[parent[dest]].size();i++)
                {
                    if(adj[parent[dest]][i]==dest)
                    {
                        //printf("erased %d ",adj[parent[dest]][i]);
                        adj[parent[dest]].erase(adj[parent[dest]].begin()+i);
                    }
                }
            }
            for(i=0;i<adj[dest].size();i++)
                if(adj[dest][i]==parent[dest])
                    flag=1;
            if(flag==0)
                adj[dest].push_back(parent[dest]);
            dest=parent[dest];
            //scanf("%d",&temp);
           // printf("dest %d ",dest);
        }
        flow++;
    }
    return flow;
}

int main()
{
    int T;
    scanf("%d",&T);
    int corridors;
    int src,dest,count,i,j,chambers,temp;
    while(T--)
    {
        count=0;
        scanf("%d",&chambers);
        for(i=0;i<chambers-1;i++)
        {
            scanf("%d",&corridors);
            for(j=0;j<corridors;j++)
            {
                scanf("%d",&temp);
                adj[i].push_back(temp-1);
            }
        }
        dest=chambers-1;
        count=maxflow(0,dest);
        printf("%d\n",count);
        for(i=0;i<chambers;i++)
            adj[i].clear();
    }
    return 0;
}
