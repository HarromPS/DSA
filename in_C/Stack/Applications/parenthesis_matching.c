#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Parenthesis Matching using array of characters

// Creating a structure for stack
struct Stack
{
    int size; // Maximum size-total size
    int top;
    char *arr; // integers pointer for dynamioc memory allocation
};
// Creating a function which will tell whether stack is full
// O(1)=> constant time complexity
int isFull(struct Stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        // printf("Stack is Full: ");
        return 1;
    }
    else
    {
        // printf("Stack is not Full: ");
        return 0;
    }
}

// Creating a function which will tell about if stack is Empty
// O(1)=> constant time complexity
int isEmpty(struct Stack *sp)
{
    if (sp->top == -1)
    {
        // printf("Stack is Empty: ");
        return 1;
    }
    else
    {
        // printf("Stack is not Empty: \n");
        return 0;
    }
}

// Creating a function to push/insert element & update the top
// O(1)=> constant time complexity
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
// Creating a function to pop out the elements, update top & return the
// popped value
// O(1)=> constant time complexity
int pop(struct Stack *sp)
{
    if (isEmpty(sp))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        char val = sp->arr[sp->top];
        // free(sp->arr[sp->top]);
        sp->top--;
        return val;
    }
}
// Function for parenthesis matching
void parMatch(struct Stack *sp, char exp[])
{
    if (sp->arr == NULL)
    {
        return;
    }
    int x = 0, i = 0;
    int pushOp = 0, popOp = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '(')
        {
            push(sp, exp[i]);
            pushOp++;
        }
        else if (exp[i] == ')')
        {
            x = pop(sp);
            popOp++;
            if (x == -1)
                break;
        }

        // sp->arr[i];
        i++;
    }
    // Stack is not empty after the End OF Expression 
    if (sp->top > -1)
    {
        x = -1;
    }
    printf("%s\n", exp);
    printf("%d\n", sp->top);
    if (x == -1)
    {
        printf("Is a Unbalanced Expression\n");
    }
    else
    {
        printf("Is a Balanced Expression\n");
    }
    printf("No of push operations : %d\n", pushOp);
    printf("No of pop operations : %d\n", popOp);
}
int main()
{
    // char exp[] = "7-(8(3*9)+11+12))-8)";
    // char exp[] = "(1*(8-3(7)";
    char exp[] = "(7*8)-3(7)";
    struct Stack *sp; // sp will just store the address
    // Creating a instance or object of size struct Stack to which it will
    // gonna point.
    sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = sizeof(exp) / sizeof(char); // Total size = no of char in the expression
    sp->top = -1;   // top =-1 means stack is empty initially
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    printf("Stack has been created successfully\n\n");

    parMatch(sp, exp);
    return 0;
}
