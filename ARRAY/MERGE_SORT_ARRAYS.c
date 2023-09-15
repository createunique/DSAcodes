#include<stdio.h>
#include<stdlib.h>

void merge(int a[], int i, int len1,int b[], int j, int len2, int new[]) 
{
    int m = 0;

    while (i < len1 && j < len2) 
    {
        if (a[i] < b[j]) 
            new[m++] = a[i++];
        else 
            new[m++] = b[j++];        
    }

    while (i < len1)
        new[m++] = a[i++];
    
    while (j < len2)
        new[m++] = b[j++];
    
}

void mergesort(int a[], int s, int e, int new[]) 
{
    if (s == e) {
        new[0] = a[s];
        return;
    }

    int mid = (s + e) / 2;
    int left[mid - s + 1], right[e - mid];
    mergesort(a, s, mid, left);
    mergesort(a, mid + 1, e, right);
    merge(left, s, mid - s + 1,right, mid+1, e - mid+1, new);
}

int main() 
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n], sorted[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    

    mergesort(a, 0, n - 1, sorted);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", sorted[i]);
    
    printf("\n");

    return 0;
}
