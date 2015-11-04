#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	int n,a,d,sum;
	double s;
	while(T--)
	{
		scanf("%d%d%d",&n,&a,&d);
		s=((double)n/2)*(2*a+(n-1)*d);
		sum=s;
		printf("%d\n",sum);
	}
	return 0;
}
