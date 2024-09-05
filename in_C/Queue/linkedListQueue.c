#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Linked list is also used to make queue

typedef struct Node
{
    int data;
    struct Node *next;
} Node;
Node *front = NULL, *rear = NULL;
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

int isFull(Node* node)
{
    if (node==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// void enQueue(Node *front, Node *rear, int val)
void enQueue(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (isFull(newNode))
    {
        printf("Queue Full\n");
    }
    else
    {
        newNode->data = val;
        newNode->next = NULL;
        if (isEmpty(front))
        {
            front = rear = newNode;
        }
        else
        {
            (rear)->next = newNode;
            rear = newNode; // rear = rear->next ;
        }
    }
}

int deQueue()
{
    if (isEmpty(front))
    {
        printf("Queue Empty\n");
    }
    else
    {
        Node *temp = front;
        int val = temp->data;
        front = (front)->next;
        free(temp);
        return val;
    }
}
void FirstValue(Node *first)
{
    if (first->next == NULL)
    {
        printf("Empty Queue\n");
    }
    else
    {
        printf("First Element of the Queue is: %d", first->next->data);
    }
}
void lastValue(Node *rear)
{
    if (rear == NULL)
    {
        printf("Empty Queue\n");
    }
    else
    {
        printf("Last Element of the Queue is: %d", rear->data);
    }
}
void traverseQueue()
{
    if (isEmpty(front))
    {
        printf("Queue Empty\n");
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
    enQueue(12);
    enQueue(13);
    enQueue(15);
    enQueue(4);
    deQueue();
    traverseQueue();
    return 0;
}