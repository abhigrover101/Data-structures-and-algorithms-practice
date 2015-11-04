#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

void palindrome(string s)
{
    int maxlen=0,start,i,l,r;
    int n=s.length();
    for(i=1;i<n;i++)
    {
        l=i-1;
        r=i;
        while(l>=0 && r < n && s[l]==s[r])
        {
            if(maxlen< r-l+1)
            {
                start=l;
                maxlen=r-l+1;
            }
            l--;
            r++;
        }

        l=i-1;
        r=i+1;
        while(l>=0 && r < n && s[l]==s[r])
        {
            if(maxlen< r-l+1)
            {
                start=l;
                maxlen=r-l+1;
            }
            l--;
            r++;
        }
    }

    cout <<"the longest palindromic substring "<< s.substr(start,maxlen) << " is of length " << maxlen << endl;
    return;
}

int main()
{
    string s;
    printf("Enter String\n");
    cin >>s;
    palindrome(s);
    return 0;
    //cout << palindrome(s) << endl;
}
