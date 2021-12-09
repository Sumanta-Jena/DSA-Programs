#include<stdio.h>
void quicksort(int a[],int left,int right);
int partition(int a[], int left,int right);

void main()
{
    int n,i,j,k, a[100],b[100];
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the number: ");
        scanf("%d", &a[i]);
    }
    printf("\nThe entered array is : ");
    for(i=0 ; i<n ; i++)
    {
        printf("%2d", a[i]);
    }
    printf("\n");
    quicksort(a,0,n-1);

    printf("\nFinal sorted array is: ");
    for(int z=0 ; z<n ; z++)
    {
        printf("%2d", a[z]);
    }
}

void quicksort(int a[],int left,int right)
{
    if(left<right)
    {
        int p = partition(a,left,right);
        quicksort(a,left,p-1);
        quicksort(a,p+1,right);
    }
}

int partition(int a[], int left,int right)
{
    int p = a[left];
    int l = left+1 ;int r = right;

    while(l<r)
    {
        while(a[l]<p && l<right)
        {
            l++;
        }
        while(a[r]>= p && r>left)
        {
            r--;
        }
        if(l<r)
        {
            int temp = a[l];
            a[l] = a[r];
            a[r] = temp;
        }
    }
    if(a[r]<a[left])
    {
        int tmp = a[left];
        a[left] = a[r];
        a[r] = tmp;
        //a[left] = a[r];
        //a[r] = p;
    }

    return r;
}








