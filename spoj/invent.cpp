#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;

long long int ans;

struct node
{
    struct node *parent;
    int rank;
    long long int count;
};
struct node * find(struct node *x)
{
    if(x->parent==x)
        return x;
    else
        find(x->parent);
}

void uni(struct node * x,struct node *y,int w)
{
    struct node *rootx,*rooty;
    rootx=find(x);
    rooty=find(y);
    //printf("%d",rootx->count);
    if(rootx==rooty)
        return;
    if(rootx->rank==rooty->rank)
    {
        //printf("%d",rootx->count);
        ans=ans+(rootx->count)*(rooty->count)*(w+1)-(1);
        rooty->parent=rootx;
        rootx->count+=rooty->count;
        rootx->rank+=1;
    }
    else if(rootx->rank > rooty->rank)
    {
        ans=ans+(rootx->count)*(rooty->count)*(w+1)-(1);
        rooty->parent=rootx;
        rootx->count+=rooty->count;

    }
    else if(rooty->rank > rootx->rank)
    {
        ans=ans+(rootx->count)*(rooty->count)*(w+1)-(1);
        (rootx->parent)=rooty;
        (rooty->count)+=(rootx->count);
    }
    return;
}

int main()
{
    int T,n,a,b,w,j,i;
    scanf("%d",&T);
    pair<int , int > vert;
    pair<int, pair <int, int > > l;
    pair <int, int > temp,m;
    struct node *element[15010];

    vector <pair <int , pair<int , int > > > edges;
    while(T--)
    {
        scanf("%d",&n);
        j=n;
        n--;
        ans=0;
        while(n--)
        {
            scanf("%d%d%d",&a,&b,&w);
            edges.push_back(make_pair(w,make_pair(a,b)));
            //printf("%d size\n",edges.size());
        }
        sort(edges.begin(),edges.end());
        for(i=1;i<=j;i++)
        {
            element[i]=(struct node *)malloc(sizeof(struct node));
            element[i]->parent=element[i];
            element[i]->rank=0;
            element[i]->count=1;
        }
        //printf("%d size",j);
        for(i=0;i<j-1;i++)
        {
            l=edges[i];
            temp=edges[i].second;
            //printf("%d ",l.first);
            uni(element[temp.first],element[temp.second],edges[i].first);
        }
        printf("%lld\n",ans);
        for(i=1;i<=j;i++)
        {
            free(element[i]);
        }
        edges.clear();
    }
    return 0;
}
