#include <stdio.h>
#include <stdlib.h>

int merge(int a[], int s, int mid, int e)
{
    int len1 =mid-s+1;
    int len2 =e-mid;

    int temp[len1 + len2];

    int i = s; 
    int j = mid+1; 
    int k = 0; 
    int invs = 0; 

    while (i <=mid && j <=e)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
            invs += (mid-i+1); 
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= e)
        temp[k++] = a[j++];

    for (int x = 0;x < len1+len2 ;x++)
        a[s+x] = temp[x];

    return invs;
}

int mgsort(int a[],int s,int e)
{
    int invs = 0;

    if(s < e)
    {
        int mid = s + (e-s)/2;

        invs +=mgsort(a,s,mid);
        invs +=mgsort(a,mid + 1,e);

        invs +=merge(a,s,mid,e);
    }

    return invs;
}

int main() 
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);

    int a[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);

    int invs=mgsort(a, 0, n - 1);

    printf("Number of inversions : %d\n", invs);

    return 0;
}
