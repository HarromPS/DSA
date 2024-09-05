#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// DE-Queue (Double Ended Queue)
/*
1) Do not follows FIFO principle.
2) Insertion can be done from both front & rear.
3) Deletion can be done from both front & rear.
4) Two Types of DE-Queue-
    a) Restricted Input DE-Queue=> Insertion from front is not allowed.
    a) Restricted Output DE-Queue=> Deletion from rear is not allowed.
5) Opertions-
    1) isFull()     3) enQueueRear() // same as normal Queue
    2) isEmpty()    4) deQueueFront()
    5) enQueueFront()
    6) deQueueRear()
*/

struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct Queue *q)
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

int isEmpty(struct Queue *q)
{
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
        return 1;
    }
    else
    {
        return 0;
    }
}

int backPlace(struct Queue *q)
{
    if (q->front < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int backIsFront(struct Queue *q)
{
    if ((q->rear - 1) == q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enQueueRear(struct Queue *q, int value) // same as normal queue
{
    if (isFull(q))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = value;
        printf("Enqueued %d\n", q->arr[q->rear]);
    }
}

void deQueueFront(struct Queue *q) // same as normal queue
{
    if (isEmpty(q))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        q->front += 1;
        printf("Dequeued from front: %d\n", q->arr[q->front]);
    }
}

void enQueueFront(struct Queue *q, int val)
{
    if (backPlace(q))
    {
        printf("Cannot place before\n");
    }
    else
    {
        q->arr[q->front] = val;
        q->front = q->front - 1;
        printf("Enqueued: %d\n", q->arr[q->front + 1]);
    }
}

void deQueueRear(struct Queue *q)
{
    if (backIsFront(q))
    {
        printf("Cannot remove from before\n");
    }
    else
    {
        q->rear = q->rear - 1;
        printf("Dequeued from Rear: %d\n", q->arr[q->rear+1]);
    }
}

void printQueue(struct Queue *q)
{
    for (int i = q->front + 1; i < q->rear + 1; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

void peek(struct Queue *q, int i)
{
    if ((q->front) + i > q->rear || i <= 0)
    {
        printf("Invalid Position\n");
    }
    else
    {
        printf("%d\n",q->arr[(q->front) + i]);
    }
}

int firstValue(struct Queue *q)
{
    return q->arr[(q->front) + 1];
}

int lastValue(struct Queue *q)
{
    return q->arr[q->rear];
}
int main()
{
    struct Queue q;
    q.size = 10;
    q.front = q.rear = -1;
    q.arr = (int *)malloc(sizeof(int *) * q.size);

    enQueueRear(&q, 12);
    enQueueRear(&q, 56);
    enQueueRear(&q, 9);
    enQueueRear(&q, 6);
    enQueueRear(&q, 5);
    deQueueFront(&q);
    enQueueFront(&q, 34);
    deQueueRear(&q);
    printQueue(&q);
    printf("The first value is: %d\n",firstValue(&q));
    printf("The last value is: %d\n",lastValue(&q));
    peek(&q,3);
    return 0;
}