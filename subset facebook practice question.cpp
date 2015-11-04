#include<iostream>
#include<vector>
using namespace std;

void subset(vector<int> &ans,int sum)
{
    int i;
    if(sum<0)
        return;
    if(sum==0)
    {
        for(i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout << endl;
    }

    for(i=1;i<=sum;i++)
    {
        ans.push_back(i);
        subset(ans,sum-i);
        ans.pop_back();
    }
    return;
}


int main()
{
    //cout <<"Enter N\n";
    //int n;
    //cin >>n;
    //int a[n];
    //for(i=0;i<n;i++)
    //    cin>>a[i];
    int T;
    cout << "Enter sum T\n";
    cin >>T;
    vector<int> ans;
    //int ans[];
    subset(ans,T);
}
