#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Stack operation using simple array

// Function to check if the stack is empty
int isEmpty(int *arr, int *top, int size)
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
int isFull(int *arr, int *top, int size)
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
int Push(int arr[], int *top, int value, int size)
{
    if (*top == size - 1)
    {
        printf("Stack is in Overflow Condition\n");
        return 0;
    }
    else
    {
        *top++;
        arr[*top] = value;
        printf("The element entered :: %d\n", value);
    }
}
// function to pop element in the stack
int Pop(int arr[], int *top, int size)
{
    if (*top == -1)
    {
        printf("Stack is in Underflow Condition\n");
        return -1;
    }
    else
    {
        int val = arr[*top];
        *top--;
        // free(arr[*top]);
        return val;
    }
}
int main()
{
    int size = 10, top = -1;
    int array[size];
    printf("Before pushing any element\n");
    printf("Empty : %d\n", isEmpty(array, &top, size));
    printf("Full : %d\n", isFull(array, &top, size));
    // Push operation on Stack.
    Push(array, &top, 1, size);
    Push(array, &top, 2, size);
    Push(array, &top, 3, size);
    Push(array, &top, 4, size);
    Push(array, &top, 5, size);
    Push(array, &top, 6, size);

    printf("\nAfter pushing any element\n");
    printf("Empty : %d\n", isEmpty(array, &top, size));
    printf("Full : %d\n", isFull(array, &top, size));
    // Pop operation on Stack.
    int result = Pop(array, &top, size);
    printf("The element removed :: %d\n", result);
    return 0;
}