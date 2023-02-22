#include<stdio.h>

void buildTree(int a[],int i,int item)
{
    int ch;
    int val;

    a[i]=item;
    printf("Do you want left child for %d(1/0)",item);
    scanf("%d",&ch);
    if(ch==1)
    {
        printf("\nenter the value\n");
        scanf("%d",&val);
        buildTree(a,2*i,val);
    }
    printf("\nDo you want right child for %d (1/0)",item);
    scanf("%d",&ch);
    if(ch==1)
    {
        printf("\nenter the value\n");
        scanf("%d",&val);
        buildTree(a,2*i+1,val);
    }
}
void main()
{
    int a[100],item;
    for(int i=0;i<100;i++)
        a[i]=-1;
    printf("enter the root node\n");
    scanf("%d",&item);
    buildTree(a,1,item);
    for(int i=0;i<16;i++)
    {
        if(a[i]==-1)
            printf("- ");
        else
            printf("%d ",a[i]);
    }
}