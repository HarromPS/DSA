#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

// function to check if the stack is full
int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
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
int isEmpty(struct Node *Node)
{
    if (Node == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// function to push the elements in the stack
struct Node *push(struct Node *top, int d)
{
    if (isFull(top))
    {
        printf("Stack Oveflow\n");
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = d;
        newNode->next = top;
        top = newNode;
        printf("Element pushed in stack: %d\n", top->data);
    }
    return top;
}

// function to pop out the topmost element
int pop(struct Node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        int val = (*top)->data;
        struct Node *temp = (*top);
        (*top) = (*top)->next;
        free(temp);
        return val;
    }
}
void transversal(struct Node *top)
{
    // struct Node* temp=top;
    while (top != NULL)
    {
        printf("(%d)\n", top->data);
        printf(" v\n");
        top = top->next;
    }
    printf("NULL\n");
}
// Peek operation to find the element at the ith position
int stackPeek(struct Node *top, int position)
{
    struct Node *ptr = top;
    for (int i = 0; (i < position - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL && position > 0)
    {
        return (ptr->data);
    }
    else
    {
        return -1;
    }
}
int main()
{
    // In stack of LL "head" is referred as "top"
    struct Node *top;
    top = NULL;
    int ele = 0;
    top = push(top, 10);
    ele += 1;
    top = push(top, 20);
    ele += 1;
    top = push(top, 30);
    ele += 1;
    top = push(top, 40);
    ele += 1;
    transversal(top);
    printf("%d \n", pop(&top));
    transversal(top);
    for (int i = 0; i < ele; i++)
    {
        int r = stackPeek(top, i+1); // Position 1 element
        if (r != -1)
        {
            printf("The element at %d position is: %d\n", i+1,r);
        }
        else
        {
            printf("Position does not exist\n");
        }
    }

    return 0;
}