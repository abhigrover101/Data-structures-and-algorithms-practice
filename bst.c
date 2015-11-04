#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int value;
	struct node *left;
	struct node *right;
}node;

void insert(node *root,int num)
{
	if(root->value==-1)
	{
		root->value=num;
		return;
	}
	else if (num > root->value)
	{
		if(root->right==NULL)
		{
			node *child;
			child=(node *)malloc(sizeof(node *));
			child->value=num;
			child->left=NULL;
			child->right=NULL;
			root->right=child;
			return;
		}
		else
			insert(root->right,num);
	}
	else if (num < root->value)
	{
		if(root->left==NULL)
		{
			node *child;
			child=(node *)malloc(sizeof(node *));
			child->value=num;
			child->left=NULL;
			child->right=NULL;
			root->left=child;
			return;
		}
		else
			insert(root->left,num);
	}
	return;
}

void print(node *root)
{
	if(root==NULL)
		return;
	print(root->left);
	printf("%d ",root->value);
	print(root->right);
	return;
}

int findmin(node *root)
{
	if(root->left !=NULL)
		findmin(root->left);
	else
		return root->value;
}

int findmax(node *root)
{
	if(root->right !=NULL)
		findmax(root->right);
	else
		return root->value;
}

int delete(node **root,int num)
{
	if(num > (*root)->value)
		delete(&(*root)->right,num);
	else if(num < (*root)->value)
		delete(&(*root)->left,num);
	else if((*root)->value==num && (*root)->left==NULL && (*root)->right==NULL)
	{
		int temp;
		//node *temp1;
//		temp1=(node *)malloc(sizeof(node *));
		temp=(*root)->value;
//		temp1=NULL;
		*root=NULL;
//		free((*root));
		return temp;
	}
	else if((*root)->value==num && (*root)->right!=NULL)
	{
		//node *temp;
		//node *left=root->left;
		//node *right=root->right;
		(*root)->value=findmin((*root)->right);
		delete(&(*root)->right,findmin((*root)->right));
	}
	else if((*root)->value==num && (*root)->left!=NULL)
	{

		//node *temp;
		//temp=(node *)malloc(sizeof(node *));
		//temp=root;
		(*root)->value=findmax((*root)->left);
		delete(&(*root)->left,findmax((*root)->left));
	}
	return (*root)->value;
}

void main()
{
	int num=0,option=1;
	node *root;
	root=(node *)malloc(sizeof(node *));
	root->value=-1;
	root->left=NULL;
	root->right=NULL;
	while(option!=0)
	{
		printf("Select from following:\n1.Insert Element\n2.Print\n3.Find Min\n4.Find Max\n5.Delete Number\n0.Exit\n");
		scanf("%d",&option);
		if(option==1)	
		{
			scanf("%d",&num);
			insert(root,num);
		}
		if(option==2)
		{
			print(root);
			printf("\n");
		}
		if(option==3)
			printf("%d\n",findmin(root));
		if(option==4)
			printf("%d\n",findmax(root));
		if(option==5)
		{
			scanf("%d",&num);
			delete(&root,num);
		}
	}
}
