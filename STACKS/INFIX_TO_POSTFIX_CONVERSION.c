// using arrays

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 1000

char stack[MAX];
int top=-1;

void push(char c)
{
    if (top>= MAX-1) 
    {
        printf("Stack overflow \n");
        return ;
    }
    stack[++top] = c;
}

char pop() 
{
    if (top<0) 
    {
        printf("Stack underflow\n");
        return ;
    }
    return stack[top--];
}

int order(char op)
{
    switch(op) 
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1; // if it is not operator
}

void infixToPostfix(const char* infix)
{
    printf("Postfix expression : ");
    for (int i=0; infix[i] !='\0'; ++i) 
    {
        if (infix[i] >= 'a' && infix[i] <='z') 
            printf("%c", infix[i]);
        else if (infix[i] == '(') 
            push(infix[i]);
        else if (infix[i] == ')') 
        {
            while (top >= 0 && stack[top] != '(') 
                printf("%c", pop());
            pop();  
        } 
        else 
        {
            while (top >= 0 && order(stack[top]) >= order(infix[i]))
                printf("%c", pop());
            
            push(infix[i]);
        }
    }
    while (top>= 0)
        printf("%c", pop());
    printf("\n");
}

int main() {
    char infix[1000];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix);

    return 0;
}
