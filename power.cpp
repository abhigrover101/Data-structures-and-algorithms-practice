#include<iostream>
using namespace std;

    int power(int x,int n)
    {
        int ans=1;
        while(n>0)
        {
            if(n%2)
                ans=ans*x;
            x=x*x;
            n=n>>1;
        }
        return ans;
    }

int main()
{
    int x,n;
    cout << "enter number and its power\n";
    cin >> x;
    cin >> n;
    cout << power(x,n);
}
