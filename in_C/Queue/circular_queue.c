#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Circulr Queue
/*
1) Circular Queue is used because in linear queue of array space is not
efficiently used.
2) In circular queue, front & rear counters are used in such a way
elements can be added when there is space is left i.e space can be used efficiently.
3) In Linear Queue, we use linear increment i++ , j++ or i=i+1
But In Circular Queue, we use circular increment
    i = (i+1) % size;
    i= increment mod size of array
    i.e when i+1 == size => i resets to 0 index i.e circular queue

4) Note: The front index in Circular Queue is always empty
*/

typedef struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
} Queue;

int isFull(Queue *q)
{
    // circular "rear next" is equal to front
    if (q->front == (q->rear + 1) % q->size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(Queue *q)
{
    if (q->rear == q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enQueue(Queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        // Circular Increment
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = val;
        printf("Enqueued %d\n", q->arr[q->rear]);
    }
}

void deQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        // Circular Increment
        q->front = (q->front + 1) % q->size;
        printf("Dequeued %d\n", q->arr[q->front]);
    }
}

int firstValue(Queue *q)
{
    return q->arr[q->front + 1];
}
int lastValue(Queue *q)
{
    return q->arr[q->rear];
}

int peek(Queue *q, int index)
{
    if ((q->front + index) > q->rear || index <= 0)
    {
        return -1;
    }
    else
    {
        return q->arr[q->front + index];
    }
}
void printfCircularQueue(struct Queue *q)
{
    for (int i = q->front + 1; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}
int main()
{
    Queue q;
    q.size = 4;
    q.front = q.rear = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enQueue(&q, 12);
    enQueue(&q, 56);
    enQueue(&q, 34);
    // enQueue(&q, 23);

    deQueue(&q);
    deQueue(&q);
    deQueue(&q);
    // deQueue(&q);

    enQueue(&q, 12);
    enQueue(&q, 56);
    enQueue(&q, 34);
    if (isEmpty(&q))
    {
        printf("Queue Underflow\n");
    }
    if (isFull(&q))
    {
        printf("Queue Overflow\n");
    }

    // q.size=10;
    // if (isEmpty(&q))
    // {
    //     printf("Queue if empty\n");
    // }

    // // enqueue some elements
    // enQueue(&q, 12);
    // enQueue(&q, 56);
    // enQueue(&q, 34);
    // printfCircularQueue(&q);
    // printf("The First element in Queue is: %d\n",firstValue(&q));
    // printf("The last element in Queue is: %d\n",lastValue(&q));
    // printf("The peek element in Queue is: %d\n",peek(&q,2));

    return 0;
}