#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

int main()
{
    int wt[100],val[100];
    printf("Enter number of elements followed by its weight and value and Knapsack limit\n");
    int n,i,sum,j,W;
    scanf("%d",&n);
    sum=0;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&wt[i],&val[i]);
        //sum=sum+wt[i];
    }
    scanf("%d",&W);

    int dp[100][100];
    memset(dp,'\0',sizeof(dp));
    for(i=0;i<n;i++)
        for(j=0;j<=W;j++)
        {
            if(i==0)
                dp[j][i]=0;
            if(j-wt[i]>=0)
                dp[j][i]=max(dp[j-wt[i]][i-1]+val[i],dp[j][i-1]);
            else
                dp[j][i]=dp[j][i-1];
        }

    printf("%d\n",dp[W][n-1]);
    return 0;
}
