#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*lc,*rc;
};

void buildTree(struct node*ptr)
{
    struct node*lcptr,*rcptr;
    int ch;
    if(ptr!=NULL)
    {
       printf("enter the data\n");
       scanf("%d",&ptr->data);
       ptr->lc=NULL;
       ptr->rc=NULL;
       printf("Do you have left child for%d(1/0)",ptr->data);
       scanf("%d",&ch);
       if(ch==1)
       {
            lcptr=(struct node*)malloc(sizeof(struct node));
            ptr->lc=lcptr;
            buildTree(lcptr);
       }
       printf("do you have right child for%d(1/0) \n",ptr->data);
       scanf("%d",&ch);
       if(ch==1)
       {
            rcptr=(struct node*)malloc(sizeof(struct node));
            ptr->lc=rcptr;
            buildTree(rcptr);
       }
    }
}
void inorder(struct node*ptr)
{
    if(ptr!=NULL)
    {
        inorder(ptr->lc);
        printf("%d",ptr->data);
        inorder(ptr->rc);
    }
}
void preorder(struct node*ptr)
{
    if(ptr!=NULL)
    {
        printf("%d",ptr->data);
        preorder(ptr->lc);
        preorder(ptr->rc);
    }
}
void postorder(struct node*ptr)
{
    if(ptr!=NULL)
    {
        postorder(ptr->lc);
        postorder(ptr->rc);
        printf("%d",ptr->data);
    }
}
void main()
{
    struct node*root;
    root=(struct node*)malloc(sizeof(struct node));
    buildTree(root);
    printf("\ninorder traversal\n");
    inorder(root);
    printf("\npreorder traversal\n");
    preorder(root);
    printf("\npostorder traversal\n");
    postorder(root);
    getchar();
}