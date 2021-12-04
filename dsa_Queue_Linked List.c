//Queue using Linked List

#include<stdio.h>
#include<stdlib.h>

typedef struct qlink
{
    int data;
    struct qnode *next;
} ql;

ql *front=0;
ql * rear=0;

void enqueue(int x)
{
    ql * new1 = (ql*)malloc(sizeof(ql));
    new1->data=x;
    new1->next=0;
    if(front==0 && rear==0)
    {
        front=rear=new1;
        return;
    }
    rear->next=new1;
    rear = new1;
    return;
}

void display()
{
    ql *temp;
    if(front==0)
    {
        printf("Queue Empty\n");
        return;
    }
    temp = front;
    printf("Elements are :");
    while(temp!=0)
    {
        printf("%4d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void dequeue()
{
    ql *temp;
    temp=front;

    if(front==0)
    {
        printf("Queue Empty\n");
        return;
    }

    printf("The deleted item is: %d\n",front->data);
    front=front->next;
    free(temp);
    return;
}

void main()
{
    int x;
    int ch;
    do
    {
        printf("\nEnter one of the following options: \n");
        printf(" 1-Enqueue \n 2-Dequeue \n 3-Display \n 4-Quit\n");

        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
        {
            printf("Enter the element : ");
            scanf("%d",&x);
            enqueue(x);
            break;
        }
        case 2:
        {
            dequeue();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
            break;
        default:
            printf("Invalid choice");
        }
    }
    while(ch!=4);
}
