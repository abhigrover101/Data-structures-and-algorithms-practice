#include<cstdio>
#include<stack>
#include<string.h>
using namespace std;
int main ()
{
    int n,a[100][100],i,j;
    memset(a,'\0',sizeof(a));
    printf("Enter size of square matrix\n");
    scanf("%d",&n);
    stack <int> st;
    for(i=0;i<n;i++)
    {
        st.push(i);
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    int aa,b;
    while(st.size()>1)
    {
        aa=st.top();
        st.pop();
        b=st.top();
        st.pop();
        if(a[aa][b]==1 && a[b][aa]==0)
            st.push(b);
        else if(a[b][aa]==1 && a[aa][b]==0)
            st.push(aa);

    }
    //printf("%d",st.top());
    if(st.size()==1)
    {
        aa=st.top();
        st.pop();
        for(i=0;i<n;i++)
        {
            if(a[i][aa]==1 && a[aa][i]==0 || aa==i)
                continue;
            else
            {
                printf("No celebrity\n");
                return 0;
            }
        }
        printf("Celebrity is %d\n",aa);
    }
    else
            printf("No celebrity\n");

    return 0;

}
