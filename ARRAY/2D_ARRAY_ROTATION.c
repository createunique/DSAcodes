#include <stdio.h>

void rotate(int r,int c,int a[r][c])
{
    r--;
    c--;
    int i,j,temp;
    i=j=0;
    temp=a[0][0];

    while(1)
    {
        if(i<r && j==0)
        {
            a[i][j]=a[i+1][j];
            i++;
        }
        else if(i==r && (j==0 || j<c))
        {
            a[i][j]=a[i][j+1];
            j++;
        }
        else if(j==c && (i==r || i>0) )
        {
            a[i][j]=a[i-1][j];
            i--;
        }
        else if(i==0 && j>1)
        {
            a[i][j]=a[i][j-1];
            j--;
        }
        else
        {
            a[0][1]=temp;
            break;
        }
    }
}

void print2darray(int r,int c,int a[r][c])
{
    printf("Two-dimensional ar:\n");
    for (int i = 0; i < r; i++) 
    {
        for (int j = 0; j <c; j++) 
            printf("%d ", (a[i][j]));
        printf("\n");
    }
}

int main() {
    int r,c;
    printf("Enter number of rows : ");
    scanf("%d",&r);
    printf("Enter number of columns : ");
    scanf("%d",&c);

    int ar[r][c];

    printf("Enter elemetns row wise :");
    for (int i = 0; i < r; i++) 
        for (int j = 0; j < c; j++) 
            scanf("%d",&ar[i][j]);

    print2darray(r,c,ar);
    rotate(r,c,ar);
    print2darray(r,c,ar);   

    return 0;
}
