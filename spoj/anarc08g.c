#include<stdio.h>
int main()
{
	int count=1;
	while(1)
	{
		int N=0,i=0,j=0,sum=0,total=0;
		scanf("%d",&N);
		if(N==0)
			return 0;
		int a[N][N],bal[N];
		for(i=0;i<N;i++)
			bal[i]=0;
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
			{
				scanf("%d",&a[i][j]);
				bal[i]-=a[i][j];
				bal[j]+=a[i][j];
				total+=a[i][j];
			}

		for(i=0;i<N;i++)
			if(bal[i]>=0)
				sum+=bal[i];
		printf("%d. %d %d\n",count,total,sum);
		count++;
	}
}
