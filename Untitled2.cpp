#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int myints[] = {10,20,30,30,20,10,10,20};
    vector<int> v(myints,myints+8);
      sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30
    cout << int(lower_bound(v.begin(),v.end(),25)-v.begin());

}
