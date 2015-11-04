#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    long long int T,N,a,b,c,i=0;
    long long int f[200010], sum=0,ele=0;
    scanf("%lld",&T);
    f[0]=0;
    f[1]=1;
    while(T--)
    {
    priority_queue <int, vector<int>, less <int> > max;
    priority_queue <int, vector<int>, greater <int> > min;
    sum=1;
    scanf("%lld%lld%lld%lld",&a,&b,&c,&N);
    max.push(1);
    for(i=2;i<=N;i++)
    {
        ele=(a*max.top()+ (b*i) + c)%1000000007;
        sum+=ele;
        if(max.size()==min.size())
        {
            if(ele>min.top())
            {
                max.push(min.top());
                min.pop();
                min.push(ele);

            }
            else
            {
                max.push(ele);
            }
        }
        else
        {
            if(ele < max.top())
            {
                min.push(max.top());
                max.pop();
                max.push(ele);
            }
            else
            {
                min.push(ele);
            }
        }
    }
    printf("%lld\n",sum);
    }
    return 0;
}

