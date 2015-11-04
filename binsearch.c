#include<stdio.h>
int binsearch(int a[100],int first,int last)
{
	if(first==last)
		return a[first];
	if(a[(last+first)/2 +1]>=a[(first+last)/2])
		binsearch(a,(first+last)/2+1,last);
	else
		binsearch(a,first,(first+last)/2);
}

void main()
{
	int a[100]={0},i=0,k=0;
	while(1)
	{
		scanf("%d",&a[i++]);
		if(a[i-1]<0 && i>=0)
			break;
	}

	k=binsearch(a,0,i-2);
	printf("The Largest Number is %d\n",k);
}
