#include <iostream>
#include <cstdio>
using namespace std;

// Queue using Linked list
typedef class Node
{
public:
    int data;
    int i;
    class Node *next;
} Node;

int isEmpty(Node *node)
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

void enQueue(Node **front, Node **rear, int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (isFull(newNode))
    {
        cout << "Cannot enQueue " << endl;
    }
    else
    {
        newNode->data = val;
        newNode->next = NULL;
        // check if queue is null - one time condition
        if (*front == NULL)
        {
            *front = *rear = newNode;
            cout << "Enqueued: " << (*rear)->data << endl;
            (*front)->i=0;
            (*rear)->i=0;
            (*rear)->i += 1;
        }
        else
        {
            (*rear)->next = newNode;
            *rear = newNode;
            (*rear)->i += 1;
            cout << "Enqueued: " << (*rear)->data << endl;
        }
    }
}

void deQueue(Node **front, Node **rear)
{
    if (*front == NULL)
    {
        return;
    }
    else
    {
        int val = (*front)->data;
        *front = (*front)->next;
        (*front)->i += 1;
        cout << "Dequeued: " << val << endl;
    }
}

void printQueue(Node *front)
{
    cout << "Printing Queue::" << endl;
    if (front == NULL)
    {
        cout << "Empty" << endl;
    }
    Node *current = front;
    while (current != NULL)
    {
        cout << current->data << "->";
        current = current->next;
    }
    cout << "NULL" << endl;
}

// void peekValue(Node *front, Node *rear, int index)
// {
//     if (front == NULL)
//     {
//         cout << "Empty" << endl;
//     }
//     cout<<front->i<<endl;
//     cout<<rear->i<<endl;
//     if (front->i + index > rear->i - 1 || index <= 0)
//     {
//         cout << "Invalid Position" << endl;
//     }
// }
void firstValue(Node *front)
{
    if (front == NULL)
    {
        cout << "Empty" << endl;
    }
    else
    {
        cout << "First Element: " << front->data<<endl;
    }
}
void lastValue(Node *rear)
{
    if (rear == NULL)
    {
        cout << "Empty" << endl;
    }
    else
    {
        cout << "Last Element: " << rear->data<<endl;
    }
}
int main()
{
    Node *front = NULL, *rear = NULL;

    enQueue(&front, &rear, 12);
    enQueue(&front, &rear, 23);
    enQueue(&front, &rear, 14);
    enQueue(&front, &rear, 54);
    printQueue(front);
    deQueue(&front,&rear);
    deQueue(&front,&rear);
    deQueue(&front,&rear);
    printQueue(front);
    
    enQueue(&front, &rear, 14);
    enQueue(&front, &rear, 8);
    printQueue(front);

    firstValue(front);
    lastValue(rear);
    // peekValue(front,rear,3);
    return 0;
}