#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

void nextpermut(string &s)
{
    int i,first=s.length()-1,second=s.length()-1,min=10;
    for(i=s.length()-2;i>=0;i--)
    {
        if(s[i]<s[i+1])
        {
            first=i;
            break;
        }
    }
    min=10;
    for(i=first+1;i<s.length();i++)
    {
        if(s[i]-s[first]>0 && s[i]-s[first] < min)
        {
            second=i;
            min=s[i]-s[first];
        }
    }

    char temp=s[first];
    s[first]=s[second];
    s[second]=temp;

    reverse(s.begin()+first+1,s.end());
    cout<<s;
    return;
}


int main()
{
    string s;
    cin>>s;
    nextpermut(s);
    return 0;
}
