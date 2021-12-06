#include<stdio.h>
#include<stdlib.h>
#define size 10

int adj_mat[size][size];
int visited[size];

//Array for stack
struct stackarr
{
    int num[size];
    int top;
};
struct stackarr s1;

void push(int x)
{
    if(s1.top == size-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    s1.top++;
    s1.num[s1.top]=x;
    return;
}

int pop()
{
    if(s1.top==-1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    //printf("The deleted element is %d\n",s1.num[s1.top]);
    int node = s1.num[s1.top];
    s1.top--;
    return node;
}

void dfs(int ch)
{
    int nd;
    int x = ch;
    push(ch);
    printf("\nDFS Traversal :");
    while(s1.top!= -1)//While stack is not empty
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
    s1.top=-1;
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

