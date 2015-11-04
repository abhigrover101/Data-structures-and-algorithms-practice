#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

void permutations(string str,string data,int start,int end)
{
    int i;
    if(start==end)
    {
        cout<<data<<endl;
        return;
    }
    for(i=0;i<end;i++)
        permutations(str,data+str[i],start+1,end);
    return;
}

int main()
{
    printf("Enter String\n");
    string str,data;
    cin >> str;

    sort(str.begin(),str.end());

    permutations(str,data,0,str.length());
    return 0;
}
