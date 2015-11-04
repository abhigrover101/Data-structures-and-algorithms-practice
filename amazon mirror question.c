#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node *left;
    struct node *right;
};

struct node* reverse(struct node *temp)
{
	if(temp==NULL)
		return temp;
	struct node *t1,*t2;
	t1=temp->right;
	t2=temp->left;
	temp->left=reverse(t1);
	temp->right=reverse(t2);
	return temp;
}

void print(struct node *temp)
{
    if(temp==NULL)
        return;
    print(temp->left);
    printf("%d ",temp->value);
    print(temp->right);
    return;
}

int main()
{
    struct node *root;
    int i;
    root=(struct node *)malloc(sizeof(struct node *));
    root->value=20;
    struct node *temp[6];
    for(i=0;i<6;i++)
        temp[i]=(struct node *)malloc(sizeof(struct node *));

    temp[0]->value=16;
    temp[1]->value=18;
    temp[2]->value=14;
    temp[3]->value=12;
    temp[4]->value=10;
    temp[5]->value=8;

    root->left=temp[0];
    root->left->left=temp[2];
    root->left->right=temp[3];
    root->right=temp[1];
    root->right->left=temp[4];
    root->right->right=temp[5];

    print(root);
    printf("\n");
    reverse(root);
    print(root);
    return 1;
}

