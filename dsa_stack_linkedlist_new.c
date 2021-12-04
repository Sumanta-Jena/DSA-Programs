#include <stdio.h>
#include <stdlib.h>

typedef struct stacknode
{
    int data;
    struct stacknode *next;
}ll;

ll *push(ll *temp, int x)
{
    ll *new1 = (ll *) malloc(sizeof(ll));
    new1->data=x;
    new1->next=NULL;

        new1->next=temp;
        temp=new1;
        return temp;
}

void display(ll *temp)
{
    if(temp==NULL)
    {
        printf("Stack Underflow");
        return;
    }
    while(temp!=NULL)
    {
        printf("\n%d",temp->data);
        temp = temp->next;
    }
}

ll *pop(ll *temp)
{
    if(temp==NULL)
    {
        printf("Stack Underflow\n");
        return temp;
    }

    temp=temp->next;

    return temp;
}

int main()
{
    int ch,no;
    ll *top = NULL;
    int flag = 1;
    while (flag!=0)
    {
        printf("\nEnter one of the following options: \n");
        printf(" 1-Display\n 2-Push\n 3-Pop\n 4-Quit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case(1):
            display(top);
            break;

        case(2):
            printf("Enter the Number to be pushed :");
            scanf("%d",&no);
            top = push(top,no);
            break;

        case(3):
            top = pop(top);
            break;
        case(4):
            flag = 0;
            break;
        default:
            printf("Please enter valid input\n");
            break;
        }
    }
    return 0;
}
