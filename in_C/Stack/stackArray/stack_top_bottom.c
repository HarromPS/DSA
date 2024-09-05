#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Creating a structure for stack
struct Stack{
    int size; // Maximum size-total size
    int top;
    int *arr; // integers pointer for dynamioc memory allocation
};

// Stack top & stack bottom operations
// stackTop() - O(1)=> top most element of the stack 
// stackBottom() - O(1) => bottom most element of the stack 

int stackTop(struct Stack* sp)
{
    return sp->arr[sp->top];
}

int stackBottom(struct Stack* sp)
{
    return sp->arr[0];
}
// Creating a function which will tell whether stack is full
// O(1)=> constant time complexity
int isFull(struct Stack *sp){
    if(sp->top==sp->size-1){
        printf("Stack is Full: ");
        return 1;
    }
    else{
        printf("Stack is not Full: ");
        return 0;
    }
}

// Creating a function which will tell about if stack is Empty 
// O(1)=> constant time complexity
int isEmpty(struct Stack*sp){
    if(sp->top==-1){
        printf("Stack is Empty: ");
        return 1;
    }
    else{
        printf("Stack is not Empty: ");
        return 0;
    }
}

// Creating a function to push/insert element & update the top
// O(1)=> constant time complexity
void push(struct Stack *sp,int value){
    if(isFull(sp)){
        printf("Stack Overflow\n");
        printf("Cannot push %d to the stack\n",value);
    }
    else{
        sp->top++;  // moving to the next index 
        sp->arr[sp->top]=value; // sp's -->{array}->sp's top index -value
    }
}
// Creating a function to pop out the elements, update top & return the 
// popped value
// O(1)=> constant time complexity
int pop(struct Stack *sp){
    if(isEmpty(sp)){
        printf("Stack Underflow\n");
    }
    else{
        int val=sp->arr[sp->top];
        //free(sp->arr[sp->top]);
        sp->top--;
        return val;
    }
}

int main(){
    struct Stack *sp; // sp will just store the address
    // Creating a instance or variable of size struct Stack to which it will
    // gonna point.
    sp=(struct Stack*)malloc(sizeof(struct Stack));
    sp->size=10;    // Total size is 10 
    sp->top=-1;     // top =-1 means stack is empty initially
    sp->arr=(int*)malloc(sp->size*sizeof(int));
    printf("Stack has been created successfully\n\n");

    // Directly calling the function 
    printf("Before pushing any element\n");
    printf("%d\n",isEmpty(sp));
    printf("%d\n",isFull(sp));
    push(sp,1);
    push(sp,2);
    push(sp,4);
    push(sp,5);
    push(sp,6);
    push(sp,7);
    push(sp,8);
    push(sp,9);
    push(sp,9);
    push(sp,10);
    // push(sp,11);    // Stack oveflow since the size of the full 

    printf("\nAfter pushing an element\n");
    printf("%d\n",isEmpty(sp));
    printf("%d\n",isFull(sp));

    printf("\nAfter popping element from the stack\n");
    // LAST IN FIRST OUT
    // printf("Popped %d from the stack\n",pop(sp));

    printf("The Topmost element sp->arr[sp->top] in the stack is : %d\n",stackTop(sp));
    printf("The Bottommost element sp->arr[0] in the stack is : %d\n",stackBottom(sp));
    return 0;
}