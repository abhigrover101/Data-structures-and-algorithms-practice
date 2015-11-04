#include<stdio.h>
int main()
{
	int N=0,M=0,k=0;
	scanf("%d%d",&N,&M);
	int i=0,j=0,a[N],maxl=0;
	long long int money[N],temp=0,maxm=0;
	int length[N];

	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
		money[i]=0;
		//length[i]=0;
	}

	if(a[0]<M)
	{
		length[0]=1;
		money[0]=a[0];
		temp=a[0];
	}

	for(i=1;i<N;i++)
	{
			temp=a[i]+money[i-1];

        while(temp>M)
		{
		    temp=temp-a[k];
		    k++;
		}
		if(temp<=M)
		{
			money[i]=temp;
			//length[i]=length[i-1]+1;
		}

	}

	for(i=0;i<N;i++)
		//if(maxl<=length[i])
		{
			if(maxm<money[i])
				maxm=money[i];
			//if(maxl<length[i])
				//maxm=money[i];
			//maxl=length[i];
		}

	printf("%lld\n",maxm);
	return 0;
}
