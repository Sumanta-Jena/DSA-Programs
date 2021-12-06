#include<stdio.h>
#include<stdlib.h>

int isfull(int *harr,int size)
{
    for(int i=0;i<size;i++)
    {
        if(harr[i] == -1)
        {
            return 0;
        }
    }
    return 1;
}

void insert(int *harr,int size)
{
    int i,key,hkey,index;
    printf("\nEnter a value to insert into hash table : ");
    scanf("%d",&key);
    hkey=key%size;

    i=0;
    while(isfull(harr,size)==0)
    {
        //printf("i = %d",i);
        index=(hkey+i*i)%size;
        i++;

        if(harr[index] == -1)
        {
            harr[index]=key;
            break;
        }

        //Here i is how many times we want to run the loop to check if element can be inserted
        if(i>50)
        {
            printf("Element Cannot be inserted\n");
            break;
        }
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
    for(i=0; i<10; i++)
    {
        index=(hkey+i*i)%size;
        if(harr[index]==key)
        {
            printf("Value found at index %d\n",index);
            break;
        }
    }

    if(i == 10)
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
