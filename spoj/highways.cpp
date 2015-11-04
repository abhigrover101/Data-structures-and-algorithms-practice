#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
typedef pair<int,int> pp;

int main()
{
    vector <pp> paths[100010];
    pp temp;
    int T,source,dest,cities,highways,end1,end2,time,i=0,dis[100010],src;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&cities,&highways,&source,&dest);
        for(i=0;i<highways;i++)
        {
            scanf("%d%d%d",&end1,&end2,&time);
            paths[end1-1].push_back(pp(end2-1,time));
            paths[end2-1].push_back(pp(end1-1,time));
        }
        priority_queue < pp , vector< pp > ,greater < pp > > que;

        source=source-1;
        dest=dest-1;

		for(i=0;i<cities;i++)
			dis[i]=100000000;
        que.push(pp(0,source));
        dis[source]=0;
        while(que.empty()==false)
        {

            temp=que.top();
            que.pop();
            src=temp.second;
            for(i=0;i<paths[src].size();i++)
            {
                if(dis[paths[src][i].first] > dis[src]+paths[src][i].second)
                {
                    //
                    if(dis[paths[src][i].first]==100000000)
                    {
                        dis[paths[src][i].first]=dis[src]+paths[src][i].second;
                        que.push(pp(dis[paths[src][i].first],paths[src][i].first));
                        //printf("vertex %d\n",paths[src][i].first);
                    }
                    else
                        dis[paths[src][i].first]=dis[src]+paths[src][i].second;
                }
            }
        }
        if(dis[dest]==100000000)
            printf("NONE\n");
        else
            printf("%d\n",dis[dest]);

		for(i=0;i<100010;i++)
			paths[i].clear();

    }
    return 0;

}
