#include<stdio.h>
#include<stdlib.h>
#define size 10

//Linked list for adjacency list
struct node
{
    int vertex;
    struct node * next;
};
struct node *a[size];
int visited[size];
int v,e;

//Array for queue //Maybe use different size for this
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
        struct node *hlpptr1 = a[nd];
        while(hlpptr1 != NULL )
        {
            if(visited[hlpptr1->vertex] == 0)
            {
                visited[hlpptr1->vertex]=1;
                printf("%2d ",hlpptr1->vertex);
                enqueue(q1,hlpptr1->vertex);
            }
            hlpptr1 = hlpptr1->next;
        }
    }
}


struct node * createGraph(struct node * root, int n)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->vertex=n;
    ptr->next=NULL;

    if(root==NULL)
    {
        root=ptr;
    }
    else
    {
        struct node *hlpptr = root;
        while(hlpptr -> next != NULL)
        {
            hlpptr = hlpptr->next;
        }
        hlpptr->next = ptr;
    }
    return root;
}

void main()
{
    q q1;
    q1.front=-1;
    q1.rear=-1;
    int tp;
    for(tp = 0; tp<size ; tp++)
    {
        visited[tp] = 0;
    }
    int j,k,l,n,m;
    printf("\nEnter number of vertices and edges : ");
    scanf("%d%d",&v,&e);

    for(int i=1; i<=v; i++)
    {
        a[i]=NULL;
    }

    for(int i=1; i<=e; i++)
    {
        printf("\nEnter pair of vertices : ");
        scanf("%d%d",&j,&k);
        a[j]=createGraph(a[j],k);
        a[k]=createGraph(a[k],j);
    }

    //Printing
    printf("The Linked list representation of Graph is : \n");
    for(int i=1; i<=v; i++)
    {
        struct node *t;
        t=a[i];
        printf("\n");
        printf("%d | ",i);
        while(t!=NULL)
        {
            printf("->%d ",t->vertex);
            t=t->next;
        }
    }

    int ch;
    printf("\nEnter the element you want to start the traversal with : ");
    scanf("%d",&ch);
    bfs(&q1,ch);
}
