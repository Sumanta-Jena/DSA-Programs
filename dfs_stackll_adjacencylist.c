#include <stdio.h>
#include <stdlib.h>
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
    int tp,nd;
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
        struct node *hlpptr1 = a[nd];
        while(hlpptr1 != NULL)
        {
            if(visited[hlpptr1->vertex] == 0)
            {
                push(hlpptr1->vertex);
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
    dfs(ch);
}

