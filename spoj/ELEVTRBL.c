#include<stdio.h>
//int gcd(int a,int b)
//{
//    if(b==0)
//        return a;
//    else
//        return gcd(b,a%b);
//}

int main()
{
    int f,s,g,u,d,count=0,n1,n2,c;
    scanf("%d%d%d%d%d",&f,&s,&g,&u,&d);
    int dis=abs(g-s);
    n1=u;
    n2=d;
    int t=0;

while (n2 != 0) { // not equal
         c = n1 % n2; // modulus operator
         n1 = n2; // assignment
         n2 = c;
    }

    d=-1*d;
    if((dis%n1!=0 && n1!=0) || n1==0)
    {
       printf("use the stairs\n");
       return 0;
    }
    else if(s<g && u!=0 && dis%u==0)
        printf("%d\n",dis/u);
    else if(s>g && d!=0 && dis%abs(d)==0)
        printf("%d\n",dis/abs(d));
    else
    {
        while(s!=g)
        {
            t=0;
            if(s<g && s+u<=f)
                {
                    if(u!=0)
                        t=(g-s)/u;
                    if(t==0)
                        t=1;
                    s+=u*t;
                    count=count+t;
                }
            else if(s>g && s+d>=1)
                {
                    if(d!=0)
                        t=(g-s)/abs(d);
                    if(t==0)
                        t=1;
                    s+=d*t;
                    count=count+t;
                }
            else if(s+u>f)
                {
                    s+=d;
                    count++;
                }
            else if(s+d<1)
                {
                    s+=u;
                    count++;
                }
        }
        printf("%d\n",count);
    }

    return 0;
}
