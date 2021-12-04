// Dequeue linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct qnode
{
 int data;
 struct qnode *next;
} qn;
qn *front=NULL;
qn *rear=NULL;
void enqueuerear(int x)
{
 qn * new1 = (qn*)malloc(sizeof(qn));
 new1->data=x;
 new1->next=NULL;
 if(front==NULL)
 {
 front=new1;
 rear=new1;
 return;
 }
 rear->next=new1;
 rear = new1;
 return;
}
void display()
{
 qn *i;
 if(front==NULL)
 {
 printf("Queue Empty\n");
 return;
 }
 i = front;
 printf("Elements are :");
 while(i!=NULL)
 {
 printf("%4d",i->data);
 i = i->next;
 }
 printf("\n");
}
void dequeuefront()
{
 if(front==NULL)
 {
 printf("Queue Empty\n");
 return;
 }
 qn *temp = front;
 if(front==rear)
 {
 temp = front;
 printf("The deleted item is %d\n",front->data);
 front = NULL;
 rear = NULL;
 free(temp);
 return;
 }
 printf("The deleted item is %d\n",front->data);
 front=front->next;
 free(temp);
 return;
}
void dequeuerear()
{
 if(front==NULL)//Can also use rear for this condition
 {
 printf("Queue Empty\n");
 return;
 }
 qn *temp = front;
 if(front==rear)
 {
 temp = front;
 printf("The deleted item is %d\n",front->data);
 front = NULL;
 rear = NULL;
 free(temp);
 return;
 }
 while(temp->next!=rear)
 {
 temp = temp->next;
 }
 printf("The deleted item is %d\n",rear->data);
 rear = temp;
 temp = rear->next;
 free(temp);
 rear->next = NULL;
 return;
}
void main()
{
 int x;
 int ch;
 do
 {
 printf("\nEnter one of the following options: \n");
 printf("1-Enqueue Rear | 2-Dequeue Front | 3-Dequeue Rear | 4-Display | 5-Quit\n");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:
 {
 printf("Enter the element : ");
 scanf("%d",&x);
 enqueuerear(x);
 break;
 }
 case 2:
 {
 dequeuefront();
 break;
 }
 case 3:
 {
 dequeuerear();
 break;
 }
 case 4:
 {
 display();
 break;
 }
 case 5:
 break;
 default:
 printf("Invalid choice");
 }
 }
 while(ch!=5);
}
