#include<cstdio>
#include<stdlib.h>
using namespace std;
typedef struct tree{
    int data;
    struct tree *left;
    struct tree *right;

}tree;

int find(int *in,int n,int start,int end)
{
    int mid=start + (end-start)/2;
    if(end==start && in[mid]!=n)
        return -1;
    if(in[mid]==n)
        return mid;
    else if(in[mid]<n)
        find(in,n,mid+1,end);
    else if(in[mid]>n)
        find(in,n,start,mid-1);
}

tree* construct(int *pre,int *in,int start,int end,int *c)
{
    tree *temp;
    if(start>end)
        return NULL;
    int f;
    f=find(in,pre[*c],start,end);

    if(f==-1)
    {
        return NULL;
    }
    temp=(tree *)malloc(sizeof(tree));
    temp->data=pre[*c];
    (*c)++;
    //printf("%d ",*c);
    temp->left=construct(pre,in,start,f-1,c);
    temp->right=construct(pre,in,f+1,end,c);
    return temp;
}

void print(tree *root)
{
    if(root==NULL)
        return;
    print(root->left);
    print(root->right);
    printf("%d ",root->data);
    return;
}

int main(){

    tree *root;
    int n,i;
    printf("Enter number of elements:");
    scanf("%d",&n);
    int pre[n],in[n];
    printf("Enter the preorder and inorder traversals:");
    for(i=0;i<n;i++)
        scanf("%d",&pre[i]);
    for(i=0;i<n;i++)
        scanf("%d",&in[i]);


    int start=0,end=n-1;
    int count=0;
    //root=(tree *)malloc(sizeof(tree));
    root=construct(pre,in,start,end,&count);
    print(root);
    return 0;
}
