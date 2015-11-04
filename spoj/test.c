#include<stdio.h>
main()
{
   long long int q, n,p;
   scanf("%lld",&p);
   for(q=0;q<p;q++)
   {
       scanf("%lld",&n);
       printf("%lld\n",n*(n+2)*(2*n+1)/8);

   }

   return 0;
}
