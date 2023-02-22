#include<stdio.h>

int A[20],size,front,rear;

void display()
{
    if(front==-1)
        printf("\nno element present");
    else{
        for(int i=front;i<=rear;i++)
            printf("%d\t",A[i]);
    }
}
void push(int x)    //insertion from front
{
    if(front==0 && rear==size-1)
        printf("DEqueue is full");
    else if(rear==-1){
        front=0;
        rear=0;
        A[front]=x;
    }
    else if(front>0)
    {
        front--;
        A[front]=x;
    }
    else{
        for(int i=rear;i>=front;i--)
            A[i+1]=A[i];
        A[front]=x;
        rear++;
    }
    display();
}
void inject(int x)   //insert rear
{
    if(front==0 && rear==size-1)
        printf("DEQueue is full\n");
    else if(rear==-1){
        front=0;
        rear=0;
        A[rear]=x;
    }
    else if(rear<size-1){
        rear++;
        A[rear]=x;
    }
    else{
        for(int i=front;i<=rear;i++)
            A[i-1]=A[i];
        A[rear]=x;
        front--;
    }
    display();
}
void pop()      //delete front
{
    if(front==-1)
        printf("no element present yet!!");
    else if(front==rear)
    {
        printf("delete item is %d\n",A[front]);
        front=-1;
        rear=-1;
    }
    else{
        printf("delete item is %d",A[front]);
        front++;
    }
    display();
}
void reject()       //delete rear
{
    if(front==-1)
        printf("queue is empty\n");
    else if(front==rear)
    {
        printf("delete item is %d",A[rear]);
        front=rear=-1;
    }
    else{
        printf("delete item is %d",A[rear]);
        rear--;
    }
    display();
}
void main()
{
    int choice,item;
    front=rear=-1;
    printf("enter the size of DEqueue");
    scanf("%d",&size);
    do
    {
        printf("enter the choice\n 1.push\n2.inject\n3.pop\n4.reject\n5.display\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("enter the element to insert");
                scanf("%d",&item);
                push(item);
            break;
        
        case 2: printf("enter the element to insert");
                scanf("%d",&item);
                inject(item);
            break;
        case 3: pop();
            break;
        case 4: reject();
            break;
        case 5: display();
                break;
        }
    } while (choice!=6);
}