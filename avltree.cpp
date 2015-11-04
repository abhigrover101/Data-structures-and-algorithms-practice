#include<cstdio>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;
typedef struct tree{
    int data;
    int height;
    struct tree *left;
    struct tree *right;

}tree;

tree *leftrotation(tree *root)
{
    tree *x=root->right;
    root->right=x->left;
    root->height=max(root->left? root->left->height:0,root->right? root->right->height:0)+1;
    x->left=root;
    return x;
}

tree *rightrotation(tree *root)
{
    tree *x=root->left;
    root->left=x->right;
    root->height=max(root->left? root->left->height:0,root->right? root->right->height:0)+1;
    x->right=root;
    return x;
}

tree *push(tree *root,int n)
{
    int lh,rh;
    if(root->data==-1)
    {
        root->data=n;
        root->height=1;
        root->left=NULL;
        root->right=NULL;
        return root;
    }

    if(root->data > n)
    {
        if(root->left==NULL)
        {
            //printf("here1");
            tree *newn;
            newn=(tree *)malloc(sizeof(tree));
            newn->data=n;
            newn->height=1;
            newn->left=NULL;
            newn->right=NULL;
            root->left=newn;
            root->height=max(root->left? root->left->height:0,root->right? root->right->height:0)+1;
            return root;
        }
        else
        {
            root->left=push(root->left,n);
            lh=root->left? root->left->height:0;
            rh=root->right? root->right->height:0;
            if(lh-rh >= 2)
            {
                if(n < root->left->data)
                    root=rightrotation(root);
                else
                {
                    root->left=leftrotation(root->left);
                    root=rightrotation(root);
                }
            }
            root->height=max(root->left? root->left->height:0,root->right? root->right->height:0)+1;
        }
    }
    else if(root->data < n)
    {
        if(root->right==NULL)
        {
            tree *newn;
            newn=(tree *)malloc(sizeof(tree));
            newn->data=n;
            newn->height=1;
            newn->left=NULL;
            newn->right=NULL;
            root->right=newn;
            root->height=max(root->left? root->left->height:0,root->right? root->right->height:0)+1;
            return root;
        }
        else
        {
            root->right=push(root->right,n);
            lh=root->left? root->left->height:0;
            rh=root->right? root->right->height:0;
            if(rh-lh >= 2)
            {
                if(n > root->right->data)
                    root=leftrotation(root);
                else
                {
                    root->right=rightrotation(root->right);
                    root=leftrotation(root);
                }
            }
            root->height=max(root->left? root->left->height:0,root->right? root->right->height:0)+1;
        }
    }
    return root;
}

int diameter(tree *root,int *height)
{
    if(root==NULL)
        return 0;

    int lh=0,rh=0;
    int ld=0,rd=0;

    ld=diameter(root->left,&lh);
    rd=diameter(root->right,&rh);

    *height=max(lh,rh)+1;
    return max(lh+rh+1,max(ld,rd));
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

tree* mirror(tree *root){

    tree *temp1,*temp2;
    if(root==NULL)
        return NULL;

    temp1=root->right;
    temp2=root->left;
    root->left=mirror(temp1);
    root->right=mirror(temp2);

    return root;

}

int mini(tree *root)
{
    while(root->left!=NULL)
        root=root->left;
    return root->data;
}


int maxi(tree *root)
{
    while(root->right!=NULL)
        root=root->right;
    return root->data;
}

void printst(vector <int> st)
{
    int i=0;
    for(i=st.size()-1;i>=0;i--)
        printf("%d ",st[i]);
    printf("\n");
    return;
}

void roottoleaf(tree *root,vector <int> st)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
        printst(st);
    if(root->left !=NULL)
    {
        st.push_back(root->left->data);
        roottoleaf(root->left,st);
        st.pop_back();
    }
    if(root->right !=NULL)
    {
        st.push_back(root->right->data);
        roottoleaf(root->right,st);
        st.pop_back();
    }
    return;
}

void lca(tree *root,int a,int b)
{
    if(b>root->data && a < root->data)
        printf("LCA of %d and %d is %d\n",a,b,root->data);
    else if(root->data > a && root->data > b && root->left->data==a)
        printf("LCA of %d and %d is %d\n",a,b,root->data);
    else if(root->data < a && root->data < b && root->right->data==a)
        printf("LCA of %d and %d is %d\n",a,b,root->data);
    else if(root->data > a && root->data > b)
        lca(root->left,a,b);
    else if(root->data < a && root->data < b)
        lca(root->right,a,b);
    return;
}

void levelorder(queue<pair <tree *, int> > q)
{
    tree *temp;
    int current=-1,lvl;
    while(!q.empty())
    {
        temp=q.front().first;
        lvl=q.front().second;
        if(temp==NULL)
            continue;
        if(lvl!=current)
        {
            current=lvl;
            printf("\nLevel %d:",lvl);
        }
        printf("%d ",temp->data);
        if(temp->left!=NULL)
        {
            q.push(make_pair(temp->left,current+1));
        }
        if(temp->right!=NULL)
        {
            q.push(make_pair(temp->right,current+1));
        }
        q.pop();
    }
    printf("\n");
}

int countleaf(tree *root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    return countleaf(root->left)+countleaf(root->right);
}

void incre(tree *root,int diff)
{
    if(root==NULL)
        return;
    root->data+=diff;
    if(!root->left)
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
    printf("l = %d\n",root->data);
    childrensum(root->left);
    childrensum(root->right);
    if(!root->left)
        l=root->left->data;
    if(!root->right)
        r=root->right->data;
    printf("l = %d\n",l);
    diff=r+l-root->data;
    if(diff==0)
        return;
    else if(diff>0)
        root->data=r+l;
    else if(diff<0)
    {
        if(!root->left)
            incre(root->left,-diff);
        else
            incre(root->right,-diff);
    }
    return;
}

void convert_to_dll(tree *root,tree **head,tree **prev)
{
    if(root==NULL)
        return;
    convert_to_dll(root->left,head,prev);

    if(*head==NULL)
    {
        *head=root;
    }
    else
    {
        (*prev)->right=root;
        root->left=*prev;
    }
    *prev=root;
    convert_to_dll(root->right,head,prev);
    return;
}

int checkavl(tree *root,int *height)
{
    if(root==NULL)
        return 0;
    int lh;
    int rh;
    lh=checkavl(root->left,height);
    rh=checkavl(root->right,height);
    if(*height==-1)
        return 0;
    if(abs(lh-rh)>1)
    {
        *height=-1;
        //printf("%d ",abs(lh-rh));
    }
    return max(lh,rh)+1;
}

tree * del(tree *root,int n)
{
    int lh=0,rh=0;
    if(root->data==n && root->left==NULL && root->right==NULL )
    {
        free(root);
        return NULL;
    }
    if(root->data > n)
    {
        root->left=del(root->left,n);
        lh=root->left? root->left->height:0;
            rh=root->right? root->right->height:0;
            if(rh-lh >= 2)
            {
                if(root->right!=NULL)
                    root=leftrotation(root);
                else
                {
                    root->right=rightrotation(root->right);
                    root=leftrotation(root);
                }
            }
            root->height=max(root->left? root->left->height:0,root->right? root->right->height:0)+1;
    }
    else if(root->data < n)
    {
        root->right=del(root->right,n);
        lh=root->left? root->left->height:0;
            rh=root->right? root->right->height:0;
            if(lh-rh >= 2)
            {
                if(root->left!=NULL)
                    root=rightrotation(root);
                else
                {
                    root->left=leftrotation(root->left);
                    root=rightrotation(root);
                }
            }
            root->height=max(root->left? root->left->height:0,root->right? root->right->height:0)+1;
    }
    else if(root->data==n && root->right!=NULL)
    {
        root->data=mini(root->right);
        root->right=del(root->right,mini(root->right));
        lh=root->left? root->left->height:0;
            rh=root->right? root->right->height:0;
            if(lh-rh >= 2)
            {
                if(root->left!=NULL)
                    root=rightrotation(root);
                else
                {
                    root->left=leftrotation(root->left);
                    root=rightrotation(root);
                }
            }
            root->height=max(root->left? root->left->height:0,root->right? root->right->height:0)+1;
    }
    else if(root->data==n && root->left!=NULL)
    {
        root->data=maxi(root->left);
        root->left=del(root->left,maxi(root->left));
            lh=root->left? root->left->height:0;
            rh=root->right? root->right->height:0;
            if(rh-lh >= 2)
            {
                if(root->right!=NULL)
                    root=leftrotation(root);
                else
                {
                    root->right=rightrotation(root->right);
                    root=leftrotation(root);
                }
            }
            root->height=max(root->left? root->left->height:0,root->right? root->right->height:0)+1;
    }
    return root;
}

void postorder(tree *root)
{
    stack<tree*> st1,st2;
    st1.push(root);
    tree *temp;
    while(!st1.empty()|| !st2.empty())
    {
        temp=st1.top();
        st1.pop();
        st2.push(temp);
        if(temp->left)
        {
            st1.push(temp->left);
        }
        if(temp->right)
        {
            st1.push(temp->right);
        }

        if(st1.empty()==true)
        {
            while(!st2.empty())
            {
                cout<<(st2.top())->data<<" ";
                st2.pop();
            }
            cout<<endl;
        }

    }
    return;
}

int main(){

    tree *root,*head,*p,*prev;
    queue <pair <tree *, int> > q;
    vector <int> st;
    root=(tree*)malloc(sizeof(tree));
    root->data=-1;
    root->left=NULL;
    root->right=NULL;
    int op,n,a,b,tt,h;
    while(1)
    {
        printf("1.Insert new element in tree\n2.Print tree in inorder\n3.Make mirror\n4.Find height\n5.Find Minimum\n6.Find Maximum\n7.Print root to leaf paths\n8.Find LCA\n9.Print Level Order\n10.Count Leaf Nodes\n11.Find Diameter\n12.Convert to Dll\n13.Check if Avl\n14.Delete Node\n15.Print Postorder\n16.Exit\n");
        scanf("%d",&op);
        if(op==1)
        {
            printf("Enter number to insert\n");
            scanf("%d",&n);
            root=push(root,n);
            //printf("%d",root->data);
        }
        if(op==2)
        {
            inorder(root);
            printf("\n");
        }
        if(op==3)
            mirror(root);
        else if(op==4)
            printf("Size of Tree is %d\n",root->height);
        else if(op==5)
            printf("Minimum Value in tree is %d\n",mini(root));
        else if(op==6)
            printf("Maximum Value in tree is %d\n",maxi(root));
        else if(op==7)
        {
            st.push_back(root->data);
            roottoleaf(root,st);
            st.pop_back();
        }
        else if(op==8)
        {
            printf("Enter two numbers:");
            scanf("%d%d",&a,&b);
            lca(root,min(a,b),max(a,b));
        }
        else if(op==9)
        {
            q.push(make_pair(root,0));
            levelorder(q);
            q.pop();
        }
        else if(op==10)
            printf("Number of leaf nodes in tree %d\n",countleaf(root));
        else if(op==11)
        {
            tt=0;
            printf("Diameter of tree is %d\n",diameter(root,&tt));
        }
        else if(op==12)
        {
            prev=NULL;
            head=NULL;
            convert_to_dll(root,&head,&prev);
            prev->right=head;
            p=head;
            while(1)
            {
                printf("%d ",p->data);
                p=p->right;
                if(p==head)
                    break;
            }
            printf("\n");
        }
        else if(op==13)
        {
            h=0;
            printf("%s",checkavl(root,&h)? "It is Avl\n" : "Not Avl\n");
        }
        else if(op==14)
        {
            printf("Enter number to delete\n");
            scanf("%d",&n);
            root=del(root,n);
        }
        else if(op==15)
        {
            postorder(root);
        }
        else if(op==16)
            return 0;
    }
    return 0;

}
