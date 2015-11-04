#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    priority_queue <int, vector<int>, less <int> > max;
    priority_queue <int, vector<int>, greater <int> > min;
    int N,sizemax=0,sizemin=0,ele=0,temp1=0,temp2=0;
    scanf("%d",&N);
    scanf("%d",&ele);
    max.push(ele);
    N--;
    printf("%d\n",max.top());
    while(N--)
    {
        scanf("%d",&ele);
        if(max.size()==min.size())
        {
            if(ele>min.top())
            {
                temp1=ele;
                temp2=min.top();
                min.pop();
                min.push(temp1);
                max.push(temp2);
            }
            else
            {
                max.push(ele);
            }
        }
        else if(max.size()>min.size())
        {
            if(ele < max.top())
            {
                temp1=max.top();
                temp2=ele;
                max.pop();
                min.push(temp1);
                max.push(temp2);
            }
            else
            {
                min.push(ele);
            }
        }
        printf("%d\n",max.top());
    }
    return 0;
}
