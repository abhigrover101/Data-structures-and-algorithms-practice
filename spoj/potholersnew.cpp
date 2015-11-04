#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;

int adj[300][300];
int parent[300];
int temp;
int corridors[300];
int chambers;

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

        for(i=0;i<chambers;i++)
        {
            if(adj[src][i]>0 && parent[i]==-1)
            {
                q.push(i);
                parent[i]=src;
                //printf("%d ",parent[adj[src][i]]);
                if(i==t)
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
            adj[parent[dest]][dest]--;
            adj[dest][parent[dest]]++;
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
    int src,dest,count,i,j,temp;
    while(T--)
    {
        count=0;
        scanf("%d",&chambers);
        memset(adj,'\0',sizeof(adj));
        memset(corridors,'\0',sizeof(corridors));
        for(i=0;i<chambers-1;i++)
        {
            scanf("%d",&corridors[i]);
            for(j=0;j<corridors[i];j++)
            {
                scanf("%d",&temp);
                if(i!=0 && temp!=chambers)
                    adj[i][temp-1]=100000;
                else
                    adj[i][temp-1]=1;
            }
        }
        dest=chambers-1;
        count=maxflow(0,dest);
        printf("%d\n",count);
        //for(i=0;i<chambers;i++)
        //    adj[i].clear();
    }
    return 0;
}

