#include<stdio.h>
#include <iostream>
#include <queue>
using namespace std;

typedef struct node{
    int p1;
    int p2;
    int p3;
}nn;

int main()
{
    int n,a,b,c;
    int adj[60][60],count[60][60][60];
    nn pos,temp;
    int i,j,k,flag;
    queue <nn> q;         //c++ inbuilt que
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        scanf("%d%d%d",&a,&b,&c);
        a=a-1;                          //as arrays start from 0
        b=b-1;
        c=c-1;
        flag=0;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf(" %c",&adj[i][j]);
        pos.p1=a;
        pos.p2=b;
        pos.p3=c;
        q.push(pos);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                for(k=0;k<n;k++)
                    count[i][j][k]=100000;
        count[a][b][c]=0;

        while(!q.empty())
        {
            pos=q.front();
            q.pop();
            if(pos.p1==pos.p2 && pos.p2==pos.p3)
            {
                flag=1;
                printf("%d\n",count[pos.p1][pos.p2][pos.p3]);
                break;
            }
            //printf("pos.p1 %d %d %d\n",pos.p1,pos.p2,pos.p3);
            for(i=0;i<n;i++)
            {
                if((adj[pos.p1][i]==adj[pos.p2][pos.p3]) && (count[i][pos.p2][pos.p3] > count[pos.p1][pos.p2][pos.p3]+1))
                {
                    temp.p1=i;
                    temp.p2=pos.p2;
                    temp.p3=pos.p3;
                    count[i][pos.p2][pos.p3] = count[pos.p1][pos.p2][pos.p3] +1;
                    q.push(temp);
                }
                if((adj[pos.p2][i]==adj[pos.p1][pos.p3]) && (count[pos.p1][i][pos.p3] > count[pos.p1][pos.p2][pos.p3]+1))
                {
                    temp.p1=pos.p1;
                    temp.p2=i;
                    temp.p3=pos.p3;
                    count[pos.p1][i][pos.p3] = count[pos.p1][pos.p2][pos.p3] +1;
                    q.push(temp);
                }
                if((adj[pos.p3][i]==adj[pos.p1][pos.p2]) && (count[pos.p1][pos.p2][i] > count[pos.p1][pos.p2][pos.p3]+1))
                {
                    temp.p1=pos.p1;
                    temp.p2=pos.p2;
                    temp.p3=i;
                    count[pos.p1][pos.p2][i] = count[pos.p1][pos.p2][pos.p3] +1;
                    q.push(temp);
                }
            }
        }
        if(flag==0)
            printf("impossible\n");
        while(!q.empty())
            q.pop();
    }
    return 0;
}
