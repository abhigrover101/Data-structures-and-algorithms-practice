#include<iostream>
using namespace std;

int cut(int price[],int s,int n)
{
    if(n==0)
        return 0;
    if(s==0)
        return 0;
    if(s<n)
        return cut(price,s,n-1);
    else
        return max(cut(price,s-n,n)+price[n-1],cut(price,s,n-1));
}


int main()
{
    int price[100];
    int i,n;
    cout << "Enter N followed by N numbers\n";
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> price[i];
    }

    cout << cut(price,n,n)<<endl;
}
