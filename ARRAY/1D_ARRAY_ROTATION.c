#include <stdio.h>

void print1darray(int r,int a[r])
{
    for (int j = 0; j <r; j++) 
        printf("%d | ",a[j]);
    printf("\n");
}

void rotate(int r,int rot,int a[r])
{
    if(rot==0)
    {
        return ;
    }
    else
    {
        rotate(r,rot-1,a);
        printf("Array after rotation %d :  | ",rot);
        int temp=a[0];
        for(int i=0;i<r-1;i++)
            a[i]=a[i+1];
        a[r-1]=temp;

        print1darray(r,a);
    }
}



int main() 
{
    int r,c,rot;
    printf("Enter number of elements : ");
    scanf("%d",&r);

    int ar[r];

    printf("Enter elemetns row wise :");
    for (int i = 0; i < r; i++)  
            scanf("%d",&ar[i]);

    printf("Enter number of rotations : ");
    scanf("%d",&rot);

    printf("Original array is      :  | ");
    print1darray(r,ar);

    rotate(r,rot,ar);


    return 0;
}
