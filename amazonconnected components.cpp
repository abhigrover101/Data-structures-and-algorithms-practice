#include<cstdio>
#include<stack>
#include<string.h>
using namespace std;
int a[1010][1010],chk[1010][1010];
void dfs(int m,int k,int n )
{
    //printf("%d %d\n",m,n);
    int i,j;
    stack< pair <int, int> > st;
    st.push(make_pair(m,k));
            while(!st.empty())
            {

                i=st.top().first;
                j=st.top().second;
                st.pop();
                //printf("%d %d %d %d\n",m,k,i,j);
                chk[i][j]=1;
                if(a[i][j]==1)
                {
                    if( i>0 && a[i-1][j]==1 && chk[i-1][j]!=1)
                        st.push(make_pair(i-1,j));
                    if(i>0 && a[i-1][j+1]==1 && chk[i-1][j+1]!=1)
                        st.push(make_pair(i-1,j+1));
                    if(j<n-1 && a[i][j+1]==1 && chk[i][j+1]!=1)
                        st.push(make_pair(i,j+1));
                    if(i<n-1 && j<n-1 && a[i+1][j+1]==1 && chk[i+1][j+1]!=1)
                        st.push(make_pair(i+1,j+1));
                    if(i<n-1 && a[i+1][j]==1 && chk[i+1][j]!=1)
                        st.push(make_pair(i+1,j));
                    if(i<n-1 && j>0 && a[i+1][j-1]==1 && chk[i+1][j-1]!=1)
                        st.push(make_pair(i+1,j-1));
                    if(j>0 && a[i][j-1]==1 && chk[i][j-1]!=1)
                        st.push(make_pair(i,j-1));
                    if(i>0 &&  j> 0 && a[i-1][j-1]==1 && chk[i-1][j-1]!=1)
                        st.push(make_pair(i-1,j-1));
                }
            }
            return;
}

int main()
{
    printf("Enter size of square matrix followed by NxN elements\n");
    memset(a,'\0',sizeof(a));
    memset(chk,'\0',sizeof(chk));
    int n,i,j,count=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(chk[i][j]==0 && a[i][j]==1)
            {
                dfs(i,j,n);
                count++;
            }
            //printf("chk %d %d %d\n",i,j,chk[i][j]);
        }
        printf("%d\n",count);
}
