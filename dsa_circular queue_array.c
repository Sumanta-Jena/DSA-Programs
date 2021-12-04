//circular queue using arrays

#include<stdio.h>
#define N 5

typedef struct quarr
{
  int queue[N];
  int front;
  int rear;
} qu;


void enqueue (qu * en, int x)
{
  if (en->rear == -1 && en->front == -1)
    {
      en->front=0;
      en->rear=0;
      en->queue[en->rear] = x;
    }
    else if((en->rear+1)%N== en->front)
    {
        printf("Queue is full \n");
    }
    else{
        en->rear = (en->rear+1)%N;
        en->queue[en->rear]=x;
    }
}


void display (qu * di)
{
    int i = di->front;
  if (di->front == -1 && di->rear == -1)
    {
      printf ("\n Queue is Empty");
      return;
    }
    else{
        printf("Queue is : ");
        while(i != di->rear)
        {
            printf("%d",di->queue[i]);
            i=(i+1)%N;
        }
        printf("%d",di->queue[di->rear]);
    }
}

void dequeue (qu * de)
{
  if (de->rear == -1 && de->front == -1)
    {
      printf ("\n Queue is Empty");
    }

    else if(de->front == de->rear)
    {
        de->front = -1;
        de->rear = -1;
    }

    else{
        printf ("\n The deleted element is %d", de->queue[de->front]);
        de->front= (de->front+1)%N;
    }

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
