#include <stdio.h>
#define SIZE 5
struct stackarray
{
    int num[SIZE];
    int top;
}s;

void push(int x)
{
    if(s.top>=SIZE-1)
    {
        printf("\n Stack Overflow");
        return;
    }
    s.top++;
    s.num[s.top]=x;
    return;
}
void pop()
{
    if(s.top==-1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("The deleted element is %d\n",s.num[s.top]);
    s.top--;
    return;
}

void display()
{
    if(s.top==-1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("\nThe elements of the stack are :\n");
    for(int i=s.top; i>=0; i--)
    {
        printf("%d\n",s.num[i]);
    }
    return;
}
int main()
{
    s.top=-1;
    int ch;
    int no;
    int flag = 1;
    while (flag!=0)
    {
        printf("\nEnter one of the following options: \n");
        printf(" 1-Display\n 2-Push\n 3-Pop\n 4-Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case(1):
            display();
            break;

        case(2):
            printf("Enter the Number to be pushed :");
            scanf("%d",&no);
            push(no);
            break;

        case(3):
            pop();
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
