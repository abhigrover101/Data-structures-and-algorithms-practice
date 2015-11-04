#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    string s;
    cin>>s;
    next_permutation(s.begin(),s.end());
    cout<<s;
    return 0;
}
