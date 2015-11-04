#include<stdio.h>
#include<string.h>
int main()
{
    char str1[101][20],str2[20],str3[101][20],temp[20];
    int T,N,k,i,j,flag;
    scanf("%d",&T);
    while(T--)
    {
        i=0;
        j=0;
        k=0;
        flag=0;
        scanf("%d",&N);
        while(N--)
        {
            scanf("%s",temp);
            if(temp[0]=='#' && flag==0)
            {
                strcpy(str1[i],temp);
                i++;
            }
            else if(temp[0]!='#' && flag==0)
            {
                strcpy(str2,temp);
                flag=1;
            }
            else if(temp[0]=='#' && flag==1)
            {
                strcpy(str3[j],temp);
                j++;
            }
        }
        for(k=0;k<j;k++)
            printf("%s ",str3[k]);

        if(flag==1)
            printf("%s ",str2);

        for(k=0;k<i;k++)
            printf("%s ",str1[k]);
    }
    return 0;
}
