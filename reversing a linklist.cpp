#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

struct node{
    int val;
    node *next;
};

void insert(node *root,int n)
{
    while(root->next!=NULL)
        root=root->next;
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->val=n;
    temp->next=NULL;
    root->next=temp;
    return;
}

node* reverse(node* root,int n)
{
    if(root==NULL)
        return NULL;
    int count=1;
    node *prev=NULL,*current=root,*next=current->next;
    while(count<=n)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        count++;
    }
    root->next=reverse(current,n);
    return prev;

}


int main()
{
    cout << "Enter elements terminated by -1\n";
    int n;
    node *root=NULL;
    root=(node *)malloc(sizeof(node));
    cin >>n;
    root->val=n;
    root->next=NULL;
    while(1)
    {
        scanf("%d",&n);
        if(n==-1)
            break;
        insert(root,n);
    }

    cout <<"Enter window length that u want to reverse\n";
    int l;
    cin >> l;
    root=reverse(root,l);
    while(root!=NULL)
    {
        cout << root->val << " ";
        root=root->next;
    }
    cout << endl;
}
