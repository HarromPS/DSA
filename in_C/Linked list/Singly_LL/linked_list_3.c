#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int Data;
    struct Node *link_next; // link as pointer of type struct Node
};
int main()
{
    // 3 nodes head ==>start linked list
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    // struct Node *head2 = (struct Node *)malloc(sizeof(struct Node));
    // struct Node *head3 = (struct Node *)malloc(sizeof(struct Node));
    // 3rd pointer is NULL

    (*head).Data = 10; // head->Data
    // (*head).link_next = head; // head->link
    printf("Address of pointer of head: %d \n", &(head));
    (head++);
    printf("Address of pointer of head: %d \n", &(head));
    (head++);
    printf("Address of pointer of head: %d \n", &(head));
    (head++);
    printf("Address of pointer of head: %d \n", &(head));

    // printf("Data of Head Node: %d \n", (head->Data));

    // int x=0;
    // while (x != 0)
    // {
    //     head++;
    //     printf("Enter '1' to continue or else Enter '0' to end\n==>");
    //     scanf("%d", &x);
    //     head->Data = 1;
    //     // head2++;
    //     head->link_next = head;
    // }

    free(head);
    // free(head2);
    // free(head3);

    return 0;
}