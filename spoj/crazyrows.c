#include<stdio.h>
#include<string.h>
int main()
{
    int N,n,l,a[10],replacee=0,replaceeid=0,stored=0,count=0,i=0,j=0,sum=0,row=0,t=0;
    char temp[10];
    scanf("%d",&N);
    for(l=1;l<=N;l++)
    {
        count=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",temp);
            sum=0;
            for(j=0;j<strlen(temp);j++)
            {
                //scanf("%c",&temp);
                if(temp[j]=='1')
                    sum=sum+(1<<(j));
            }
            a[i]=sum;
        }

        for(i=0;i<n;i++)
        {
            replaceeid=i;
            replacee=a[i];
            row=((1<<(i+1))-1);
            if(a[i]>row)
            {
                stored=a[i];
                for(j=i+1;j<n;j++)
                {
                    if(a[j]<=row)
                    {
                        replacee=a[j];
                        replaceeid=j;
                        break;
                    }
                    else
                    {
                        t=a[j];
                        a[j]=stored;
                        stored=t;
                    }
                }
                a[i]=replacee;
                a[replaceeid]=stored;
                count=count+(replaceeid-i);
            }
        }
        printf("Case #%d: %d\n",l,count);
    }
    return 0;
}
