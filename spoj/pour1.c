#include<stdio.h>
int gcd(int a,int b)
{
    if(a==b || b==0)
        return a;
    if(a>b)
        return gcd(a-b,b);
    else
        return gcd(a,b-a);
}

int main()
{
    int N,a,b,c,temp=0,a1,b1,c1,steps1,steps2;
    scanf("%d",&N);
    while(N--)
    {
        a1=0;b1=0;c1=0;steps1=10000;steps2=10000;
        scanf("%d%d%d",&a,&b,&c);

        if(b>a)
            {
                temp=a;
                a=b;
                b=temp;
            }
        temp=gcd(a,b);

        if(a==c || b==c)
            printf("1\n");
        else if(c>a && c>b)
            printf("-1\n");
        else if(c%temp!=0)
            printf("-1\n");
        else
        {
            {
                steps1=0;
                while(a1!=c && b1!=c)
                {
                    //printf("%d\n",a1);
                    if(a1==0)
                    {
                        a1=a;
                        steps1++;
                    }
                    else if(b1==0 && a1!=0)
                    {
                        if(a1>b)
                        {
                            a1=a1-b;
                            b1=b;
                            steps1++;
                        }
                        else
                        {
                            b1=a1;
                            a1=0;
                            steps1++;
                        }
                    }
                    else if(b1==b)
                    {
                        b1=0;
                        steps1++;
                    }
                    else if(b1!=0 && a1!=0)
                    {
                        if(a1+b1>b)
                        {
                            a1=a1-(b-b1);
                            b1=b;
                            steps1++;
                        }
                        else
                        {
                            b1=b1+a1;
                            a1=0;
                            steps1++;
                        }
                    }
                }
            }
            a1=0;b1=0;
            {
                steps2=0;
                while(b1!=c && a1!=c)
                {
                    //printf("%d\n",b1);
                    if(b1==0)
                    {
                        b1=b;
                        steps2++;
                    }
                    else if(a1==0 && b1!=0)
                    {
                        a1=b1;
                        b1=0;
                        steps2++;
                    }
                    else if(a1==a)
                    {
                        a1=0;
                        steps2++;
                    }
                    else if(a1!=0 && b1!=0)
                    {
                        if(a1+b1>a)
                        {
                            b1=b1-(a-a1);
                            a1=a;
                            steps2++;
                            //printf("%d\n",steps2);
                        }
                        else
                        {
                            a1=a1+b1;
                            b1=0;
                            steps2++;
                        }
                    }
                }
            }
            if(steps1<steps2)
                printf("%d\n",steps1);
            else
                printf("%d\n",steps2);
        }
    }
    return 0;
}
