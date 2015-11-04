#include<stdio.h>
#include<stdlib.h>
struct node{
	int value;
	struct node *next;
};

void insert(struct node *root, int n)
{
	if(root->value==-2)
	{
		root->value=n;
		root->next=NULL;
		return;
	}
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	while(root->next!=NULL)
		root=root->next;
	temp->value=n;
	temp->next=NULL;
	root->next=temp;
	return;
}

struct node * swap(struct node *root)
{
	struct node *temp,*previous;
	temp=root->next;
	previous=(struct node *)malloc(sizeof(struct node));
	//previous=root->next;
	while(1)
	{
		if(root->next!=NULL)
		{
			struct node *temp1,*temp2;
			temp1=root->next;
			temp2=root;
			temp2->next=root->next->next;
			temp1->next=temp2;
			root=temp1;
			previous->next=temp1;
			previous=temp2;
			if(root->next->next==NULL || root->next==NULL)
				return temp;
			root=root->next->next;
		}
		else
			break;
	}
	if(root!=NULL)
		previous->next=root;
	//previous=temp2;
	return temp;
}

void main()
{
	int n=0;
	struct node *root,*start;
	root=(struct node *)malloc(sizeof(struct node));
	root->value=-2;
	root->next=NULL;
	start=root;
	while(1)
	{
		scanf("%d",&n);
		if(n==-1)
			break;
		insert(root,n);
	}
	while(root!=NULL)
	{
		printf("%d ",root->value);
		root=root->next;
	}
	printf("\n");
	start=swap(start);
	while(start!=NULL)
	{
		printf("%d ",start->value);
		start=start->next;
	}
	printf("\n");

}
