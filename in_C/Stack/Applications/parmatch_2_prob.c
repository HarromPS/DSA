#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Parenthesis (brackets) matching
// ByteBrew
// Function to check if the stack is empty
int isEmpty(int *top)
{
    // if((*arr)->*top)  // operator -> or ->* applied to "int" instead of
    // to a pointer type
    // if(arr[*top])     // Will work
    if (*top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(int *top, int size)
{
    if (*top == size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// function to push element in the stack
void Push(char *arr, int *top, char value, int size)
{
    if (*top == size - 1)
    {
        printf("Stack Overflow Condition\n");
    }
    else
    {
        *top++;
        arr[*top] = value;
        // printf("The element entered :: %d\n", value);
    }
}
// function to pop element in the stack
int pop(char arr[], int *top, int size)
{
    if (*top == -1)
    {
        printf("Stack Underflow Condition\n");
        return -1;
    }
    else
    {
        char val = arr[*top];
        int x = (int)val;
        *top--;
        // free(arr[*top]);
        return x;
    }
}
// Parenthesis Matching function
int parenthesisMatching(char *exp, char *arr, int *top, int size)
{
    int i = 0, x = 0;
    for (i; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            Push(arr, top, exp[i], size);
        }
        else if (exp[i] == ')')
        {
            x = pop(arr, top, size);
            if (x == -1)
            {
                break;
            }
        }
    }
    if (*top > -1)
    {
        x = -1;
    }
    printf("%s\n",exp);
    if (x == -1)
    {
        printf("Is a Unbalanced Expression\n");
    }
    else
    {
        printf("Is a Balanced Expression\n");
    }

}
int main()
{
    char exp[]="3*2-(8+1)";
    // char exp[]="7-(8(3*9)+11+12))-8)";
    int size = strlen(exp);
    int top = -1;
    char array[20];
    parenthesisMatching(exp,array,&top,size);
    printf("%d\n",size);
    return 0;
}