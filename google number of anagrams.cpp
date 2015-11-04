#include<cstdio>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;
int main()
{
    printf("Enter number of strings followed by strings of equal length\n");
    int d,i,count=0;
    string s,prev="";
    cin >> d;
    vector <string> list;
    for(i=0;i<d;i++)
    {
        cin>>s;
        list.push_back(s);
    }

    for(i=0;i<list.size();i++)
        sort(list[i].begin(),list[i].end());

    sort(list.begin(),list.end());
    for(i=0;i<list.size();i++)
    {
        cout << list[i]<<endl;
        if(list[i]!=prev)
        {

            count++;
            prev=list[i];
        }
    }
    cout << count;
    return 0;
}
