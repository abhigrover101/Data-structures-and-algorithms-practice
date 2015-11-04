#include<string.h>
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    string s;
    int dp[100]={0},n,chk[256]={0},prev[256][100]={0,0},i,j,k;
    printf("Enter String & K\n");
    cin >> s;
    scanf("%d",&k);
    dp[0]=1;
    for(i=1;i<=s.length();i++)
    {
        if(i>=k)
            j=k;
        else
            j=i;
        for(;j>=1;j--)
        {
            if(chk[s[i-1]]==0)
            {
                dp[j]+=dp[j-1];
                prev[s[i-1]][j]=dp[j-1];
            }
            else
            {
                dp[j]+=dp[j-1] - prev[s[i-1]][j];   //here
                if(j!=1)
                prev[s[i-1]][j]=dp[j-1] - prev[s[i-1]][j];  //here
                else
                prev[s[i-1]][j]=0;
            //cout << dp[j] << "j=" <<j << endl;

            }
         }
        chk[s[i-1]]=1;
    }
    printf("%d\n",dp[k]);
    return 0;
}
