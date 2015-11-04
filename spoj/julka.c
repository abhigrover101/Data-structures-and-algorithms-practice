#include<stdio.h>
int main()
{
	long long int i=10,total=0,diff=0;
	while(i--)
	{
		scanf("%lld%lld",&total,&diff);
		printf("%lld\n%lld\n",(total+diff)/2,(total-diff)/2);
	}
	return 0;
}
