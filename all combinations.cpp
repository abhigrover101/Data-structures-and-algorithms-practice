#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

void combinations(int n,int r,int i,string ans){
    int j;
    char temp;
    if(ans.length()==r)
    {
        cout<<ans<<endl;
        return;
    }
    for(j=i;j<n;j++)
    {
        temp=0;
        temp='0'+j;
        combinations(n,r,j+1,ans+temp);
    }
    return;
}


int main()
{
    int n,r;
    cout << "Enter maximum numbers:";
    cin>>n;
    cout << "Enter output length:";
    cin>>r;
    string ans="";
    combinations(n,r,0,ans);
    return 0;
}
