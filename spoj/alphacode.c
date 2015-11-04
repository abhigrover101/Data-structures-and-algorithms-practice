#include<stdio.h>
#include<string.h>
int main()
{
	char alpha[5010];
	long int f[5010],i=0;
	f[0]=1;
	f[1]=1;
	while(1)
	{
		scanf("%s",alpha);
		if(strcmp(alpha,"0")==0)
			break;
		int len=strlen(alpha);
		for(i=1;i<len;i++)
		{
			if(alpha[i-1]=='0' && alpha[i]=='0')
			{
				f[i]=0;
				break;
			}
			else if(alpha[i]=='0' && alpha[i-1]<='2')
			{
				f[i+1]=f[i-1];
				f[i]=f[i-1];
			}
			else if(alpha[i]=='0' && alpha[i-1]>'2')
			{
				f[i]=0;
				break;
			}
			else if(alpha[i-1]=='0')
				f[i+1]=f[i];
			else if(alpha[i]<='6' && alpha[i-1]<='2')
				f[i+1]=f[i]+f[i-1];
			else if(alpha[i]>='1' && alpha[i]<='9')
				f[i+1]=f[i];
		}
		printf("%ld\n",f[i]);
	}
	return 0;
}
