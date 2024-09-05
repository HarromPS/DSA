#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node* top;
// function to check if the stack is full
int isFull(struct Node *top)
{
    struct Node* p=(struct Node*)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// funtion to check if the stack is empty
int isEmpty(struct Node *n)
{
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// function to push the elements in the stack
struct Node* push(struct Node* top,int d)
{
    if(isFull(top))
    {
        printf("Stack Oveflow\n");
    }
    else{
     struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
     newNode->data=d;
     newNode->next=top;
     top=newNode;
     printf("Element pushed: %d\n",top->data);
    }
    return top;
}

// function to pop out the topmost element or last in element
int pop(struct Node** top)  // passing reference
{
    if(isEmpty(*top))
    {
        printf("Stack Underflow\n");
    }
    else{
        int val=(*top)->data;
        struct Node* temp=(*top);
        (*top)=(*top)->next;
        free(temp);
        return val;
    }
}
void transversal(struct Node*top)
{
    while(top!=NULL)
    {
        printf("(%d)->",top->data);
        top=top->next;
    }
    printf("NULL\n");
}
int stackPeek(struct Node* top,int position)
{
    struct Node* ptr=top;
    for(int i=0;(i<position-1 && ptr!=NULL);i++)
    {
        ptr=ptr->next;
    }
    if(ptr!=NULL && position>0)
    {
        return (ptr->data);
    }
    else{
        return -1;
    }
}
// function to rrturn the topmost element
int stackTop()
{
    return top->data;
}
int main()
{
    // In stack of LL "head" is referred as "top"
    top=push(top,10);
    top=push(top,20);
    top=push(top,30);
    top=push(top,40);
    transversal(top);
    printf("Popped element: %d\n",pop(&top));      // call by reference
    transversal(top);
    printf("The topMost element in the stack is: %d\n",stackTop());

    return 0;
}