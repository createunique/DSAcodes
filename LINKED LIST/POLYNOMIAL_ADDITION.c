#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coef;
    int pow;
    struct Node* next;
}node;


node* create_node(int co,int po) {
    node* newnode = (node*)malloc(sizeof(struct Node));
    newnode->coef = co;
    newnode->pow = po;
    newnode->next = NULL;
    return newnode;
}

node* insert_node(node** head, int coe,int pow) {
    node* newnode = create_node(coe,pow);
    
    if (*head == NULL) 
        *head = newnode; 
    else 
        newnode->next = *head ;

    return newnode;
}


void displayList(node* head) {
    node* current = head;

    while (current != NULL) 
    {
        if(current->pow == 0)
            printf("%d", current->coef);
        else if(current->pow == 1)
            printf("%dx", current->coef);
        else
            printf("%dx^%d", current->coef,current->pow);
        
        current = current->next;

        if(current!=NULL)
                printf("+");
                
    }
    printf("\n");
}


void bubbleSort(node* head) 
{
    int swap;
    node* ptr1;
    node* lptr = NULL;

    if (head == NULL)
        return;

    do {
        swap = 0;
        ptr1 = head;

        while (ptr1->next != lptr) 
        {
            if (ptr1->pow < ptr1->next->pow) 
            {
                int temp1 = ptr1->coef;
                int temp2= ptr1->pow;
                ptr1->coef = ptr1->next->coef;
                ptr1->pow = ptr1->next->pow;
                ptr1->next->coef = temp1;
                ptr1->next->pow = temp2;
                swap = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swap);
}



void add(node*p1,node* p2,node* res)
{

    while(p1 !=NULL || p2 !=NULL)
    {
            
            if(p1->pow == p2->pow  && (p1 !=NULL && p2 !=NULL))
            {
                res->coef = p1->coef+p2->coef;
                res->pow=p1->pow;
                p1=p1->next;
                p2=p2->next;
            }
            else if(p1->pow > p2->pow || (p1 !=NULL && p2 ==NULL))
            {
                res->coef = p1->coef;
                res->pow=p1->pow;
                p1=p1->next;
            }
            else 
            {
                res->coef = p2->coef;
                res->pow=p2->pow;
                p2=p2->next;
            }

            if(p1==NULL && p2==NULL)
                return ;

            res->next=create_node(0, 0);
            res=res->next;
    }

}


int main() 
{
    node* num1 ,*num2, *res, *temp;
    num1=num2=res=temp=NULL;
    
    res=create_node(0,0);

    int powr,cof,i=1;
    printf("Enter 1st equation ( 0 -> end of equation ) : \n");

    while (1) 
    {
        printf("Enter coefficient ( 00 -> end of equation ) : ");
        scanf("%d",&cof);
    
        if (cof == 0 && i==1)
        { 
            i=2;
            printf("\nEnter 2 for 2nd equation ( 00 -> end of equation ) : \n");
            continue;
        }
        if(cof== 0 && i==2)
            break;

        printf("Enter power : ");
        scanf("%d",&powr);

        if(i==1)
            num1=insert_node(&num1, cof,powr);
        else
            num2=insert_node(&num2, cof,powr);
    }


    bubbleSort(num1);
    bubbleSort(num2);
  
    printf("First number :      ");
    displayList(num1);

    printf("Second number :     ");
    displayList(num2);


    add(num1,num2,res);

    printf("Resultant number :  ");
    displayList(res);

    return 0;
}
