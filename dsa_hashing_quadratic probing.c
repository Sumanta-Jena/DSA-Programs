//Quadratic probing

#include<stdio.h>
#include<stdlib.h>

void insert(int *arr,int size)
{
    int i,key,hkey,index;
    printf("\nEnter a value to insert : ");
    scanf("%d",&key);
    hkey=key%size;

    for(i=0; i<size; i++)
    {
        index=(hkey+i*i)%size;
        if(arr[index] == NULL)
        {
            arr[index]=key;
            break;
        }
    }

    if(i == size)
    {
        printf("\nElement cannot be inserted\n");
    }
}

void display(int *arr,int size)
{
    int i;
    printf("\n Elements in the hash table are :\n");
    for(i=0; i< size; i++)
    {
        if(arr[i]==NULL)
        {
            printf("\n At index %d \t value = NULL",i);
            continue;
        }
        printf("\n At index %d \t value =  %d",i,arr[i]);
    }
}

void search(int* arr, int size)
{
    int i,key,hkey,index;
    printf("\nEnter element to search : ");
    scanf("%d",&key);
    hkey=key%size;
    for(i=0; i<size; i++)
    {
        index=(hkey+i*i)%size;
        if(arr[index]==key)
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
    int arr[size];
    for(int i=0 ; i<size ; i++)
    {
        arr[i] = NULL;
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
            insert(arr,size);
            break;
        }
        case 2:
        {
            search(arr,size);
            break;
        }
        case 3:
        {
            display(arr,size);
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
