#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int s, int mid, int e) 
{
    int len1 =mid - s + 1;
    int len2 =e - mid;

    int temp[len1 + len2];

    int i =s; 
    int j= mid + 1;
    int k =0; 

    while (i <=mid && j<= e) 
    {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i <= mid)
        temp[k++] = a[i++];

    while(j <= e)
        temp[k++] = a[j++];

    for(int x=0; x< len1+len2; x++)
        a[s+x] = temp[x];
}

void mgsort(int a[], int s, int e) 
{
    if(s<e)
    {
        int mid= s+(e-s)/2;
    
        mgsort(a, s, mid);
        mgsort(a, mid+1, e);
 
        merge(a, s, mid, e);
    }
}

int find_sum(int arr[], int n, int X)
{
    mgsort(arr,0,n - 1);

    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int tsum = arr[left] + arr[right];

        if (tsum == X)
            return 1; 
        else if (tsum < X)
            left++;
        else 
            right--;
    }

    return 0; 
}

int main() 
{
    int n,ts;
    printf("\nEnter the number of elements : ");
    scanf("%d", &n);

    int a[n];
    printf("\nEnter the elements :\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter the sum to find : ");
    scanf("%d", &ts);

    int result = find_sum(a,n,ts);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    if (result)
        printf("Yes, there exist two integers whose sum is %d\n",ts);
    else
        printf("No, there are no two integers whose sum is %d\n",ts);
    

    return 0;
}
