#include<stdio.h>
#include<math.h>
int main()
{
    int T;
    scanf("%d",&T);
    int c,b,x,y,digit;
    int ans;
    while(T--)
    {
        ans=0;
        digit=0;
        scanf("%d%d%d%d",&c,&b,&x,&y);
        while(x>=1 || y >=1)
        {
            ans=ans+(((x%b + y%b)%b)*pow(b,digit));
            //printf("%d ",((x%b + y%b)%b));
            digit++;
            x=x/b;
            y=y/b;

        }
        printf("%d %d\n",c,ans);
    }
}
