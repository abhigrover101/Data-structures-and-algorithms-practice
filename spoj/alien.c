#include<stdio.h>
int main()
{
	int t=0,i=0,j=0,stmax=0,countmax=0,st=0;
	scanf("%d",&t);
	int at=0,bt=0,count=0,start=0;;
	while(t--)
	{
		stmax=0;
		count=0;
		countmax=0;
		start=0;
		i=0;
		scanf("%d%d",&at,&bt);
		int humans[at];
		for(i=0;i<at;i++)
			scanf("%d",&humans[i]);
		for(i=0;i<at;i++)
		{
			while(1)
			{
				if(count+humans[i]>bt && start<at)
				{
					if(start==i)
					{
						//st=0;
						start++;
						break;
					}
					count=count-humans[start];
					start++;
					//st--;
				}
				else
				{
					count=count+humans[i];
					//st++;
					if(stmax<=(i-start+1))
					{
						if(stmax==(i-start+1) && (count<countmax))
							countmax=count;
						else if(stmax<(i-start+1))
						{
							stmax=i-start+1;
							countmax=count;
						}
					}
					break;
				}
			}
		}
		printf("%d %d\n",countmax,stmax);
	}
	return 0;
}
