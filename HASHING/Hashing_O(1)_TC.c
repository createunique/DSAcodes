#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct 
{
    int arr[MAX_SIZE];
    int size;
    int* map;
}temp;

void initialize(temp* ds) 
{
    ds->size= 0;
    ds->map =(int*)calloc(MAX_SIZE, sizeof(int));  // to initialise all with zeroe's

    if (ds->map == NULL)
    {
        printf("Memory allocation failed for initialisation !!!!\n");
        exit(1);
    }
}

void add(temp* ds, int x) 
{
    if (ds->map[x] !=0)  // duplicate Numbers are inserted again
    {
        printf(" %d is already present ! ");
        return;
    }

    int index=(ds->size)+1; 
    ds->arr[index] =x; 
    ds->size++ ;
    ds->map[x]=index;  // in hash map equating number index to non zero
    printf("Successfully added %d \n",x);
}

void removeNumber(temp* ds,int x) 
{
    if (ds->map[x] == 0) // no number was found 
    {
        printf("%d was not found to delete ! ",x);
        return;
    }

    int index = ds->map[x];
    int lastnum = ds->size;
    ds->arr[index]= ds->arr[lastnum];
    ds->size-- ;
    ds->map[ds->arr[index]]=index;
    ds->map[x] =0;
    printf("Successfully removed %d \n",x);
}

int search(temp* ds,int x) 
{
    if (ds->map[x] != 0)
        return ds->map[x];
    return 0;
}

int getRandom(temp* ds) 
{
    int rand_idx = (rand() % (ds->size)) + 1;
    return ds->arr[rand_idx];
}

void printNumbersAndHash(temp* ds) 
{
    int i;    printf("Array Numbers : [ ");
    for (i = 1; i< ds->size; i++) 
    {
        printf("%d , ",ds->arr[i]);
    }
    printf("%d ]\n",ds->arr[i]);

    printf("Hash Table : \n");
    for (int j = 1; j < MAX_SIZE; j++) 
    {
        if (ds->map[j] != 0) {
            printf("[ %d | %d ]\n",j,ds->map[j]);
        }
    }
    printf("\n");
}

int main() 
{
    temp ds;
    initialize(&ds);

    int sel, val;
    srand(time(NULL));

    int index;

    do 
    {
        printf("\nMenu:\n");
        printf("1. Add Number \n");
        printf("2. Remove Number \n");
        printf("3. Search Number\n");
        printf("4. Get Random Number \n");
        printf("5. Print Numbers and Hash Table\n");
        printf("6. Exit\n");
        printf("Enter your selection : ");
        scanf("%d",&sel);

        switch (sel) 
        {
            case 1:
                printf("Enter number to add: ");
                scanf("%d",&val);
                add(&ds,val);
                break;

            case 2:
                printf("Enter number to remove: ");
                scanf("%d",&val);
                removeNumber(&ds,val);
                break;

            case 3:
                printf("Enter number to search: ");
                scanf("%d",&val);
                index = search(&ds,val);

                if (index != 0)
                    printf("Number found at index %d\n",index);
                else
                    printf("Number not found\n");
                
                break;

            case 4:
                val = getRandom(&ds);
                printf("Random number : %d\n",val);
                break;

            case 5:
                printNumbersAndHash(&ds);
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid selection . Please try again.\n");
        }
    } while(sel != 6);

    

    return 0;
}
