#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
}node;

//  merging two sorted linked lists
node* merge(node* l1,node* l2)
{
    node* mlist =NULL; // final merged list
    node* nptr =NULL;

    while (l1 != NULL  &&  l2 != NULL)
    {
        if(l1->data  <  l2->data)
        {
            if (mlist == NULL) 
            {
                mlist =l1;
                nptr =l1;
            }
            else 
            {
                nptr->next = l1;
                nptr=l1;
            }
            l1= l1->next;
        }
        else 
        {
            if (mlist == NULL) 
            {
                mlist=l2;
                nptr=l2;
            } 
            else 
            {
                nptr->next=l2;
                nptr=l2;
            }
            l2=l2->next;
        }
    }

    // adding remaining elements from l1 and l2
    while (l1 !=  NULL) 
    {
        nptr->next =  l1;
        nptr =l1;
        l1 =  l1->next;
    }

    while (l2 !=  NULL) 
    {
        nptr->next  =  l2;
        nptr=l2;
        l2=l2->next;
    }

    return mlist;
}


node* mergeSort(node* head) 
{
    if (head == NULL  ||  head->next == NULL) 
        return head; // list with 0 or 1 number
    

    node* ptr1 = head; //before
    node* ptr2 = head->next; //next

    while (ptr2 != NULL) 
    {
        ptr2 = ptr2->next;
        if (ptr2 !=  NULL) 
        {
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
    }

    node* left =head;
    node* right =ptr1->next;
    ptr1->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left,right);
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    node* head = NULL;
    node* temp=NULL;

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) 
    {
        int value;
        scanf("%d", &value);

        
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else 
        {           
            temp->next = newNode;
            temp=temp->next;
        }
    }

    head = mergeSort(head);

    printf("Sorted list: ");
    node* current = head;

    while (current != NULL) 
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");


    return 0;
}
