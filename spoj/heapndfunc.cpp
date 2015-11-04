#include<stdio.h>

void pushdown(int *a,int length)
{
    int j=1;
    int k=2*j;
    int temp,replace;
    while(1 && k<=length)
    {
        temp=a[j];
        replace=k;
        if(k+1<=length && a[k]<a[k+1])
            replace=k;
        else if(k+1 <=length)
            replace=k+1;

        if(a[j]<a[replace])
            break;
        else
        {
            a[j]=a[replace];
            a[replace]=temp;
            j=replace;
            k=2*j;
        }
    }
}

void pushup(int *a,int length)
{
    int j=length;
    int k=j/2;
    int temp,replace;
    while(1 && k>=1)
    {
        temp=a[j];
        replace=k;
        if(temp<a[k])
        {
            a[j]=a[replace];
            a[replace]=temp;
            j=replace;
            k=j/2;
        }
        else
            break;
    }
}



void heapify(int *a,int length)
{
    int i,j,k,temp,replace;
    for(i=length/2;i>=1;i--)
    {
        j=i;
        k=2*j;
        while(1 && k<=length)
        {
            temp=a[j];
            replace=k;
            if(k+1<=length && a[k]<a[k+1])
                replace=k;
            else if(k+1 <=length)
                replace=k+1;

            if(a[j]<a[replace])
                break;
            else
            {
                a[j]=a[replace];
                a[replace]=temp;
                j=replace;
                k=2*j;
            }
        }
    }
}

int main()
{
    int len,i,op;

    int a[10000];

    while(1)
    {
        printf("Select operation:\n0.Heapify\n1.Delete Minimum\n2.Insert a number\n3.Print Array\n4.Exit\n");
        scanf("%d",&op);
        if(op==0)
        {
            printf("Enter length and array of integers:\n");
            scanf("%d",&len);
            for(i=1;i<=len;i++)
                scanf("%d",&a[i]);
            heapify(&a[0],len);
        }
        if(op==1 && len >0)
        {
            printf("Number deleted is %d\n",a[1]);
            a[1]=a[len];
            len--;
            pushdown(&a[0],len);
        }
        else if(op==2)
        {
            printf("Enter number\n");
            scanf("%d",&a[len+1]);
            len++;
            pushup(&a[0],len);
        }
        else if(op==3)
        {
            for(i=1;i<=len;i++)
                printf("%d ",a[i]);
            printf("\n");
        }
        else if(op==4)
            return 0;
    }
    return 0;
}
