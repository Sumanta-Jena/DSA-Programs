#include<stdio.h>
#include<stdlib.h>
#define size 10

int adj_mat[size][size];
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

        //Instead of size can also use egde but will have to pass it to function or make it global
        for (int j = 1; j <= size; j++)
        {
            if(adj_mat[nd][j] == 1 && visited[j] == 0){
                printf("%2d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

void main()
{
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
    bfs(ch);
}
