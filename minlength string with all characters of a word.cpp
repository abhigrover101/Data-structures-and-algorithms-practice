#include<cstdio>
#include<string.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
    string a,b,result="";
    int count[256]={0},l[256]={0},i,flag=0,c=0,start,minlen=10000;
    printf("Enter 1st string\n");
    getline(cin,a);
    printf("Enter word\n");
    cin >> b;

    for(i=0;i<b.length();i++)
        count[b[i]]++;
    for(i=0;i<a.length();i++)
    {
        if(c>=b.length())
        {
            flag=1;
            if(result.length()<minlen)
            {
                minlen=result.length();
                start=i-minlen;
            }
        }
        else
            flag=0;

        if(flag==0 && count[a[i]]>=1 && l[a[i]] < count[a[i]])
        {
            result=result+a[i];
            l[a[i]]++;
            c++;
        }
        else if(flag==0 && count[a[i]]>=1 && l[a[i]] >= count[a[i]])
        {
            result=result+a[i];
            l[a[i]]++;
        }
        else if(flag==0)
        {
            result=result + a[i];
        }
        else if(flag==1 && result[0]==a[i])
        {
            l[a[i]]++;
            result=result+a[i];
            while(flag!=0)
            {
                if(l[result[0]]>count[result[0]] || l[result[0]]==0)
                {
                    if(l[result[0]]!=0)
                        l[result[0]]--;
                    result.erase(0,1);
                }
                else if(l[result[0]]==count[result[0]])
                {
                    flag=0;
                    c=b.length();
                }
                else
                    flag=0;
            }
        }
        else if(flag==1)
        {
            if(count[a[i]]>=1)
                l[a[i]]++;
            result=result+a[i];
        }
    }
    cout << start << endl;
    for(i=start;i<=minlen+start;i++)
        printf("%c",a[i]);
    cout<<endl;
    //scanf("%[^\n]",a[1000]);
    return 0;
}
