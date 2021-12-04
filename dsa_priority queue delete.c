#include<stdio.h>
#include<stdlib.h>

struct node
{
    int priority;
    int data;
 struct node *next;
};
struct node*f=NULL;
struct node*r=NULL;
void insert(int x, int pr)
{
 struct node *p=(struct node *)malloc(sizeof(struct node));
 p->data=x;
 p->priority=pr;
 p->next=NULL;
 if(f==NULL)
 {
 f=p;
 r=p;
 return ;
 }
 r->next=p;
 r=p;
 return;
}


void deleten()
{
    struct node *temp=f;
struct node *node2delete;
int x=temp->priority;
 if(f == NULL)//Queue is empty
 {
 printf("The Queue is empty\n");
 return;
 }
 if(f==r)
{
free(f);
f=NULL;
r=NULL;
return;
}
while(temp!=NULL)
{
if(temp->priority<x)
x=temp->priority;
temp=temp->next;
}
if(f->priority==x)
{
node2delete=f;
f=f->next;
free(node2delete);
return;
}

temp=f;
while(temp->next->priority!=x)
temp=temp->next;
node2delete=temp->next;
if(node2delete->next==NULL)
{
r=temp;
r->next=NULL;
free(node2delete);
return;
}
else
{
temp->next=node2delete->next;
free(node2delete);
return;
}

}
void display()
{
 struct node* f1 = f;
 if(f1==NULL)
 {
 printf("The Queue is Empty\n");
 return;
 }
 while(f1!=NULL)
 {
 printf("\n %d\t %d",f1->data,f1->priority);
f1=f1->next;
 }
 return;
}
int main()
{
 int n,v,p,flag=1,ch;

 while(flag!=0)
 {
 printf("\nEnter one of the following number: \n");
 printf("1-Insert | 2-Delete | 3-Display | 4-Quit\n");
 scanf("%d",&ch);
 switch(ch)
 {
 case(1):
 printf("Enter value and priority : ");
 scanf("%d %d",&v,&p);

 insert(v,p);
 display();
 break;
 case(2):
 deleten();
 break;
 case(3):
 display();
 break;
 case(4):
 flag = 0;
 break;
 }
 } }
