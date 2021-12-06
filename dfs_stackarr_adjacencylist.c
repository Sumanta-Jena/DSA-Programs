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
    int tp,nd;
    int x = ch;
    push(ch);
    printf("\nDFS Traversal :");
    while(s1.top!=-1)//While stack is not empty
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
    s1.top=-1;
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
