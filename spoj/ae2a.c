#include<stdio.h>
#include<math.h>
int fac(int x)
{
	int factorial=1;
	while(x>0)
	{
		factorial=factorial*x;
		x--;
	}
	return factorial;
}

int main()
{
	int t;
	scanf("%d",&t);
	int n,k;
	while(t--)
	{
		int a,b,c,d,p;
		scanf("%d%d",&n,&k);
		a=fac(k-1);
		b=fac(n-1);
		c=fac(k-n);
		d=a/(b*c);
		p=(d*100)/pow(6,n);
		printf("%d\n",p);
	}
	return 0;
}

