#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*link;
};
struct node*rear,*front;

void Display()
{
    if(front==NULL)
     printf("no element present");
    else{
        struct node*ptr;
        ptr=front;
        while(ptr->link!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->link;
        }
    }
}
void Enqueue(int x)
{
    struct node*new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    if(front==NULL)
    {
        front=rear=new;
    }
    else{
        rear->link=new;
        rear=new;
    }
    Display();
}
void dequeue()
{
    struct node*temp;
    if(front==NULL)
     printf("can't delete");
    else if(front==rear)
    {
        temp=front;
        front=rear=NULL;
        free(temp);
    }
    else{
        temp=front;
        front=front->link;
        free(temp);
        Display();
    }
}

int main()
{
    int choice,x;
    do
    {
        printf("enter the choice\n 1.Enqueue\n 2.Dequeue\n 3.Display\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf(" enter the element to insert");
                scanf("%d",&x);
                Enqueue(x);
            break;
        case 2: dequeue();
            break;
        case 3: Display();
            break;
        }
    } while (choice!=4);
    
}