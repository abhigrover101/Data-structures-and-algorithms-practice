#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char c,str1[10],str2[10],n1[11],n2[11],temp[4],ans[10];
    int num[128],map[10],i;
    int sum;
    int index;
    memset(num,'\0',sizeof(num));
    memset(temp,'\0',sizeof(temp));
    memset(map,'\0',sizeof(map));
    num[63]=0;
    num[10]=1;
    num[93]=2;
    num[79]=3;
    num[106]=4;
    num[119]=6;
    num[11]=7;
    num[127]=8;
    num[107]=9;
    map[0]=63;
    map[1]=10;
    map[2]=93;
    map[3]=79;
    map[4]=106;
    map[6]=119;
    map[7]=11;
    map[8]=127;
    map[9]=107;
    while(1)
    {
        memset(n1,'\0',sizeof(n1));
        memset(n2,'\0',sizeof(n2));
        memset(ans,'\0',sizeof(ans));
        sum=0;
        index=0;
        scanf("%[^+]+",str1);
        //printf("%s\n",str1);
        if(strcmp(str1,"BYE")==0)
            break;
        //printf("abcd");
        scanf("%[^=]=%*c",str2);
        //printf("%s\n",str2);
        for(i=1;i<=strlen(str1)/3;i++)
        {
            temp[0]=str1[3*i-3];
            temp[1]=str1[3*i-2];
            temp[2]=str1[3*i-1];
            temp[3]='\0';
            index=atoi(temp);
            //printf("%d\n",num[index]);
            n1[i-1]=num[index]+'0';
        }
        n1[i]='\0';
        //printf("%d\n",atoi(n1));
        for(i=1;i<=strlen(str2)/3;i++)
        {
            temp[0]=str2[3*i-3];
            temp[1]=str2[3*i-2];
            temp[2]=str2[3*i-1];
            temp[3]='\0';
            index=atoi(temp);
            n2[i-1]=num[index]+'0';
        }

        sum=atoi(n1)+atoi(n2);
        itoa(sum,ans,10);
        printf("%s+%s=",str1,str2);
        for(i=0;i<strlen(ans);i++)
        {
            if(map[ans[i]-'0']<10)
                printf("00%d",map[ans[i]-'0']);
            else if(map[ans[i]-'0']<100)
                printf("0%d",map[ans[i]-'0']);
            else
                printf("%d",map[ans[i]-'0']);
        }
        printf("\n");
    }
    return 0;
}
