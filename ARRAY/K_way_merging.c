#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void merge(int a[],int l[],int ls,int r[],int rs)
{
    int i,j,k;
    i=j=k=0;
   
    while (i<ls && j<rs)
    {
        if (l[i] <= r[j])
            a[k++] = l[i++];
        else
            a[k++] = r[j++];
    }
   
    while (i < ls)
        a[k++] = l[i++];
   
    while (j < rs)
        a[k++] = r[j++];
}

void mergesort(int a[],int n)
{
    if (n <= 1)
        return;

    int m = n/2;
    int left[m];
    int right[n - m];
   
    for (int i=0; i<m; i++)
        left[i]=a[i];

    for (int i = m; i<n ; i++)
        right[i-m] = a[i];

    mergesort(left,m);
    mergesort(right,n-m);
   
    merge(a,left,m,right,n-m);
}

void mergeArrays(int arr[][MAX_SIZE],int k,int size[])
{
    int c = 0;
   
    for (int i = 0; i<k; i++)
        c += size[i];
   
    int merged[c];
    int n = 0;
    for (int i = 0; i < k; i++) 
        for (int j = 0; j < size[i]; j++)
             merged[n++] = arr[i][j];

   
    printf("\nMerged array: ");
    for (int i = 0; i < c; i++) 
        printf("%d ", merged[i]);
    
    mergesort(merged, c);
    printf("\nSorted merged array: ");
    for (int i = 0; i < c; i++)
        printf("%d ", merged[i]);
}

int main()
{
    int n,k;
    do
    {
        printf("enter the number of arrays:");
        scanf("%d",&k);
       
        if (k <= 2)
            printf("\n Please enter more than 2 arrays...!\n");
        else break;
    }while(1);
    
    int arr[k][MAX_SIZE];
    int size[k];
    
    for (int i = 0; i<k; i++)
    {
        printf("\nEnter the size of array %d:",i+1);
        scanf("%d",&size[i]);
       
        for (int j = 0; j<size[i]; j++) 
        {
            printf("Enter value %d:", j + 1);
            scanf("%d",&arr[i][j]);
        }
    }
   
    for (int i=0; i<k; i++) 
    {
        printf("\nArray %d:", i + 1);
        for (int j = 0; j < size[i]; j++)
            printf("%d ", arr[i][j]);        
    }
    
    mergeArrays(arr, k, size);
    return 0;
}
