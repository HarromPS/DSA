#include <iostream>
#include <cstdio>
using namespace std;
// Circular Queue-
/*
1) Drawback of the queue is that the space is inefficiently used.
2) When front=rear==> queue becomes full at the same time it is empty
as the previous indexes can be used to store elements.
3) To solve this issue Circular Queue can be implemented.
4) In Linear Queue, we used the linear increments of the counters
5) In Circular Queue, we used the circular increments of the counters.
    => i= (i+1) % size;
    => counter = increment mod size
i.e when counter reaches the size it resets to the starting index = 0
*/
// Class for the Circular Queue Implementation
typedef class CircularQueue
{
public:
    int size;
    int front;
    int rear;
    int *arr;
} CircularQueue;

// Methods of Circular Queue
int isFull(CircularQueue *q)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(CircularQueue *q)
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

void enQueue(CircularQueue *q, int val)
{
    if (isFull(q))
    {
        cout << "Queue Overflow\n";
    }
    else
    {
        // Circular Increment
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = val;
        cout << "Enqueued " << q->arr[q->rear] << endl;
    }
}

void deQueue(CircularQueue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue Underflow" << endl;
    }
    else
    {
        // Circular Increment
        q->front = (q->front + 1) % q->size;
        printf("DeQueued: %d\n", q->arr[q->front]);
    }
}

int firstValue(CircularQueue *q)
{
    return q->arr[q->front + 1];
}
int lastValue(CircularQueue *q)
{
    return q->arr[q->rear];
}
void peekValue(CircularQueue *q, int index)
{
    if ((q->front + index) > q->rear || (index <= 0))
    {
        cout<<"Invalid Position\n";
    }
    else
    {
        cout<<"Element at position "<<index<<" is: "<<q->arr[q->front + index]<<endl;
    }
}

void printQueue(CircularQueue *q)
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
    CircularQueue q;
    q.size = 10;
    q.front = q.rear = 0; // if front=-1 then the queue will never end
                          // as rear+1 mod size != -1
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

    deQueue(&q);
    deQueue(&q);

    cout << "The first value: " << firstValue(&q) << endl;
    cout << "The last value: " << lastValue(&q) << endl;

    enQueue(&q, 82);
    enQueue(&q, 7);
    enQueue(&q, 87);
    printQueue(&q);
    peekValue(&q,0);
    return 0;
}