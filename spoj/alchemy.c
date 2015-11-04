#include<stdio.h>
int main()
{
	while(1)
	{
		double i,w,ratio;
		scanf("%lf%lf",&i,&w);
		if(i==-1 && w==-1)
			break;
		else 
		{
			if(i==0)
			{
				printf("N\n");
				break;	
			}
			if(1000*w==37*i)
				printf("Y\n");
			else
				printf("N\n");
		}
	}
	return 0;
}
