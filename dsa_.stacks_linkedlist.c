#include <stdio.h>
#include <stdlib.h>

typedef struct stacknode
{
    int data;
    struct stacknode *next;
}s;

s *push(s *temp, int x)
{
    s *new1 = (s *) malloc(sizeof(s));
    new1->data=x;
    new1->next=NULL;

        new1->next=temp;
        temp=new1;
        return temp;
}

void display(s *temp)
{
    if(temp==NULL)
    {
        printf("Stack Underflow");
        return;
    }
    while(temp!=NULL)
    {
        printf("Elements in stack are: \n");
        printf("\n%d",temp->data);
        temp = temp->next;
    }
}

s *pop(s *temp)
{
    if(temp==NULL)
    {
        printf("Stack Underflow\n");
        return temp;
    }
    s *ptr = temp;
    temp=temp->next;
    free(ptr);
    return temp;
}

int main()
{
    int ch,no;
    s *top = NULL;
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
