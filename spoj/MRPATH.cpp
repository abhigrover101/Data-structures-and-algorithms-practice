#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
typedef pair<double,int> pp;

int main()
{
    int N,E,s,d,a,b,src,i;
    double c;
    pp temp;
    vector <pp> adj[30010];
    double dis[30010];
    memset(dis,'\0',sizeof(dis));
    scanf("%d%d",&N,&E);
    scanf("%d%d",&s,&d);
    while(E--)
    {
        scanf("%d%d%Lf",&a,&b,&c);
        adj[a].push_back(pp(c,b));
    }

    priority_queue < pp , vector< pp > ,less < pp > > que;
    que.push(pp(1,s));
    dis[s]=1;
    while(que.empty()==false)
    {
        temp=que.top();
        que.pop();
        src=temp.second;
        //printf("%d ",src);
        for(i=0;i<adj[src].size();i++)
        {
            if(dis[adj[src][i].second] < dis[src]*adj[src][i].first)
            {
                dis[adj[src][i].second]=dis[src]*adj[src][i].first;
                que.push(pp(dis[adj[src][i].second],adj[src][i].second));
            }
        }
    }
    printf("%Lf",dis[d]);
    return 0;
}
