#include <iostream>
#include <cstdio>
using namespace std;
// Double Ended Queue (DE-Queue)
/*
1) Double Ended Queue Do Not Follow FiFO
2) Insertion can be done from both front & rear
3) Deletion can be done from both front & rear
4) Two types of DE-Queue-
    a) Restricted Input DE-Queue=> Insertion can not be done from front
    b) Restricted Output DE-Queue=> Deletion can not be done from rear
5) Methods =
    1) isEmpty()    2) isFull()
    3) enQueueRear()    4) enQueueFront()
    5) deQueueFront()   6) deQueueRear()
    7) backIsFront()    8) backPlace()
*/
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


// Some more methods of DE-Queue 
int backPlace(Queue* q)
{
    if(q->front < 0)
    {
        return 1;
    }
    else{
        return 0;
    }
}
void enQueueFront(class Queue *q, int val)
{
    if (backPlace(q))
    {
        cout << "Cannot Enqueue\n";
    }
    else
    {
        q->arr[q->front]=val;
        q->front--;
        cout << "Enqueued " << q->arr[q->front+1] << endl;
    }
}
int backIsFront(Queue* q)
{
    if(q->rear-1 == q->front)
    {
        return 1;
    }
    else{
        return 0;
    }
}
void deQueueRear(class Queue *q)
{
    if (backIsFront(q))
    {
        cout << "Cannot Dequeue" << endl;
    }
    else
    {
        q->rear--;
        cout << "Queueed: " << q->arr[q->rear] << endl;
    }
}

// Same as normal Queue
void enQueueRear(class Queue *q, int val)
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

void deQueueFront(class Queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        cout << "Queue Underflow" << endl;
    }
    else
    {
        q->front++;
        cout << "Queueed: " << q->arr[q->front] << endl;
    }
}

void firstValue(class Queue *q)
{
    cout << "First Value :" << q->arr[q->front + 1] << endl;
}
void lastValue(class Queue *q)
{
    cout << "First Value :" << q->arr[q->rear] << endl;
}
void peekValue(class Queue *q, int index)
{
    if (q->front + index > q->rear || index <= 0)
    {
        cout << "Invalid Position" << endl;
    }
    else
    {
        cout << "Element is: " << q->arr[q->front + index] << endl;
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

    enQueueRear(&q,12);
    enQueueRear(&q,34);
    enQueueRear(&q,54);
    enQueueRear(&q,523);
    printQueue(&q);
    deQueueFront(&q);
    deQueueFront(&q);
    deQueueFront(&q);

    enQueueFront(&q,45);
    enQueueFront(&q,43);
    enQueueFront(&q,21);
    printQueue(&q);

    firstValue(&q);
    lastValue(&q);
    peekValue(&q,2);

    return 0;
}