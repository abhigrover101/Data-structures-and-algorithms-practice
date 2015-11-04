#include<cstdio>
#include<stdlib.h>
using namespace std;
typedef struct tree{
    int data;
    struct tree *right;
    struct tree *left;
}tr;


int main()
{
    tr *t1=NULL;
    char *i;
    //t1=(struct tree*)malloc(sizeof(struct tree));
    printf("%d\n",sizeof(*t1));
    return 0;
}
