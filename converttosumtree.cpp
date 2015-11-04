#include<cstdio>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}tree;

tree * insert(int n)
{
    tree *newn;
    newn=(tree *)malloc(sizeof(tree));
    newn->data=n;
    newn->left=NULL;
    newn->right=NULL;
    return newn;
}

void incre(tree *root,int diff)
{
    if(root==NULL)
        return;
    root->data+=diff;
    if(root->left!=NULL)
        incre(root->left,diff);
    else
        incre(root->right,diff);
    return;
}

void childrensum(tree *root)
{
    int l=0,r=0,diff=0;
    if(root==NULL)
        return;
    //printf("l = %d\n",root->data);
    childrensum(root->left);
    childrensum(root->right);
    if(root->left!=NULL)
        l=root->left->data;
    if(root->right!=NULL)
        r=root->right->data;
    //printf("l = %d\n",l);
    diff=r+l-root->data;
    if(diff==0)
        return;
    else if(diff>0)
        root->data=r+l;
    else if(diff<0)
    {
        if(root->left!=NULL)
            incre(root->left,-diff);
        else
            incre(root->right,-diff);
    }
    return;
}


void inorder(tree *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
    return;
}


int main()
{
    printf("Convert given tree to sum tree\n");
    tree *root;
    root=insert(50);
    root->left=insert(7);
    root->left->left=insert(3);
    root->left->right=insert(5);
    root->right=insert(2);
    root->right->right=insert(30);
    root->right->left=insert(1);
    inorder(root);
    printf("\n");
    childrensum(root);
    inorder(root);
    printf("\n");
    return 0;
}
