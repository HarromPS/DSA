#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// PEEK OPERATION
// Creating a structure for stack
struct Stack
{
    int size; // Maximum size-total size
    int top;
    int *arr; // integers pointer for dynamic memory allocation
};
// Creating a functions which will tell whether stack is full
int isFull(struct Stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        printf("Stack is Full: ");
        return 1;
    }
    else
    {
        printf("Stack is not Full: ");
        return 0;
    }
}

// Creating a function which will tell about if stack is Empty
int isEmpty(struct Stack *sp)
{
    if (sp->top == -1)
    {
        printf("Stack is Empty: ");
        return 1;
    }
    else
    {
        printf("Stack is not Empty: ");
        return 0;
    }
}

// Creating a function to push/insert element & update the top
void push(struct Stack *sp, int value)
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
int pop(struct Stack *sp)
{
    if (isEmpty(sp))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        int val = sp->arr[sp->top];
        // free(sp->arr[sp->top]);
        sp->top--;
        return val;
    }
}
// function to find the top element in the stack -- peek
// we can print the elements in the stack
// O(1) -> constant time complexity
int peek(struct Stack *sp, int i) // i=position
{
    if ((sp->top - i + 1) < 0)
    {
        printf("Invalid Position\n");
        return -1;
    }
    else
    {
        // printf("%d\n",sp->top);
        return sp->arr[sp->top - i + 1];
    }
}
int main()                                                                                 
{
    struct Stack *sp; // sp will just store the address
    // Creating a instance or object of size struct Stack to which it will
    // gonna point.
    sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = 10; // Total size is 10
    sp->top = -1;  // top =-1 means stack is empty initially
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n\n");

    // Directly calling the function
    printf("Before pushing any element\n");
    push(sp, 1);
    push(sp, 2);
    push(sp, 4);
    push(sp, 5);
    push(sp, 6);
    push(sp, 7);
    push(sp, 18);
    push(sp, 9);
    push(sp, 9);
    push(sp, 10);
    // push(sp, 11); // Stack oveflow since the size of the full

    // Peek operation
        printf("\nThe value at %d is %d\n",0,peek(sp,0));
        printf("The value at %d is %d\n",11,peek(sp,11));

    printf("The elements from the top is\n");
    for(int j=1;j<=       sp->top+1;j++)
    {
        printf("The value at %d is %d\n",j,peek(sp,j));
    }
    return 0;
}