#include<stdio.h>
#include<stdlib.h>

void insert(int *harr,int size)
{
    int i,key,hkey,index;
    printf("\nEnter a value to insert into hash table : ");
    scanf("%d",&key);
    hkey=key%size;

    for(i=0; i<size; i++)
    {
        index=(hkey+i)%size;
        if(harr[index] == -1)
        {
            harr[index]=key;
            break;
        }
    }

    if(i == size)
    {
        printf("\nElement cannot be inserted\n");
    }
}

void display(int *harr,int size)
{
    int i;
    printf("\n Elements in the hash table are \n");
    for(i=0; i< size; i++)
    {
        if(harr[i]==-1)
        {
            printf("\n At index %d \t value = NULL",i);
            continue;
        }
        printf("\n At index %d \t value =  %d",i,harr[i]);
    }
}

void search(int* harr, int size)
{
    int i,key,hkey,index;
    printf("\nEnter element to search : ");
    scanf("%d",&key);
    hkey=key%size;
    for(i=0; i<size; i++)
    {
        index=(hkey+i)%size;
        if(harr[index]==key)
        {
            printf("Value found at index %d\n",index);
            break;
        }
    }
    if(i == size)
    {
        printf("\nValue not found\n");
    }
}

void main()
{
    int ch,size;
    printf("Enter Size of Array : ");
    scanf("%d",&size);
    int harr[size];
    for(int i=0 ; i<size ; i++)
    {
        harr[i] = -1;
    }

    do
    {
        printf("\nEnter one of the following options: \n");
        printf("1-Insert | 2-Search | 3-Display | 4-Quit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
        {
            insert(harr,size);
            break;
        }
        case 2:
        {
            search(harr,size);
            break;
        }
        case 3:
        {
            display(harr,size);
            break;
        }
        case 4:
            break;
        default:
            printf("Invalid choice");
        }
    }
    while(ch!=4);
}

