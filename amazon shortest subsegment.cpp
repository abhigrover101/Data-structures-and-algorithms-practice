#include<cstdio>
#include<string.h>
#include<map>
#include<iostream>
#include <ctype.h>
#include<algorithm>
using namespace std;

int main()
{

    string s[100],temp="",words[100];
    int i=0,k,j,flag=0;
    char c;
    map <string,int> chk,hm;
    while(c!='\n')
    {
        cin >> s[i];
        transform(s[i].begin(),s[i].end(),s[i].begin(),::tolower);
        //cout<<s[i];
        hm[s[i]]=0;
        i++;
        scanf("%c",&c);
    }
    int n;
    scanf("%d",&n);
    for(j=0;j<n;j++)
    {
        cin >> words[j];
        transform(words[j].begin(),words[j].end(),words[j].begin(),::tolower);
        chk[words[j]]=1;
    }

    int len=i-1;
    int start=0,dummystart=0;
    int end=i-1;
    int count=0;
    int mi=100000000;
    for(i=0;i<len;i++)
    {
        if(c<n)
            flag=0;
        else if(count==n)
            {
                if((i-dummystart-1)<mi)
                {
                    mi=i-dummystart-1;
                    start=dummystart;
                    end=i-1;
                }
                flag=1;
            }

        if(flag==0 && chk[s[i]]==1)
        {

            if(hm[s[i]]==0)
                count++;
            if(count==1)
                dummystart=i;
            hm[s[i]]++;

        }
        else if(flag==1 && chk[s[i]]==1 && s[dummystart]==s[i])
        {
            j=dummystart;
            hm[s[i]]++;
            while(flag!=0)
            {
                if(chk[s[j]]==1 && hm[s[j]]>1)
                {
                    //count--;
                    hm[s[j]]--;
                    //count--;
                }
                else if(chk[s[j]]==1 && hm[s[j]]==1)
                {
                    flag=0;
                }
                j++;
            }
            while(chk[s[j]]!=1)
                j++;
            dummystart=j;
            //cout << "here"<<dummystart<<"hmm"<<i;

            //hm[s[i]]++;
            //count++;
        }
         //cout << count <<endl;
    }

    cout << start << " " << end <<endl;



}
