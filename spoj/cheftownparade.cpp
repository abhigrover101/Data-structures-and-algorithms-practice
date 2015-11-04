#include<cstdio>
#include<list>
using namespace std;

int main()
{
    int n,w,i,count=0,temp,m1,m2,back;
    list <int> maxq,minq;
    scanf("%d%d",&n,&w);
    int a[400010];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(i=0;i<w;i++)
    {
        while(!maxq.empty() && a[i]>=a[maxq.back()])
            maxq.pop_back();
        maxq.push_back(i);

        while(!minq.empty() && a[i]<=a[minq.back()])
            minq.pop_back();
        minq.push_back(i);
    }
    if(a[maxq.front()]-a[minq.front()]==w-1)
            count++;

    for(i=w;i<n;i++)
    {
        while(!maxq.empty() && a[i] >= a[maxq.back()])
        {
                maxq.pop_back();
        }
        maxq.push_back(i);

        while(!maxq.empty() && maxq.front()<=i-w)
            maxq.pop_front();


        while(!minq.empty() && a[i]<=a[minq.back()])
            minq.pop_back();


        while(!minq.empty() && minq.front()<=i-w)
        {
                minq.pop_front();
        }

        minq.push_back(i);
        //printf("%d %d\n",maxq.front(),minq.front());
        if((a[maxq.front()]-a[minq.front()]==w-1))
            count++;
    }
    printf("%d\n",count);
    return 0;
}
