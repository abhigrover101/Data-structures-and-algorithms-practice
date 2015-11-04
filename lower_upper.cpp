#include<cstdio>
#include<iostream>
using namespace std;

int upper_bound(int *a,int left,int right,int x)
{
    int mid=left+(right-left+1)/2;

    if(right-left==0)
        return a[mid];
    if(a[mid]==x)
        return x;
    if(a[mid]==x && mid!=0 && a[mid-1]<a[mid])
        return a[mid-1];
    else if(a[mid]==x && mid!=0)
        upper_bound(a,left,mid-1,x);
    else if(a[mid] > x)
    {
        upper_bound(a,left,mid-1,x);
    }
    else if(a[mid]<x)
        upper_bound(a,mid,right,x);
}

int lower_bound(int *a,int left,int right,int x)
{
    int mid=left+(right-left)/2;

    if(right-left==0)
        return a[mid];
    //if(a[mid]==x)
    //    return x;
    if(a[mid]==x && mid!=right && a[mid]<a[mid+1])
        return a[mid+1];
    else if(a[mid]==x && mid!=right)
        lower_bound(a,mid+1,right,x);
    else if(a[mid] > x)
    {
        lower_bound(a,left,mid,x);
    }
    else if(a[mid]<x)
        lower_bound(a,mid+1,right,x);
}

int main()
{
    int a[100]={0};
    cout << "Enter N nd numbers\n";
    int n;
    cin >>n;
    int i=0;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    cout<< "Select 1.lower bound or 2.upper bound\n";
    cin >> i;
    int temp;
    cout << "Enter number to find\n";
    cin >> temp;
    if(i==1)
    {
        cout << "LB = " <<lower_bound(a,0,n-1,temp);
    }
    else
        cout << "UB = " <<upper_bound(a,0,n-1,temp);

}
