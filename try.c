#include<stdio.h>
#include<stdlib.h>
struct node{
	        int value;
		        struct node *next;
};

void main()
{
        int n=0;
        struct node *root,*start,*temp1,*temp2,*start2;

        start2=(struct node *)malloc(sizeof(struct node));
        start=(struct node *)malloc(sizeof(struct node));
        temp1=(struct node *)malloc(sizeof(struct node));
        temp2=(struct node *)malloc(sizeof(struct node));
        root=(struct node *)malloc(sizeof(struct node));
        root->value=1;
	start->value=2;
	start2->value=3;
        temp1->value=21;
        temp2->value=31;
	root->next=start;
	root->next->next=start2;
	temp1=root->next;
	temp2=root;
	temp2->next=root->next->next;
	temp1->next=temp2;
	root=temp1;
}

