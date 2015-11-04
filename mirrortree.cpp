#include<cstdio>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef struct tree{
    int data;
    struct tree *left;
    struct tree *right;

}tree;

void push(tree *root,int n){

    if(root->data==-1)
    {
        root->data=n;
        return;
    }
    if(root->data > n)
    {
        if(root->left==NULL)
        {
            tree *temp;
            temp=(tree *)malloc(sizeof(tree));
            temp->data=n;
            temp->left=NULL;
            temp->right=NULL;
            root->left=temp;
            return;
        }
        else
            push(root->left,n);
    }
    if(root->data < n)
    {
        if(root->right==NULL)
        {
            tree *temp;
            temp=(tree *)malloc(sizeof(tree));
            temp->data=n;
            temp->left=NULL;
            temp->right=NULL;
            root->right=temp;
            return;
        }
        else
            push(root->right,n);
    }
    return;
}

/*int diameter(tree *root,int *height)
{
    if(root==NULL)
        return 0;

    int lh=0,rh=0;
    int ld=0,rd=0;

    ld=diameter(root->left,&lh);
    rd=diameter(root->right,&rh);

    *height=max(lh,rh)+1;
    return max(lh+rh+1,max(ld,rd));
}*/

int diameter(tree *root,int *dia)
{
    if(root==NULL)
        return 0;
    int left,right;
    left=diameter(root->left,dia);
    right=diameter(root->right,dia);

    *dia=max(*dia,left+right+1);

    return max(left,right)+1;
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

int height(tree *root)
{
    if(root==NULL)
        return 0;
    else
        return max(height(root->left),height(root->right))+1;
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
    if(root->data==n && root->left==NULL && root->right==NULL )
    {
        free(root);
        return NULL;
    }
    if(root->data > n)
        root->left=del(root->left,n);
    else if(root->data < n)
        root->right=del(root->right,n);
    else if(root->data==n && root->right!=NULL)
    {
        root->data=mini(root->right);
        root->right=del(root->right,mini(root->right));
    }
    else if(root->data==n && root->left!=NULL)
    {
        root->data=maxi(root->left);
        root->left=del(root->left,maxi(root->left));
    }
    return root;
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
        printf("1.Insert new element in tree\n2.Print tree in inorder\n3.Make mirror\n4.Find height\n5.Find Minimum\n6.Find Maximum\n7.Print root to leaf paths\n8.Find LCA\n9.Print Level Order\n10.Count Leaf Nodes\n11.Find Diameter\n12.Convert to Dll\n13.Check if Avl\n14.Delete a node\n15.Exit\n");
        scanf("%d",&op);
        if(op==1)
        {
            printf("Enter number to insert\n");
            scanf("%d",&n);
            push(root,n);
        }
        if(op==2)
        {
            inorder(root);
            printf("\n");
        }
        if(op==3)
            mirror(root);
        else if(op==4)
            printf("Size of Tree is %d\n",height(root));
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
            diameter(root,&tt);
            printf("Diameter of tree is %d\n",tt);
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
            del(root,n);
        }
        else if(op==15)
            return 0;
    }
    return 0;

}
