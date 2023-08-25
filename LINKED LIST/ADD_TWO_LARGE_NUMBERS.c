#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}node;

node* create_node(int value) {
    node* newnode = (node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

node* insert_node(node** head, int value) {
    node* newnode = create_node(value);
    
    if (*head == NULL) 
        *head = newnode; 
    else 
        newnode->next = *head ;

    return newnode;
}

void displayList(node* head) {
    node* current = head;

    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
    }
    printf("\n");
}

node* add(node*p1,node* p2,node* res)
{
    int c=0;

    while(p1 !=NULL || p2 !=NULL)
    {
        if(p1 !=NULL && p2 !=NULL)
        {
            res->data=(p1->data+p2->data+c)%10;
            c=(p1->data+p2->data+c)/10;
            p1=p1->next;
            p2=p2->next;
        }
        
        else if(p1 !=NULL && p2 ==NULL)
        {
            res->data=(p1->data+c)%10;
            c=(p1->data+c)/10;
            p1=p1->next;
        }
        else
        {
            res->data=(p2->data+c)%10;
            c=(p2->data+c)/10;
            p2=p2->next;
        }
        node* newnode=(node*)malloc(sizeof(node));
        newnode->next=res;
        res=newnode;
    }
    if(c==0)
        res=res->next;
    else
        res->data=c;

    return res;
}

node* rev(node** head)
{
    node* current=*head;
    node* prev=NULL;
    node* next=NULL;
    
    while(current !=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}

int main() {
    node* num1 = NULL;
    node* num2 = NULL;
    node* res=NULL;
    res=(node*)malloc(sizeof(node));
    res->next=NULL;
    
    char ch;
    printf("Enter the first number : ");

    while (1) {
        ch = getchar();
        if (ch == '\n' || ch == ' ') 
            break;

        num1=insert_node(&num1, ch - '0');
    }

    printf("Enter the second number : ");
    while (1) {
        ch = getchar();
        if (ch == '\n' || ch == ' ')
            break;

        num2=insert_node(&num2, ch - '0');
    }

    res=add(num1,num2,res);
    
    num1=rev(&num1);
    printf("First number :      ");
    displayList(num1);

    num2=rev(&num2);
    printf("Second number :     ");
    displayList(num2);

    
  
    printf("Resultant number :  ");
    displayList(res);

    return 0;
}
