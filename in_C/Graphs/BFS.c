#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* BFS(Breadth first search)
=> Data Structure used is Queue.
*/

typedef struct Queue
{
    int size;
    int front, rear;
    int *arr;
} Queue;

int isEmpty(Queue *q)
{
    if (q->front == q->rear)
    {
        return 1;
    }
    return 0;
}

int isFull(Queue *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enQueue(Queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is Full\n");
        return;
    }
    else
    {
        q->rear += 1;
        q->arr[q->rear] = val;
        // printf("Enqueued: %d\n", q->arr[q->rear]);
    }
}

int deQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
        return -1;
    }
    else
    {
        q->front += 1;
        // printf("Dequeued: %d\n", q->arr[q->front]);
        return q->arr[q->front];
    }
}
void printQueue(Queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is Empty");
        return;
    }
    for (int i = q->front + 1; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}
int main()
{
    Queue q;
    q.size = 10;
    q.front = q.rear = -1;
    q.arr = (int *)calloc(sizeof(int), q.size);

    // BFS Implementation
    printf("Enter a initial node: ");
    int i;
    scanf("%d", &i);

    // no of nodes = 7
    // nodes which are visited initially none
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};

    // Adjacency Matrix
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 1, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {0, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    // starting node
    printf("%d ", i);
    visited[i]=i;

    // enQueue i for exploration
    enQueue(&q,i);
    while(!isEmpty(&q)){
        int node = deQueue(&q);
        for(int j=0;j<7;j++){
            if(a[node][j]==1 && visited[j]==0){
                printf("%d, %d",a[node][j],visited[j]);
                visited[j]=i;
                enQueue(&q,j);
            }
        }
    }
    printf("\n");
    printQueue(&q);

    return 0;
}