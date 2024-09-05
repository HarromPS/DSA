#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int isFull(struct Stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct Stack *sp)
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

void push(struct Stack *sp, char value)
{
    if (isFull(sp))
    {
        printf("Stack Overflow\n");
        printf("Cannot push %d to the stack\n", value);
    }
    else
    {
        sp->top++;                // moving to the next index
        sp->arr[sp->top] = value; // sp's -->{array}->sp's top index -value
    }
}

char stackTop(struct Stack *sp)
{
    return sp->arr[sp->top];
}

char pop(struct Stack *sp)
{
    if (isEmpty(sp))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        char val = sp->arr[sp->top];
        sp->top--;
        return val;
    }
}
int Precedence(char exp)
{
    if (exp == '*' || exp == '/')
    {
        return 2;
    }
    else if (exp == '+' || exp == '-')
    {
        return 1;
    }
    else
    {
        return 0;
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
char *infixPostfix(struct Stack *sp, char *infix)
{
    char *postfix = (char *)malloc(strlen((infix) + 1) * sizeof(char));
    int i = 0; // tracks infix expression
    int j = 0; // tracks the postfix expression
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (Precedence(infix[i]) > Precedence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
                // while(Precedence(infix[i]) <= Precedence(stackTop(sp))){
                // postfix[j] = pop(sp);
                // j++;}
                // push(sp,infix[i]);
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
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

    char *newExp = infixPostfix(sp, exp);
    printf("This is a infix expression:%s\n", exp);
    printf("This is a postfix expression:%s\n", newExp);
    return 0;
}
