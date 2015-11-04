#include<stdio.h>
#include<iostream>
#include<map>
//#include<string.h>
#include<stdlib.h>

typedef struct node
{
	int value;
	struct node *left;
	struct node *right;
	//int l;
	int r;
}node;

using namespace std;

long long int c;

void insert(node *root,int num)
{
    //printf("%d\n",root->value);
	if(root->value==-1)
	{
		root->value=num;
        root->left=NULL;
        root->right=NULL;
        root->r=0;
      //  root->l=0;
		return;
	}
	else if (num > root->value)
	{
	    root->r++;
		if(root->right==NULL)
		{
			node *child;
			child=(node *)malloc(sizeof(node));
			child->value=num;
			child->left=NULL;
			child->right=NULL;
			//child->l=0;
			child->r=0;
			root->right=child;
			return;
		}
		else
			insert(root->right,num);
	}
	else if (num < root->value)
	{
	    c=c+root->r+1;
		if(root->left==NULL)
		{
			node *child;
			child=(node *)malloc(sizeof(node));
			child->value=num;
			child->left=NULL;
			child->right=NULL;
			//child->l=0;
			child->r=0;
			root->left=child;
			return;
		}
		else
			insert(root->left,num);
	}
	return;
}

/*void print(node *root)
{
	if(root==NULL)
		return;
	print(root->left);
	//printf("%d ",root->value);
	//c=c+((root->l)*(root->r+1));
	print(root->right);
	return;
}*/

int main()
{
    int T;
    //cin >> T;
    scanf("%d",&T);
    int N,i,k;
    char temp[25];
    map<string,int> mymap;
    while(T--)
    {
        node *root;
        c=0;
        root=(node *)malloc(sizeof(node));
        root->value=-1;
        root->left=NULL;
        root->right=NULL;
        //cin >> N;
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            //cin >> temp;
            scanf("%s",temp);
            mymap.insert(pair<string,int>(temp,i));

        }
        for(i=0;i<N;i++)
        {
            scanf("%s",temp);
            insert(root,mymap.find(temp)->second);
        }

        //print(root);
        printf("%lld\n",c);
        mymap.clear();
        //free(root);
    }


    return 0;
}

