#include<vector>
#include<utility>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<algorithm>

using namespace std;

void mfl(vector<string>& input)
{
    int i,j,k=0;
    vector < pair <int,char> > inp;

    string ans="";

    for(j=0;j<input.size();j++)
    {
        for(i=0;i<256;i++)
        {
            inp.push_back(make_pair(0,i));
        }
        for(i=0;i<input[j].length();i++)
        {
            if(input[j][i]!=' ' && input[j][i]>='A' && input[j][i]<='z')
                inp[input[j][i]].first++;
        }

        sort(inp.begin(),inp.end(),greater< pair <int,char> >());
        k=0;
        ans=inp[0].second;
        while(inp[k].first==inp[k+1].first)
        {
            ans+=inp[k+1].second;
            k++;
        }
        sort(ans.begin(),ans.end());
        cout<<ans<<" "<<inp[0].first<<endl;
        ans="";
        inp.clear();
    }
    return;
}

int main()
{
    cout<<"Enter number of lines:"<<endl;
    int n,i;
    vector<string> input;


    string in,c;
    cin>>n;
    getline(cin,c);
    cout<<"Enter lines one by one:-"<<endl;
    for(i=0;i<n;i++)
    {
        getline(cin,in);
        input.push_back(in);
    }
    mfl(input);
    return 0;
    //sort(inp.begin(),inp.end(),greater< pair <int,char> >());
    //cout<<inp[0].second;
}
