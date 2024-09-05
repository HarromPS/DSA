#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;
// Parenthesis matching in an expression

// Creating a structure for stack
class Stack
{
public:
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
void push(class Stack *sp, char ch)
{
    if (isFull(sp))
    {
        cout << "Stack Overflow\n";
        cout << "Cannot push " << ch << " to the stack\n";
    }
    else
    {
        sp->top++;
        sp->arr[sp->top] = ch;
    }
}
int pop(class Stack *sp)
{
    if (isEmpty(sp))
    {
        cout << "Stack Underflow\n";
        return -1;
    }
    else
    {
        // char val=sp->arr[sp->top];
        sp->top--;
        return 1;
    }
}
int parMatch(class Stack *sp, char exp[])
{
    if (sp->arr == NULL)
    {
        return -1;
    }
    int i = 0, x = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '(')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')')
        {
            x = pop(sp);
            if (x == -1)
            {
                break;
            }
        }
        i++;
    }
    if (sp->top > -1)
    {
        x = -1;
        return x;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char exp[] = "3*1-((8+1)";
    class Stack *sp; // sp will just store the address
    // Creating a instance or object of size struct Stack to which it will
    // gonna point.
    sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = sizeof(exp) / sizeof(char); // Total size = no of char in the expression
    sp->top = -1;                          // top =-1 means stack is empty initially
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    printf("Stack has been created successfully\n\n");

    int result = parMatch(sp, exp);
    if (result == -1)
    {
        cout << exp << " ::is an Unbalanced expression\n";
    }
    else
    {
        cout << exp << " is an balanced expression\n";
    }
    return 0;
}
