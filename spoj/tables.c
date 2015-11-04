#include<stdio.h>
int main()
{
    int n,k,s,i=0,temp=0,count=0,bucket=0,flag=0;

    scanf("%d%d%d",&n,&k,&s);

    int a[1005];
    for(i=0;i<1005;i++)
        a[i]=0;

    for(i=0;i<n;i++)
    {
        scanf("%d",&temp);
        a[temp]=a[temp]+1;
    }

    for(i=1004;i>=0;i--)
    {
        while(1)
        {
            if(a[i]>0 && count<(k*s))
            {
                count=count+i;
                bucket++;
                a[i]=a[i]-1;
            }
            else
	    {
		if(count>=(k*s))
			flag=1;
                break;
	    }
        }
	if(flag==1)
		break;
    }
    printf("%d\n",bucket);
    return 0;
}
