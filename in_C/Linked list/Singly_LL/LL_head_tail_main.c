#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Implementation of the stack using linked list
// Head of the stack is used for push & pop operation
struct Node
{
    int data;
    struct Node *next;
};

// Function to create nodes in the stack
struct Node *CreateNode(struct Node *head, struct Node **tail, int d)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = d;
    newNode->next = NULL;
    if (head == NULL)
    {
        *tail = newNode;
        head = *tail;
    }
    else
    {
        (*tail)->next = newNode;
        (*tail) = newNode;
        (*tail)->next = NULL;
    }
    return head;
}

// isEmpty operation
int isEmpty(struct Node *head)
{
    if (head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// isFull operation
int isFull(struct Node *tail)
{
    if (tail == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// Function to transverse the linked list stack
int Transverse(struct Node *head)
{
    struct Node *current = head;
    if (head == NULL)
    {
        printf("Stack is Empty\n");
        return 1;
    }
    while (current != NULL)
    {
        printf("(%d)->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head = NULL;
    int sizeStack;
    printf("Enter the size of the stack: ");
    scanf("%d", &sizeStack);
    struct Node *tail = (struct Node *)malloc(sizeStack * sizeof(struct Node));
    tail=NULL;
    // we have to send the references to modify the values of the head &tail
    head = CreateNode(head, &tail, 10);
    head = CreateNode(head, &tail, 20);
    head = CreateNode(head, &tail, 30);
    head = CreateNode(head, &tail, 40);
    Transverse(head);

    return 0;
}