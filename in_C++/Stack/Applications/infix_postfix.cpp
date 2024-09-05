#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;
// Infix Prefix Postfix are the ways to write the expressions
// Infix is a standard way to write the expressions for the human readable forms
// Postfix & Prefix are the ways to write the expressions in the machine readable form.

// Creating a structure for stack
struct Stack
{
    int size; // Maximum size-total size
    int top;
    char *arr; // integers pointer for dynamioc memory allocation
};
int isFull(class Stack *sp)
{
    if (sp->top >= sp->size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(class Stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int precedence(char val)
{
    if (val == '*' || val == '/')
    {
        return 2;
    }
    else if (val == '+' || val == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(class Stack *sp, char ch)
{
    if (isFull(sp))
    {
        cout << "Stack Overflow\nCannot Push\n";
        return;
    }
    else
    {
        sp->top++;
        sp->arr[sp->top] = ch;
    }
}
char pop(class Stack *sp)
{
    if (isEmpty(sp))
    {
        cout << "Stack Underflow\n";
    }
    else
    {
        char val = sp->arr[sp->top];
        sp->top--;
        return val;
    }
}
int isOperator(char val)
{
    if (val == '+' || val == '-' || val == '*' || val == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
char stackTop(class Stack *sp)
{
    return sp->arr[sp->top];
}
char *infixPostfix(class Stack *sp, char *infixExp)
{
    if (sp->arr == NULL)
    {
        cout<<"Empty\n";
    }
    int i = 0, x = 0, j = 0;
    char *postfix = (char *)malloc(sizeof(char) * (strlen(infixExp) + 1));
    while (infixExp[i] != '\0')
    {
        if (!isOperator(infixExp[i]))
        {
            postfix[j] = infixExp[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infixExp[i]) > precedence(stackTop(sp)))
            {
                push(sp, infixExp[i]);
                i++;
            }
            else
            {
                    postfix[j]=pop(sp);
                    j++;
            }
        }
    }
    while(!isEmpty(sp))
    {
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}
int main()
{
    char exp[] = "x-y/z-k*d";
    struct Stack *sp; // sp will just store the address
    // Creating a instance or object of size struct Stack to which it will
    // gonna point.
    sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = sizeof(exp) / sizeof(char); // Total size = no of char in the expression
    sp->top = -1;                          // top =-1 means stack is empty initially
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    printf("Stack has been created successfully\n\n");

    char *result=infixPostfix(sp,exp);
    cout<<result<<endl;
    return 0;
}
