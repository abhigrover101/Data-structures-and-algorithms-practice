#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int d,i;
    cout << "Enter number of digits\n" << endl;
    cin >> d;
    long long int zero[1000]={0};
    long long int nz[1000]={0};
    zero[1]=0;
    nz[1]=9;

    for(i=2;i<=d;i++)
    {
        zero[i]=(nz[i-1]+nz[i-2])%1000000007;
        nz[i]=((9*(nz[i-1]+zero[i-1]))%1000000007);
        if(nz[i]<0)
            nz[i]=nz[i]+1000000007;
        if(zero[i]<0)
            zero[i]=zero[i]+1000000007;
    }

    cout <<"Speacial Numbers are: " <<(zero[d]+nz[d])%1000000007<<endl;
}
