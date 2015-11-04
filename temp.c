#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    int p;
}node;

int main()
{
    node *a;
    a=(node *)malloc(sizeof(node));
    node *b;
    b=a;
    b->p=10;
    free(b);
    printf("%d\n",b->p);
    return 0;
}
