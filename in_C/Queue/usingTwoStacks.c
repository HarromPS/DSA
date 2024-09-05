#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Queue using two stacks using method 1
// enQueue - O(n)
// deQueue - O(1)

typedef struct S1
{
    int top1;
    int size1;
    int *arr1;
} S1;
typedef struct S2
{
    int top2;
    int size2;
    int *arr2;
} S2;

int isFull(S1 *s1)
{
    if (s1->top1 > s1->size1 - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(S1 *s1)
{
    if (s1->top1 < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enQueue(S1 *s1, S2 *s2,int val)
{
    if(isFull(s1))
    {
        printf("Cannot EnQueue\nQueue Full\n");
    }
    else{
        // Copy all the elements of s1 to s2
        s2->top2=-1;
        while(s1->top1>=0)
        {
            s2->top2++;
            s2->arr2[s2->top2]=s1->arr1[s1->top1];
            s1->top1--;
        }
        s1->top1++;
        s1->arr1[s1->top1]=val;
        printf("Enqueued %d\n",s1->arr1[s1->top1]);

        // copy back all the elements back to s1
        while(s2->top2>=0)
        {
            s1->top1++;
            s1->arr1[s1->top1]=s2->arr2[s2->top2];
            s2->top2--;
        }
    }
}

int deQueue(S1* s1)
{
    if(isEmpty(s1))
    {
        printf("Cannot remove element\nEmpty Queue\n");
        return -1;
    }
    else{
        // s1->top == front && s1->size-1 == rear
        int x=s1->arr1[s1->top1];
        s1->top1--;
        return x;
    }
}

void printQueue(S1* s1)
{
    printf("Printing Queue::\n");
    for(int i=s1->top1;i>=0;i--)
    {
        printf("%d ",s1->arr1[i]);
    }
    printf("\n");
}
int main()
{
    S1 s1;
    s1.size1=10;
    s1.top1=-1;
    s1.arr1=(int*)malloc(sizeof(int)*s1.size1);

    S2 s2;
    s2.size2=10;
    s2.top2=-1;
    s2.arr2=(int*)malloc(sizeof(int)*s2.size2);

    enQueue(&s1,&s2,12);
    enQueue(&s1,&s2,23);
    enQueue(&s1,&s2,2);
    enQueue(&s1,&s2,223);
    enQueue(&s1,&s2,98);
    printQueue(&s1);

    printf("DeQueued %d\n",deQueue(&s1));
    printf("DeQueued %d\n",deQueue(&s1));
    printf("DeQueued %d\n",deQueue(&s1));
    printQueue(&s1);

    return 0;
}