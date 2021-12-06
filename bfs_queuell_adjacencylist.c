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
int v,e;
int visited[size];

//Linked list for queue
typedef struct qnode
{
    int data;
    struct qnode *next;
}qn;
qn *front=NULL;
qn * rear=NULL;

void enqueue(int x)
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

int dequeue()
{
    if(front==NULL)
    {
        rear = NULL;
        front = NULL;
        printf("Queue Empty\n");
        return -1;
    }
    qn *temp;
    temp=front;
    int tmp;
    tmp = front->data;
    front=front->next;
    free(temp);
    return tmp;
}

void bfs(int ch)
{
    int tp,nd;
    int x = ch;
    visited[ch]=1;
    enqueue(ch);
    printf("\nBFS Traversal :");
    printf("%2d ",ch);
    while(front!=NULL)
    {
        nd = dequeue();
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
                enqueue(hlpptr1->vertex);
            }
            hlpptr1 = hlpptr1->next;
        }
    }
}

//For Adjacency list
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
    bfs(ch);
}
