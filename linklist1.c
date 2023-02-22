#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*link;
};
struct node*head;

void Display()
{
    if(head==NULL)
     printf("no element present yet!!");
    else{
        struct node*ptr;
        ptr=head;
        while(ptr->link!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->link;
        }
    }
}
void insertAtFront(int x)
{ 
    struct node*new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->link=head;
    head=new;
    Display();
}
void insertAtEnd(int x)
{
    struct node*new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->link=NULL;
    if(head==NULL)
    {
        head=new;
    }
    else{
        struct node*ptr;
        ptr=head;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=new;
    }
    Display();
}
void insertAfterKey(int k,int x)
{
    struct node*new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    if(head==NULL)
    {
        printf("search element not found");
    }
    else{
        struct node*ptr;
        ptr=head;
        while(ptr->data!=k && ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        if(ptr->data!=k)
            printf("key not found");
        else{
            new->link=ptr->link;
            ptr->link=new;
        }
    }
    Display();
}
void deleteFront()
{
    if(head==NULL)
     printf("deletion is not possible");
    else{
        struct node*temp;
        temp=head;
        head=head->link;
        free(temp);
    }
    Display();
}
void deleteEnd()
{
    struct node*temp,*prev,*curr;
    if(head==NULL)
     printf("deletion not possible");
    else{
        prev=head;
        curr=head;
        while(curr->link!=NULL)
        {
            prev=curr;
            curr=curr->link;
        }
        prev->link=NULL;
        free(curr);
    }
    Display();
}
void deleteAtAny(int k)
{
    if(head->data==k)
    {
        struct node*temp;
        temp=head;
        head=NULL;
        free(temp);
    }
    else{
        struct node*prev;
        struct node*curr;
        prev=head;
        curr=head;
        while(curr->data!=k && curr->link!=NULL)
        {
            prev=curr;
            curr=curr->link;
        }
        if(curr->data!=k)
         printf("key not found");
        else{
            prev->link=curr->link;
            free(curr);
        }
    }
    Display();
}
void count()
{
    struct node*p;
    p=head;
    int c=0;
    while(p)
    {
        ++c;
        p=p->link;
    }
    printf("\nnumber of linklist is: %d\n",c);
}
void add()
{
    struct node*p;
    p=head;
    int sum=0;
    while(p)
    {
        sum+=p->data;
        p=p->link;
    }
    printf("\nthe sum of elements in LinkList is %d\n",sum);
}
void max()
{
    struct node*p;
    p=head;
    int max=-32768;
    while(p)
    {
        if(p->data>max)
            max=p->data;
        p=p->link;
    }
    printf("max element is %d\n",max);
}
int main()
{
    int choice;
    int ele;
    int key;
    do
    {
        printf("enter the choice:  1.insert at front\n  2.insert at end\n  3.insert after a key\n  4.delete front\n  5.delete end\n  6.delete at any given position\n 7.count\n 8.display\n 9.add\n 10.max\n" );
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("enter the element to insert");
                    scanf("%d",&ele);
                    insertAtFront(ele);
                    break;
            case 2: printf("enter the element to insert");
                    scanf("%d",&ele);
                    insertAtEnd(ele);
                    break;
            case 3: printf("enter the element to insert");
                    scanf("%d",&ele);
                    printf("enter the key value ");
                    scanf("%d",&key);
                    insertAfterKey(key,ele);
                    break;
            case 4: deleteFront();
                    break;
            case 5: deleteEnd();
                    break;
            case 6: printf("enter the key node to delete");
                    scanf("%d",&key);
                    deleteAtAny(key);
                    break;
            case 7: count();
                    break;
            case 8: Display();
                    break;
            case 9: add();
                    break;
            case 10: max();
                    break;
        }
    } while (choice!=11);
}