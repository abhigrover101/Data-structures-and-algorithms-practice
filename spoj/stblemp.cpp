#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int main()
{
    int T,N;
    int adj[600][600],i,num,j,pref,eng[600],m,ans[600],w;
    vector <int> man[600];
    queue <int> freem;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        //memset(adj,'\0',sizeof(adj));
        memset(eng,'\0',sizeof(eng));
        //memset(ans,'\0',sizeof(ans));
        for(i=1;i<=N;i++)
        {
            scanf("%d",&num);
            for(j=N;j>=1;j--)
            {
                scanf("%d",&pref);
                adj[num][pref]=j;
            }
        }
        for(i=1;i<=N;i++)
        {
            scanf("%d",&num);
            for(j=N;j>=1;j--)
            {
                scanf("%d",&pref);
                man[num].push_back(pref);
            }
            freem.push(num);
        }

        while(!freem.empty())
        {
            m=freem.front();
            freem.pop();
            w=man[m].front();
            if(eng[w]==0)
            {
                eng[w]=m;
                ans[m]=w;
                man[m].erase(man[m].begin());
            }
            else if(adj[w][eng[w]] < adj[w][m])
            {
                freem.push(eng[w]);
                ans[eng[w]]=0;
                eng[w]=m;
                ans[m]=w;
                man[m].erase(man[m].begin());
            }
            else
            {
                freem.push(m);
                man[m].erase(man[m].begin());
            }
        }

        for(i=1;i<=N;i++)
        {
            printf("%d %d\n",i,ans[i]);
            man[i].clear();
        }
    }
    return 0;
}
