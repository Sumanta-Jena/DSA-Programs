#include <stdio.h>
#include <stdlib.h>
#define size 10

int adj_mat[size][size];
int visited[size];

//Stack linked list
typedef struct stacknode
{
    int data;
    struct stacknode *next;
}sn;
sn *top = NULL;

void push(int x)
{
    sn *new1 = (sn *) malloc(sizeof(sn));
    new1->data=x;
    new1->next=top;
    top=new1;
    return;
}

int pop()
{
    if(top==NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    sn *ptr = top;
    top=top->next;
    //printf("The deleted element is %d\n",ptr->data);
    int data = ptr->data;
    free(ptr);
    return data;
}


void dfs(int ch)
{
    int nd;
    int x = ch;
    push(ch);
    printf("\nDFS Traversal :");
    while(top!=NULL)
    {
        nd = pop();//Pull the node
        if (visited[nd] == 0) //process the node
        {
            printf("%2d ",nd);
            visited[nd] = 1;
        }

        if (nd == -1)
        {
            break;
        }
        //Add adjacent nodes to stack
        for (int j = 1; j < size; j++)
        {
            if(adj_mat[nd][j] == 1 && visited[j] == 0)
            {
                push(j);
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
    dfs(ch);
}

