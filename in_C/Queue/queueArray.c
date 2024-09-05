#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Queue ADT- Discipline - First In First Out(FIFO)
Array Implementation=>

1) enQueue() - move in the element at the last of queue O(1)
2) deQueue() - move out the first element from the queue O(n)/O(1)
3) front() - index of the element next to the element removed from the front
4) rear() - index of the added element in the queue
5) peek() - returns the position of an element at a given index
6) isEmpty() - returns false if queue if empty else returns true
6) isFull() - returns false if queue if not full else returns true
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

void enQueue(struct Queue *q, int value)
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

int deQueue(struct Queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("Queue Underflow\n");
        return a;
    }
    else
    {
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}

void printQueue(struct Queue *q)
{
    for (int i = q->front + 1; i < q->rear + 1; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int peek(struct Queue *q, int i)
{
    if ((q->front) + i > q->rear || i <= 0)
    {
        return -1;
    }
    else
    {
        return q->arr[(q->front) + i];
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

    // check if the queue if empty
    if (isEmpty(&q))
    {
        printf("Queue if empty\n");
    }

    // enqueue some elements
    enQueue(&q, 12);
    enQueue(&q, 56);
    enQueue(&q, 34);
    printQueue(&q);
    printf("The first element of the queue is: %d\n", firstValue(&q));
    int result = peek(&q, 3);
    if (result == -1)
    {
        printf("Invalid Position\n");
    }
    else
    {
        printf("Peek element: %d\n", result);
    }
    printf("Dequeue %d\n", deQueue(&q));
    printf("The first element of the queue is: %d\n", firstValue(&q));

    printf("Dequeue %d\n", deQueue(&q));
    enQueue(&q, 23);
    enQueue(&q, 96);
    enQueue(&q, 5);
    printf("\n");
    printQueue(&q);

    result = peek(&q, 3);
    if (result == -1)
    {
        printf("Invalid Position\n");
    }
    else
    {
        printf("Peek element: %d\n", result);
    }
    printf("The last element of the queue is: %d\n", lastValue(&q));
    enQueue(&q, 55);
    printf("The last element of the queue is: %d\n", lastValue(&q));

    if (isEmpty(&q))
    {
        printf("Queue if empty\n");
    }
    return 0;
}