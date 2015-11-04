#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;

bool mycompare(int i,int j)
{
    stringstream ss1;
    ss1<<i;
    stringstream ss2;
    ss2<<j;
    string xy=ss1.str()+ss2.str();
    string yx=ss2.str()+ss1.str();
    if(xy>yx)
        return true;
    else
        return false;
    /*int len1=1,len2=1,t1=i,t2=j;
    while(t1/10)
    {
        t1=t1/10;
        len1=len1*10;
    }
    while(t2/10)
    {
        t2=t2/10;
        len2=len2*10;
    }

    if()*/
}



int main()
{
    int a[]={21,9,23};
    int i;
    sort(a,a+3,mycompare);
    for(i=0;i<3;i++)
        cout<<a[i];
}
