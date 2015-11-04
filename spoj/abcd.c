#include<stdio.h>
int main()
{
	int k=0,i=0,j=0;
	int flag[4]={0},N=0;
	char junk;
	scanf("%d",&N);
	scanf("%c",&junk);
	char letters[2][500000];
	for(i=0;i<2*N;i++)
		scanf("%c",&letters[0][i]);
	for(i=0;i<N;i++)
	{

		flag[letters[0][2*i]-'A']=1;
		flag[letters[0][2*i+1]-'A']=1;
		if(i==0)
		{
		for(j=0;j<4;j++)
		{
			if(flag[j]!=1)
			{
				letters[1][0]=(j+'A');
				flag[j]=1;
				break;
			}
		}
		for(j=0;j<4;j++)
		{
			if(flag[j]!=1 && letters[1][0]!=(j+'A'))
			{
				letters[1][1]=(j+'A');
				flag[j]=1;
				break;
			}
		}
		}
		if(i!=0)
		{
		for(j=0;j<4;j++)
		{
			if(flag[j]!=1 && letters[1][2*i-1]!=(j+'A'))
			{
				letters[1][2*i]=(j+'A');
				flag[j]=1;
				break;
			}
		}
		for(j=0;j<4;j++)
		{
			if(flag[j]!=1 && letters[1][2*i]!=(j+'A'))
			{
				letters[1][2*i+1]=(j+'A');
				flag[j]=1;
				break;
			}
		}
		}

		for(j=0;j<4;j++)
			flag[j]=0;

	}
	for(i=0;i<2*N;i++)
	{
		printf("%c",letters[1][i]);
	}
	printf("\n");
	return 0;
}
