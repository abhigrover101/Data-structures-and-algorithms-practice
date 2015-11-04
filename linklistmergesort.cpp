#include<cstdio>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

void split(node *head,node **start,node **end)
{
    node *fast,*slow;
    slow=head;
    fast=head->next;

    if(head==NULL || head->next==NULL)
    {
        (*start)=head;
        (*end)=NULL;
    }
    else
    {
        while(fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
            {
                slow=slow->next;
                fast=fast->next;
            }
        }
        (*start)=(head);
        (*end)=slow->next;
        //printf("%d ",(slow)->data);
        slow->next=NULL;
    }
    return;
}



node * merge(node *a,node *b)
{
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;

    node *result;
    result=(node *)malloc(sizeof(node));

    if(a->data <= b->data)
    {
        result->data=a->data;
        result->next=merge(a->next,b);
    }
    else if((a->data) > (b->data))
    {
        result->data=b->data;
        result->next=merge(a,b->next);
    }
    return result;
}

void mergesort(node **head)
{
    if((*head)==NULL)
        return;
    if((*head)->next==NULL)
        return;
    //printf("%d ",(*head)->data);
    node *a,*b;
    split((*head),&a,&b);
    mergesort(&a);
    mergesort(&b);
    *head=merge(a,b);
}

int main()
{
    int n;
    node *root,*temp;
    root=(node *)malloc(sizeof(node));
    root->next=NULL;
    temp=root;
	printf("Make Link List....It can be terminated by entering number -1\n");
	scanf("%d",&n);
	while(n!=-1)
	{
		temp->data=n;
        //printf("%d ",root->data);
        scanf("%d",&n);
        if(n==-1)
        {
            temp->next=NULL;
            break;
        }
		temp->next=(node *)malloc(sizeof(node));
		temp=temp->next;

	}
	mergesort(&root);
	while(root!=NULL)
	{
        printf("%d ",root->data);
        root=root->next;
	}
	return 0;
}
