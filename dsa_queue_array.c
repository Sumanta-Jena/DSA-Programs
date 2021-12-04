//queue using arrays

#include<stdio.h>
#define size 3

typedef struct quarr
{
  int queue[size];
  int front;
  int rear;
  int i;
} qu;


void enqueue (qu * en, int x)
{
  if (en->rear == size - 1)
    {
      printf ("\n Queue is Full");
      return;
    }
  if (en->front == -1)
    {
      en->front=0;
      en->rear=0;
      en->queue[en->rear] = x;
      return;
    }
  en->rear++;
  en->queue[en->rear] = x;
  return;
}


void display (qu * en)
{
  if (en->front == -1)
    {
      printf ("\n Queue is Empty");
      return;
    }
  for (int i = en->front; i < en->rear+1; i++)
    {
      printf ("\n %d", en->queue[i]);
    }
  return;
}

void dequeue (qu * de)
{
  if (de->rear == -1)
    {
      printf ("\n Queue is Empty");
      return;
    }
  printf ("\n The deleted element is %d", de->queue[de->front]);
  if (de->front == de->rear)
    {
      de->front = -1;
      de->rear = -1;
      return;
    }
  de->front++;
  return;

}

void main ()
{
  int x;
  qu q1;
  q1.front = -1;
  q1.rear = -1;
  int ch;
  do
    {
      printf ("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter Option :");
      scanf ("%d", &ch);
      switch (ch)
	{
	case 1:
	  {
	    printf ("Enter the element : ");
	    scanf ("%d", &x);
	    enqueue (&q1, x);
	    break;
	  }
	case 2:
	  {
	    dequeue (&q1);
	    break;
	  }
	case 3:
	  {
	    display (&q1);
	    break;
	  }
	case 4:
	  break;
	default:
	  printf ("Invalid choice");
	}
    }
  while (ch != 4);
}
