#include<stdio.h>
#include<math.h>
int main()
{
    int N;
    long int i=0,a;
    double k;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%ld",&a);
        //printf("%.0lf\n",a);
        k=((double)a);

        i=ceil(log2(k)+1);
        printf("%ld\n",i);
    }
    return 0;
}
