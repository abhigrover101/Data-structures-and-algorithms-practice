#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int lower(int a[],int start,int end,int key)
{
    int mid;
    while(start<end)
    {
        mid=start+(end-start)/2;
        if(a[mid]>=key)
            end=mid;
        if(a[mid]<key)
            start=mid+1;
    }
    if(a[start]==key)
        return start;
    else
        return -1;
}

int upper(int a[],int start,int end,int key)
{
    int mid;
    while(start<end)
    {
        mid=start+(end-start+1)/2;
        if(a[mid]>key)
            end=mid-1;
        if(a[mid]<=key)
            start=mid;
    }
    if(a[start]==key)
        return start;
    return -1;
}


int main()
{
    cout << "Enter N followed by N numbers\n";
    int n;

    cin >> n;
    int a[n];
    int i,T;
    int left,right;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    cout << "Enter T\n";
    cin >> T;
    left=lower(a,0,n-1,T);
    right=upper(a,0,n-1,T);
    //cout<<left;
    if(left==-1)
    {
        cout<<"0\n";
        return 0;
    }
    else
        cout<<right-left+1<<endl;

    return 0;
}
