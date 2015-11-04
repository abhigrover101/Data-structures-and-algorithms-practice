#include<cstdio>
#include<stdlib.h>
struct node{
    int data;
    struct node *right;
    struct node *down;
};

void push(struct node **head,int data)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->right=NULL;
    newnode->data=data;
    newnode->down=(*head);
    (*head)=newnode;
}

struct node *merge(struct node *root,struct node *next)
{
    struct node *result=NULL;
    result=(struct node*)malloc(sizeof(struct node));
    if(root==NULL)
        return next;
    if(next==NULL)
        return root;

    if(root->data < next->data)
    {
        result->data=root->data;
        result->down=merge(root->down,next);
    }
    else
    {
        result->data=next->data;
        result->down=merge(root,next->down);
    }
    return result;
}

struct node * flatten(struct node *root)
{
    if(root==NULL || root->right==NULL)
        return root;
    else
        return merge(root,flatten(root->right));
}

int main()
{
    /* Let us create the following linked list
       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
    */
    struct node *root=NULL;
    push( &root, 30 );
    push( &root, 8 );
    push( &root, 7 );
    push( &root, 5 );

    push( &( root->right ), 20 );
    push( &( root->right ), 10 );

    push( &( root->right->right ), 50 );
    push( &( root->right->right ), 22 );
    push( &( root->right->right ), 19 );

    push( &( root->right->right->right ), 45 );
    push( &( root->right->right->right ), 40 );
    push( &( root->right->right->right ), 35 );
    push( &( root->right->right->right ), 28 );

    root=flatten(root);
    while(root!=NULL)
    {
        printf("%d ",root->data);
        root=root->down;
    }
    printf("\n");
    return 0;

}
