#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef pair<int,int> pp;

int main()
{
    vector <int> paths[50010];
    pp temp;
    int source,dest,floors,lifts,end1,end2,time,i=0,src;
    int dis[50010];
    //scanf("%d",&T);
    //while(T--)
    {
        scanf("%d%d",&floors,&lifts);
        for(i=0;i<lifts;i++)
        {
            scanf("%d%d",&end1,&end2);
            paths[end1-1].push_back(end2-1);
            paths[end2-1].push_back(end1-1);
        }
        priority_queue < pp , vector< pp > ,greater < pp > > que;

        source=0;
        dest=floors-1;

		for(i=0;i<floors;i++)
			dis[i]=1000000000;
        que.push(pp(0,source));
        dis[source]=0;
        while(que.empty()==false)
        {

            temp=que.top();
            que.pop();
            src=temp.second;
            //printf("src %d %d\n",src,dis[src]);
            //if(src==dest)
            //    break;
            for(i=0;i<paths[src].size();i++)
            {
                if(dis[paths[src][i]] > (dis[src]+((2*abs(paths[src][i]-src))-(dis[src]%(2*abs(paths[src][i]-src))))%(2*abs(paths[src][i]-src))+abs(paths[src][i]-src)))
                {
                    //
                   // if(dis[paths[src][i]]==1000000000)
                    //{
                        dis[paths[src][i]]=dis[src]+((2*abs(paths[src][i]-src))-(dis[src]%(2*abs(paths[src][i]-src))))%(2*abs(paths[src][i]-src))+abs(paths[src][i]-src);
                        que.push(pp(dis[paths[src][i]],paths[src][i]));
                        //printf("vertex %d\n",paths[src][i].first);
                    //}
                    //else
                    //    dis[paths[src][i]]=dis[src]+((2*abs(paths[src][i]-src))-(dis[src]%(2*abs(paths[src][i]-src))))%(2*abs(paths[src][i]-src))+abs(paths[src][i]-src);
                }
            }
        }
        printf("%d\n",dis[dest]*5);

		for(i=0;i<50010;i++)
			paths[i].clear();

    }
    return 0;

}
