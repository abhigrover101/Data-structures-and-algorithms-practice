#include<stdio.h>
#include<string.h>
int dp[6100][6100];
/*int palindrome(char s[7000],int l,int r)
{
	int max1,max2;
	if(r-l<=0)
		return 0;
	if(s[l]==s[r])
		return palindrome(s,l+1,r-1);
	else if(s[l]!=s[r])
	{
		max1=palindrome(s,l,r-1)+1;
		max2=palindrome(s,l+1,r)+1;
		if(max1<max2)
			return max1;
		else
			return max2;
	}
}*/

int main()
{
	int t,len,i,j,max1,max2,k,l=0,m=0;
	char s[6100];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		len=strlen(s)-1;
		k=0;
		/*for(i=0;i<=len;i++)
			for(j=0;j<=len;j++)
				if(i<=j)
					dp[i][j]=0;*/
		i=len;
		while(i--)
		{
			l=0;
			m=1+k;
			k++;
			while(m<=len)
			{
				if(s[l]==s[m])
					dp[l][m]=dp[l+1][m-1];
				else
				{
					max1=dp[l+1][m]+1;
					max2=dp[l][m-1]+1;
					if(max1<max2)
						dp[l][m]=max1;
					else
						dp[l][m]=max2;
				}
				l++;
				m++;
			}
		}
		printf("%d\n",dp[0][len]);
	}
	return 0;
}
