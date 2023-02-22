#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*link;
};
struct node*top;

void Display()
{
    struct node*ptr;
    if(top==NULL)
        printf("stack is empty");
    else{
        ptr=top;
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->link;
        }
    }
}
void push(int x)
{
    struct node*new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->link=top;
    top=new;
    Display();
}
void pop()
{
    struct node*ptr;
    if(top==NULL)
        printf("can't pop item");
    else{
        ptr=top;
        printf("poped item is %d",ptr->data);
        top=top->link;
        free(ptr);
        Display();
    }
}
int main()
{
    int choice,x;
    do
    {
        printf("enter the choice\n 1.push \n2.pop\n3.display");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("enter the element to push\n");
                scanf("%d",&x);
                push(x);
            break;
        case 2: pop();
            break;
        case 3: Display();
        }
    } while (choice!=4);
    
}