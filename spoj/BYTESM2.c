#include<stdio.h>
int main()
{
    int T,h,w,a[101][101],ans[101][101],i,j,max;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&h,&w);
        for(i=0;i<h;i++)
            for(j=0;j<w;j++)
                scanf("%d",&a[i][j]);

        for(i=0;i<h;i++)
            for(j=0;j<w;j++)
            {
                max=a[i][j];
                if(i-1>=0 && j-1>=0 && max < a[i][j]+a[i-1][j-1])
                    max=a[i][j]+ans[i-1][j-1];
                if(max < a[i][j]+ans[i-1][j] && i-1 >=0)
                    max=a[i][j]+ans[i-1][j];
                if(max < a[i][j]+ans[i-1][j+1] && i-1>=0 && j+1<w)
                    max=a[i][j]+ans[i-1][j+1];
                ans[i][j]=max;
            }
            if(h-1 >=0)
                max=ans[h-1][0];
        for(i=0;i<w;i++)
             if (max < ans[h-1][i])
                max=ans[h-1][i];
        printf("%d\n",max);
    }
    return 0;
}
