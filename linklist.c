#include<stdio.h>
#include<stdlib.h>
struct node{
	int num;
	struct node *next;
};

void deleteNode(struct node *root,int del)
{
	//struct node *temp;
	if(root->num==del)
	{
		root->num=root->next->num;
		root->next=root->next->next;
		return;
	}

	while(root->next!=NULL && root->next->num!=del)
		root=root->next;
	if(root->next!=NULL)
		root->next=root->next->next;
	return;
}

void chng(struct node **head)
{
	*head=(*head)->next;
//	printf("%d.....\n",(*head)->num);
	return;
}

void main()
{
	struct node *root,*temp;
	int n,input,del;
	root=(struct node *)malloc(sizeof(struct node));
	root->next=NULL;
	//root->num=100;
	temp=root;
	printf("Make Link List....It can be terminated by entering number -1\n");
	scanf("%d",&n);
	while(n!=-1)
	{
		temp->num=n;
		temp->next=(struct node *)malloc(sizeof(struct node *));
		temp=temp->next;
		scanf("%d",&n);
	}
	temp->next=NULL;
	printf("1.Quit\n2.Delete Node\n3.Print List\n4.Change to Next head\n");
	scanf("%d",&input);
	while(input!=1)
	{
		if( input==2)
		{
			printf("Enter Node to be deleted\n");
			scanf("%d",&del);
			deleteNode(root,del);
		}
		if(input==3)
		{
			temp=root;
			while(temp->next!=NULL)
			{
				printf("%d ",temp->num);
				temp=temp->next;
			}
			printf("\n");
		}
		if(input==4)
			chng(&root);
		printf("1.Quit\n2.Delete Node\n3.Print List\n4.Change to Next Head\n");
		scanf("%d",&input);
	}
	return;
}
