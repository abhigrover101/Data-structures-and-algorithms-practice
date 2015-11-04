#include<cstdio>
#include<vector>
using namespace std;
bool chkcycle(int i,int *v,int n,int in[][100])
{
    int j;
    if(v[i]==0)
        v[i]=1;
    else if(v[i]==1)
        return true;
    for(j=1;j<=n;j++)
    {
        if(in[i][j]!=0)
        {
            if(chkcycle(j,v,n,in))
                return true;
        }
    }
    v[i]=2;
    return false;
}

void dfs(int i,int *st,int *fi,int n,int in[][100],int *t)
{
    int j;
    if(st[i]==0)
    {
        st[i]=*t;
        *t=*t+1;
    }
    else
        return;
    for(j=1;j<=n;j++)
    {
        if(in[i][j]!=0)
        {
            dfs(j,st,fi,n,in,t);
        }
    }
    fi[i]=*t;
    *t=*t+1;
    return;
}

int main()
{
    int in[100][100]={{0,0}};
    int a,b,c,t,visited[100]={0},n,ti,st[100]={0},fi[100]={0},i;
    printf("Enter number of vertices\n");
    scanf("%d",&n);
    printf("Enter number of lines followed by adjacency matrix\n");
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&c);
        in[a][b]=c;
    }

    if(chkcycle(1,visited,n,in))
        printf("There is a cycle\n");
    else
        printf("There is no cycle\n");

    ti=1;
    dfs(1,st,fi,n,in,&ti);
    for(i=1;i<=n;i++)
        printf("Vertex %d: Start Time %d Finish Time %d\n",i,st[i],fi[i]);
    return 0;
}
