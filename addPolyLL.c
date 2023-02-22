#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coef,expo;
    struct node*link;
};
struct node*Phead,*Qhead,*Rhead;

struct node*Readpoly()
{
    struct node*new,*ptr,*head=NULL;
    int n,i;
    printf("\nenter the total number of terms in the polynomial\n");
    scanf("%d",&n);
    printf("\n enter the cofficent and exponent of the polynomial\n");
    for(i=1;i<=n;i++)
    {
        printf("Enter (coef%d , expo%d)",i,i);
        new=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&new->coef);
        scanf("%d",&new->expo);
        new->link=NULL;
        if(head==NULL)
        {
            head=new;
            ptr=head;
        }
        else{
            ptr->link=new;
            ptr=new;
        }
    }
    return(head);
}
void displayPoly(struct node*head)
{
    struct node*ptr;
    if(head==NULL)
        printf("polynomial is empty\n");
    else{
        ptr=head;
        while(ptr->link!=NULL)
        {
            printf("%d*^%d+",ptr->coef,ptr->expo);
            ptr=ptr->link;
        }
        printf("%d*^%d\t",ptr->coef,ptr->expo);
    }
}
struct node*addPoly()
{
    struct node*new,*P,*Q,*R,*head=NULL;
    P=Phead;
    Q=Qhead;
    while(P!=NULL && Q!=NULL)
    {
        if(P->expo==Q->expo)
        {
            new=(struct node*)malloc(sizeof(struct node));
            new->expo=P->expo;
            new->coef=P->coef+Q->coef;
            new->link=NULL;
            P=P->link;
            Q=Q->link;
        }
        else if(P->expo>Q->expo)
        {
            new=(struct node*)malloc(sizeof(struct node));
            new->expo=P->expo;
            new->coef=P->coef;
            new->link=NULL;
            P=P->link;
        }
        else{
            new=(struct node*)malloc(sizeof(struct node));
            new->expo=Q->expo;
            new->coef=Q->coef;
            new->link=NULL;
            Q=Q->link;
        }
    }
    if(head==NULL)
    {
        head=new;
        R=head;
    }
    else{
        R->link=new;
        R=new;
    }
    while(P!=NULL)      //remaining in P
    {
        new=(struct node*)malloc(sizeof(struct node));
        new->coef=P->coef;
        new->expo=P->expo;
        new->link=NULL;
        if(head==NULL)
        {
            head=new;
            R=head;
        }
        else{
            R->link=new;
            R=new;
        }
        P=P->link;
    }
    while(Q!=NULL)      //remaning in Q
    {
        new=(struct node*)malloc(sizeof(struct node));
        new->coef=Q->coef;
        new->expo=Q->expo;
        new->link=NULL;
        if(head==NULL)
        {
            head=new;
            R=head;
        }
        else{
            R->link=new;
            R=new;
        }
        Q=Q->link;
    }
    return(head);
}
void main()
{
    printf("\nenter the  details of first the polynomial\n");
    Phead=Readpoly();
    printf("\nenter the details of second polynomial\n");
    Qhead=Readpoly();

    printf("\nthe first polynomial is\n");
    displayPoly(Phead);

    printf("\n the second polynomial is\n");
    displayPoly(Qhead);

    Rhead=addPoly();
    printf("\nthe resultant polynomial is\n");
    displayPoly(Rhead);
}