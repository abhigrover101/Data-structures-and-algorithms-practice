#include<cstdio>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<queue>
#include<utility>

using namespace std;

struct node{

    node *left;
    node *right;
    int height;
    int val;
};


void levelorder(node *root)
{
    queue < pair <node*,int> > q;
    q.push(make_pair(root,1));
    int level;
    pair <node*,int> temp;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp.first==NULL)
            continue;
        if(temp.second!=level)
            cout<<endl;
        cout<<(temp.first)->val<<" ";
        level=temp.second;
        q.push(make_pair((temp.first)->left,level+1));
        q.push(make_pair((temp.first)->right,level+1));
    }
    return;
}


node* leftrotation(node *root)
{
    node *temp=root->right;
    root->right=temp->left;
    temp->left=root;
    root->height=max(root->left? root->left->height:0,root->right?root->right->height:0)+1;
    temp->height=max(temp->left? temp->left->height:0,temp->right?temp->right->height:0)+1;
    return temp;
}

node* rightrotation(node *root)
{
    node *temp=root->left;
    root->left=temp->right;
    temp->right=root;
    root->height=max(root->left? root->left->height:0,root->right?root->right->height:0)+1;
    temp->height=max(temp->left? temp->left->height:0,temp->right?temp->right->height:0)+1;
    return temp;
}


node* bstinsert(node *root,int n)
{
    if(root->val==0)
    {
        root->val=n;
        root->height=1;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    else if(n>root->val)
    {
        if(root->right==NULL)
        {
            node *temp=(node*)malloc(sizeof(node));

            temp->val=n;
            temp->height=1;
            temp->left=NULL;
            temp->right=NULL;
            root->right=temp;
        }
        else
        {
            root->right=bstinsert(root->right,n);
            if(root->right->height - (root->left?root->left->height:0)>=2)
            {
                if(n>root->right->val)
                {
                    root=leftrotation(root);
                }
                else
                {
                    root->right=rightrotation(root->right);
                    root=leftrotation(root);
                }
            }

        }
    }
    else if(n<root->val)
    {
        if(root->left==NULL)
        {
            node *temp=(node*)malloc(sizeof(node));

            temp->val=n;
            temp->height=1;
            temp->left=NULL;
            temp->right=NULL;
            root->left=temp;
        }
        else
        {
            root->left=bstinsert(root->left,n);
            if(root->left->height - (root->right?root->right->height:0)>=2)
            {
                if(n<root->left->val)
                {
                    root=rightrotation(root);
                }
                else
                {
                    root->left=leftrotation(root->left);
                    root=rightrotation(root);
                }
            }

        }
    }
    else
    {
        cout<<"Already present, enter new number."<<endl;
        return root;
    }

    root->height=max(root->left? root->left->height:0,root->right?root->right->height:0)+1;
    return root;
}

void print(node *root)
{
    if(root==NULL)
        return;
    print(root->left);
    cout<<root->val<<" ";
    print(root->right);
    return;
}


int main()
{
    int n=1;
    node *head;
    head=(node*)malloc(sizeof(node));
    head->val=0;
    head->right=NULL;
    head->left=NULL;
    while(n!=0)
    {
        cout<<"enter 0 to quit or enter a number:";
        cin>>n;
        if(n==0)
            break;
        else
        {
            head=bstinsert(head,n);
        }
    }
    print(head);
    levelorder(head);
    //cout<<head->height<<endl;
    return 0;
}
