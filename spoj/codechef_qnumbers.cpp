#include<cstdio>
using namespace std;


int main()
{
    int q,t,i;
    long long int n,k,smaller,larger,count;
    scanf("%lld%d",&n,&q);
    while(q--)
    {
        count=0;
        scanf("%d%lld",&t,&k);
        if(t==1)
        {
            if(n<k)
            {
                smaller=n;
                larger=k;
            }
            else
            {
                smaller=k;
                larger=n;
            }
            for(i=1;i*i<=smaller;i++)
            {
                if(smaller%i==0 && larger%i==0)
                {
                    count++;
                    if((larger%(smaller/i))==0 && (smaller/i)!=i)
                    {
                        count++;
                    }
                }
            }
            printf("%lld\n",count);
        }
        if(t==2)
        {
            for(i=1;i*i<=n && i*k<=n;i++)
            {
                if(n%i==0)
                {
                    if(i%k==0)
                        count++;
                    if((n/i)%k==0 && (n/i)!=i)
                        count++;
                }
            }
            printf("%lld\n",count);
        }
        if(t==3)
        {
            for(i=1;i*i<=n;i++)
            {
                if(n%i==0)
                {
                    if(i%k!=0)
                        count++;
                    if((n/i)%k!=0 && (n/i)!=i)
                        count++;
                }
            }
            printf("%lld\n",count);
        }
    }
    return 0;
}
