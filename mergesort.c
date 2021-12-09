#include <stdio.h>
void mergesort(int a[] , int l , int r);
void merge(int a[] , int l , int mid , int r);

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

    //Calling mergesort
    mergesort(a,0,n-1);

    printf("\nFinal sorted array is: ");
    for(int z=0 ; z<n ; z++)
    {
        printf("%2d", a[z]);
    }
}

void mergesort(int a[] , int l , int r)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);

        merge(a,l,mid,r);
    }
}

void merge(int a[] , int l , int mid , int r)
{
    int b[100];
    int i,j,k;
    for(i=l ; i<=r ; i++)
    {
        b[i] = a[i];
    }
    i=l,j=mid+1,k=l;
    while(i<=mid && j<=r)
    {
        if(b[i]<= b[j])
        {
            a[k++] = b[i++];
        }
        else
        {
            a[k++] = b[j++];
        }
    }
    while(i<=mid)
    {
        a[k++] = b[i++];
    }
    while(j<=r)
    {
        a[k++] = b[j++];
    }
}
