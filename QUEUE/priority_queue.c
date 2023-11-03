#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    int data;
    int pty;
    struct Node* next;
}node;

node* rear = NULL;
node* front = NULL;

void enqueue() 
{
    int newval,pt;
    node* temp=front;
    node* bef=front;
    printf("\nEnter new data: ");
    scanf("%d", &newval);
    
    printf("Enter priority : ");
    scanf("%d",&pt);

    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = newval;
    newnode->pty=pt;
    newnode->next = NULL;
    
    /*
        if(newnode->pty == front->pty)
        {
            newnode->next=temp->next;
            temp->next=newnode;
        }
    */

    if (rear == NULL)
        rear = front = newnode;
    else 
    {
        
        if(newnode->pty < front->pty )
        {
            
            newnode->next=front;
            front=newnode;
        }
        else
        {
            
            while((newnode->pty > temp->pty || newnode->pty == temp->pty) && temp->next !=NULL )
            {
                bef=temp;
                temp=temp->next;
            }
            
            if(newnode->pty >= temp->pty )
            {
                rear->next=newnode;
                rear=rear->next;
            }
            else
            {
                newnode->next=bef->next;
                bef->next=newnode;
            }
        }
    }

    printf("Data enqueued successfully.\n");
}

void dequeue() 
{
    if (front == NULL) 
        printf("\nQueue is empty.\n");
    else 
    {
        node* temp = front;
        int delnum = front->data;
        front = front->next;

        free(temp);

        printf("\nRemoved element: %d\n", delnum);

        if (front == NULL) 
            rear = NULL;
        
    }
}

void display() 
{
    if (front == NULL) 
        printf("\nQueue is empty !\n");
    else
    {
        printf("\nElements in the queue : \n");
        printf("|          |\n|----------|\n");
        node* current = front;
        while (current != NULL) 
        {
            
            printf("|  %d | %d  |\n|----------|\n", current->data,current->pty);
            current = current->next;
        }
        printf("|          |\n");
    }
}

int main() 
{
    int sel;

    while (1) 
    {
        printf("\n\t***** QUEUE OPERATIONS *****\t\n");
        printf("\t1. Enqueue\n");
        printf("\t2. Dequeue\n");
        printf("\t3. Display\n");
        printf("\t4. Exit\n\n");
        printf("\tEnter your choice : ");
        scanf("%d", &sel);

        switch (sel) 
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice.Please enter a valid option.\n");
        }
    }

    return 0;
}
