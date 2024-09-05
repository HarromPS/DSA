#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Linked list is also used to make queue

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int isEmpty(Node *front)
{
    if (front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(Node *node)
{
    if (node == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// void enQueue(Node *front, Node *rear, int val)
void enQueue(Node **front, Node **rear, int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Queue is Full\n");
    }
    else
    {
        newNode->data = val;
        newNode->next = NULL;
        if (*front == NULL)
        {
            *front = *rear = newNode;
        }
        else
        {
            (*rear)->next = newNode;
            *rear = newNode; // *rear = *rear->next ;
        }
    }
}

int deQueue(Node **front)
{
    if (*front == NULL)
    {
        printf("Queue Empty\n");
    }
    else
    {
        Node *temp = *front;
        int val = temp->data;
        *front = (*front)->next;
        free(temp);
        return val;
    }
}

void traverseQueue(Node *front)
{
    if (front == NULL)
    {
        printf("Queue is now Empty\n");
        return;
    }
    Node *current = front;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main()
{
    Node *front = NULL, *rear = NULL;
    enQueue(&front, &rear, 12);
    enQueue(&front, &rear, 13);
    enQueue(&front, &rear, 15);
    enQueue(&front, &rear, 4);
    deQueue(&front);
    traverseQueue(front);
    return 0;
}