#include <iostream>
#include <cstdio>
using namespace std;

// Class for the Queue Implementation
class Queue
{
public:
    int size;
    int front;
    int rear;
    int *arr;
};

// Methods of Queue
int isFull(class Queue *q)
{
    if (q->rear > q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(class Queue *q)
{
    if (q->rear == q->front)
    {
        q->rear = q->front = -1;
        return -1;
    }
    else
    {
        return 0;
    }
}

void enQueue(class Queue *q, int val)
{
    if (isFull(q))
    {
        cout << "Queue Overflow\n";
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = val;
        cout << "Enqueued " << q->arr[q->rear] << endl;
    }
}

int deQueue(class Queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        cout << "Queue Underflow" << endl;
        return -1;
    }
    else
    {
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}

int firstValue(class Queue *q)
{
    return q->arr[q->front + 1];
}
int lastValue(class Queue *q)
{
    return q->arr[q->rear];
}
int peekValue(class Queue *q, int index)
{
    if (q->front + index > q->rear || index <= 0)
    {
        return -1;
    }
    else
    {
        return q->arr[q->front + index];
    }
}

void printQueue(class Queue *q)
{
    cout << "The Queue is: " << endl;
    for (int i = q->front + 1; i <= q->rear; i++)
    {
        cout << q->arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    // Allocating size & memeory for queue using array implementation
    class Queue q;
    q.size = 10;
    q.front = q.rear = -1;
    q.arr = (int *)calloc(sizeof(int), q.size);

    // if Empty
    if (isEmpty(&q))
    {
        cout << "Queue is Empty\n";
    }
    else
    {
        printQueue(&q);
    }

    enQueue(&q, 10);
    enQueue(&q, 23);
    enQueue(&q, 32);
    enQueue(&q, 54);
    printQueue(&q);

    cout << "Dequeued " << deQueue(&q) << endl;
    cout << "Dequeued " << deQueue(&q) << endl;

    cout << "The first value: " << firstValue(&q) << endl;
    cout << "The last value: " << lastValue(&q) << endl;

    enQueue(&q,82);
    enQueue(&q,7);
    enQueue(&q,87);
    printQueue(&q);
    if(peekValue(&q,3)==-1)
    {
        cout<<"Invalid Position"<<endl;
    }
    else{
        cout<<"Peek value: "<<peekValue(&q,3)<<endl;
    }
    return 0;
}