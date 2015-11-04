#include<cstdio>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *exor;
}node;

node * XOR(node *a,node *b)
{
    return (node *)(((unsigned int)a) ^ ((unsigned int)b));
}

void insertathead(node **head,int n)
{
    node *newnode;
    newnode=(node *)malloc(sizeof(node));
    newnode->data=n;
    newnode->exor=XOR(NULL,(*head));
    if(*head!=NULL)
    {
        node *next=XOR(NULL,(*head)->exor);
        (*head)->exor=XOR(newnode,next);
    }
    *head=newnode;
}

void insertafter(int num,int newdata, node *head)
{
    node *prev=NULL,*temp;
    while(head->data!=num)
    {
        temp=head;
        head=(XOR(prev,(head->exor)));
        prev=temp;
    }
    if(head==NULL)
    {
        printf("Number not in list\n");
        return;
    }
    else
    {
        node *newnode;
        node *next;
        //storing address of next element
        next=(XOR(prev,(head->exor)));
        //element to be inserted
        newnode=(node *)malloc(sizeof(node));
        newnode->data=newdata;
        // head is its prev now nd next is its next
        newnode->exor=(XOR(head,next));
        //newnode is prev of next now
        if(next!=NULL)
            next->exor=(XOR(XOR(next->exor,head),newnode));
        //new node is the next of head now
        head->exor=(XOR(prev,newnode));
      }
      return;
}

void print(node *head)
{
    node *temp,*prev;
    prev=NULL;
    while(head!=NULL)
    {
        printf("%d ",head->data);
        temp=head;
        head=XOR(head->exor,prev);
        prev=temp;
    }
    printf("\n");
    return;
}

void del(node **head,int n)
{
    node *start=(*head),*prev,*temp;
    prev=NULL;
    if((*head)->data==n)
    {
        node *next=XOR(start->exor,prev);
        next->exor=XOR(prev,XOR(next->exor,start));
        *head=(XOR((*head)->exor,prev));
        return;
    }
    prev=NULL;
    while(start->data!=n)
    {
        temp=start;
        start=(XOR(start->exor,prev));
        prev=temp;
    }
    if(start==NULL)
    {
        printf("Number not found\n");
        return;
    }
    else{
        node *next=XOR(start->exor,prev);
        prev->exor=(XOR(XOR(prev->exor,start),next));
        if(next!=NULL)
            next->exor=(XOR(prev,XOR(next->exor,start)));
    }
    return;
}
int main()
{
    int op,n,t;
    node *head=NULL;
    while(1)
    {
        printf("1.Insert Node at beginning\n2.Insert node in between\n3.Delete Node\n4.Print list\n5.Exit\n");
        scanf("%d",&op);
        if(op==1)
        {
            printf("Enter Number to insert at start:\n");
            scanf("%d",&n);
            insertathead(&head,n);
            //printf("head %d\n",head->data);
        }
        if(op==2)
        {
            printf("Enter number after which the new number be inserted then enter the new number:\n");
            {
                scanf("%d%d",&t,&n);
                insertafter(t,n,head);
                //printf("head %d\n",head->data);
            }
        }
        if(op==3)
        {
            printf("Enter number to be deleted:\n");
            scanf("%d",&n);
            del(&head,n);
        }
        if(op==4)
        {
            print(head);
        }
        if(op==5)
            return 0;
    }
}
