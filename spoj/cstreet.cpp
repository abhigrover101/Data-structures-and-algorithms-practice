#include<stdio.h>
#include<queue>
#include<string.h>
#include<vector>

using namespace std;
typedef pair < int , int > pp;

int adj[1100][1100];
int main()
{
    pp s;
    int T,p,n,m,a,b,c,d[1100],v[1100],i;
    long long int sum;
    scanf("%d",&T);
    while(T--)
    {
        memset(adj,'\0',sizeof(adj));
        memset(v,'\0',sizeof(v));
        scanf("%d%d%d",&p,&n,&m);
        while(m--)
        {
            for(i=0;i<=n;i++)
                d[i]=10000000;
            scanf("%d%d%d",&a,&b,&c);
            adj[a][b]=c;
            adj[b][a]=c;
        }
        priority_queue < pp , vector< pp > ,greater < pp > > que;
        que.push(pp(0,1));
        d[1]=0;
        sum=0;
        while(!que.empty())
        {
            s=que.top();
            que.pop();
            v[s.second]=1;
            //printf("%d %d\n",s,d[s]);
            for(i=1;i<=n;i++)
            {
                if((d[i] > adj[s.second][i]) && adj[s.second][i]!=0 && v[i]==0)
                {
                    d[i]=adj[s.second][i];
                    que.push(pp(d[i],i));
                    //printf("%d %d\n",i,d[i]);
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            sum=sum+d[i];
        }
        printf("%lld\n",sum*p);
    }
    return 0;
}
