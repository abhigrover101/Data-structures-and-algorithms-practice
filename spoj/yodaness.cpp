#include<stdio.h>
#include<iostream>
#include<map>
#include<string.h>
using namespace std;

map<string,int> mymap;
//char final[30001][25];
long long int count;
int k[30001];

void merge_sort(int *a,int start1,int end1,int start2,int end2)
{
    //printf("%d %d\n",start1,end1);
    //printf("%d %d\n",start2,end2);

    int i,j,aa,b;
    if(end1-start1>=1)
        merge_sort(&a[0],start1,(start1+end1)/2,(start1+end1)/2+1,end1);
    if(end2-start2>=1)
        merge_sort(&a[0],start2,(start2+end2)/2,(start2+end2)/2+1,end2);
    i=start1;
    j=start2;
    aa=start1;
    b=end2;
    while(i<=end1 || j<=end2)
    {
        if(a[i]<a[j] && i<=end1 && j<=end2)
        {
            k[start1++]=a[i];
            i++;
        }
        else if(a[i]>a[j] && i<=end1 && j<=end2)
        {
            k[start1++]=a[j];
            count=count+end1-i+1;
            j++;
        }
        else if(i>end1)
        {
            k[start1++]=a[j];
            j++;
        }
        else if(j>end2)
        {
            k[start1++]=a[i];
            i++;
        }
    }
    for(i=aa;i<=b;i++)
        a[i]=k[i];
    return;
}

/*void merge_sort(char a[][25],int start1,int end1,int start2,int end2)
{

    int i,j,aa,b;
    if(end1-start1>=1)
        merge_sort(&a[0],start1,(start1+end1)/2,(start1+end1)/2+1,end1);
    if(end2-start2>=1)
        merge_sort(&a[0],start2,(start2+end2)/2,(start2+end2)/2+1,end2);
    i=start1;
    j=start2;
    aa=start1;
    b=end2;

    while(i<=end1)
    {
        if(mymap[a[i]]<mymap[a[j]] && i<=end1 && j<=end2)
        {
            //strcpy(final[start1++],a[i]);
            //k[start1++]=a[i];
            i++;
        }
        else if(mymap[a[i]]>mymap[a[j]] && i<=end1 && j<=end2)
        {
            //strcpy(final[start1++],a[j]);
            //k[start1++]=a[j];
            count=count+1;
            j++;
        }
        else if(i>end1)
        {
            //strcpy(final[start1++],a[j]);
            //k[start1++]=a[j];
            //j++;
            //i=start1;
            j=end2+1;
        }
        else if(j>end2 && i<=end1)
        {
            //strcpy(final[start1++],a[i]);
            //k[start1++]=a[i];
            //i++;
            j=start2;
            i++;
        }
    }

    return;
}*/

int main()
{
    int T;
    scanf("%d",&T);
    int N,i;
    int a[30001];
    char temp[25];
    while(T--)
    {
        count=0;
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            scanf("%s",temp);
            mymap[temp]=i;
            //printf("%s",temp);
        }
        for(i=0;i<N;i++)
        {
            scanf("%s",temp);
            a[i]=mymap[temp];
        }
        //scanf("%*c");

        merge_sort(&a[0],0,(N-1)/2,(N+1)/2,N-1);
        printf("%lld\n",count);
    }


    return 0;
}

