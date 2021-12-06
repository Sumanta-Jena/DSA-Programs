#include<stdio.h>
#include<stdlib.h>
#define size 10
//int adj_mat[10][10];
int adj_mat[size][size];
int visited[size];

typedef struct queue{
    int arr[size];
    int front;
    int rear;
}q;

void enqueue(q *q1,int x)
{
    if(q1->rear==size-1)
    {
        printf("Queue is Full\n");
        return;
    }
    if(q1->rear==-1)
    {
        q1->rear++;
        q1->front++;
        q1->arr[q1->rear]=x;
        return;
    }
    q1->rear++;
    q1->arr[q1->rear]=x;
    return;
}

int dequeue(q *q1)
{
    if(q1->front==-1)
    {
        printf("Queue is Empty\n");
        return -1;
    }
    int nd = q1->arr[q1->front];
    //printf("The deleted element is : %d\n",nd);
    if(q1->front==q1->rear)
    {
        q1->rear=-1;
        q1->front=-1;
        return nd;
    }
    q1->front++;
    return nd;
}

int isEmpty(q *q1){
    if(q1->front == -1){
        return 1;
    }
    return 0;
}

void bfs(q *q1,int ch)
{
    int tp,nd;
    int x = ch;
    visited[ch]=1;
    enqueue(q1,ch);
    printf("\nBFS Traversal :");
    printf("%2d ",ch);
    while(!isEmpty(q1))
    {
        nd = dequeue(q1);
        if (nd == -1)
        {
            break;
        }

        //Instead of size can also use egde but will have to pass it to function or make it global
        for (int j = 1; j <= size; j++)
        {
            if(adj_mat[nd][j] == 1 && visited[j] == 0){
                printf("%2d ", j);
                visited[j] = 1;
                enqueue(q1,j);
            }
        }
    }
}

void main()
{
    q q1;
    q1.front=-1;
    q1.rear=-1;

    for(int tp = 0; tp<size ; tp++)
    {
        visited[tp] = 0;
    }
    int node,edge,source,dest;
    printf("\nEnter number of nodes : ");
    scanf("%d",&node);

    printf("\nEnter number of edges : ");
    scanf("%d",&edge);

    for(int i=1; i<=edge; i++)
    {
        printf("\nEnter Source Node : ");
        scanf("%d",&source);
        printf("Enter Destination Node : ");
        scanf("%d",&dest);
        adj_mat[source][dest]=1;
        adj_mat[dest][source]=1;
    }

    //Printing matrix
    printf("\n The adjacency Matrix is : \n");

    for(int i=1; i<=node; i++)
    {
        printf("%d |",i);
        for(int j=1 ; j<=node;j++)
        {
            printf("\t%d",adj_mat[i][j]);
        }
        printf("\n");
    }

    int ch;
    printf("\nEnter the element you want to start the traversal with : ");
    scanf("%d",&ch);
    bfs(&q1,ch);
}
