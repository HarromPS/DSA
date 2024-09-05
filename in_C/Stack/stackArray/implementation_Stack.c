#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Implementation of Stack ADT
// Creating a structure for stack data structure
struct Stack
{
    int size, top;
    int *array;
};
int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}
int isFull(struct Stack *ptr)
{
    if (ptr->top == (ptr->size - 1))
    {
        return 1;
    }
    // if the above code does not returns then the functio will return 0 
    // automatically.
    return 0;
}
int main()
{
    //     struct Stack S;
    //     S.size=10;
    //     S.top=-1;
    //     // Creating a array using dynamic memory allocation
    //     S.array=(int*)malloc(S.size*sizeof(int));

    struct Stack *S;
    S->size = 10;
    (*S).top = -1;
    // Creating a array using dynamic memory allocation
    S->array = (int *)malloc(S->size * sizeof(int));

    // Pushing an element in the stack
    S->array[0] = 1;
    S->top++;
    S->array[0] = 2;
    S->top++;
    S->array[0] = 3;
    S->top++;
    S->array[0] = 4;
    S->top++;
    S->array[0] = 5;
    S->top++;
    S->array[0] = 6;
    S->top++;
    S->array[0] = 7;
    S->top++;
    S->array[0] = 8;
    S->top++;
    S->array[0] = 9;
    S->top++;
    // S->array[0]=10;
    // S->top++;

    // Check if the stack is empty
    // if(boolean_expression)
    /*
        if the boolean expression i.e isEmpty returns 1 means condition is
        true else next code block will be executed.
    */
    if (isEmpty(S))
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The stack is not empty\n");
    }

    if (isFull(S))
    {
        printf("The Stack is full\n");
    }
    else
    {
        printf("The stack is not FUll\n");
    }
    return 0;
}