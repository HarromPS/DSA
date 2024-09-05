#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Creation, Transversal  & Deletion in a Circular Linked List
struct Node
{
    int data;
    struct Node *next;
};

void TraversalC_LL(struct Node *head)
{
    int i = 0;
    struct Node *current = head;
    if (current->next == current)
    {
        printf("Circular Linked list is Empty\n");
    }
    do
    {
        printf("(%d,%d)", current->data, i);
        ++i;
        if (current->next != head)
        {
            printf("->");
        }
        current = current->next;
    } while (current != head);
}
// Case 1: Delete at the head node
struct Node *DeletingAtHead(struct Node *head)
{
    // *p points to the next node of head
    struct Node *temp = head;
    struct Node

        *q = head->next;
    // Reaching the last node
    while (q->next != head)
    {
        q = q->next;
    }
    // At this point we are now at the last node
    q->next = head->next;
    head = head->next;

    free(temp);
    return head;
}

// Case 2: Deleting at the last node
struct Node *DeletingAtEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head;
    q = head->next;
    // Reaching the last node
    while (q->next != head)
    {
        p = p->next;
        q = q->next;
    }
    // At this point we are now at the last node
    p->next = q->next;
    free(q);
    return head;
}

// Case 3: Deleting at a given index
struct Node *DeletingAtIndex(struct Node *head, int index)
{
    int i = 0;
    struct Node *p = head;
    struct Node *q = head;
    q = head->next;
    // Reaching the last node
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        ++i;
    }
    // At this point we are now at the last node
    p->next = q->next;
    free(q);
    return head;
}

// Case 4: Deleting by a node with a value
struct Node *DeletingAtValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head;
    q = head->next;
    // Reaching the last node
    while (q->data != value && q->next != head)
    {
        p = p->next;
        q = q->next;
    }
    // At this point we are now at the last node
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    else
    {
        printf("Node Not Found\n");
    }

    return head;
}
int main()
{
    // Struct Node pointer variables
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    // filling the data and linking the nodes
    head->data = 4;
    head->next = second;

    // filling the data and linking the nodes
    second->data = 3;
    second->next = third;

    // filling the data and linking the nodes
    third->data = 6;
    third->next = fourth;

    // filling the data and linking the nodes
    fourth->data = 1;
    fourth->next = head;

    // Calling the Transversal function of circular linked List
    printf("Circular Linked list transversal\n");
    TraversalC_LL(head);

    // printf("\nDeletion at the Beginning\n");
    // head = DeletingAtHead(head);
    // TraversalC_LL(head);

    // printf("\nDeletion at the End\n");
    // head = DeletingAtEnd(head);
    // TraversalC_LL(head);

    // printf("\nDeletion at the Index\n");
    // head = DeletingAtIndex(head, 2);
    // TraversalC_LL(head);

    // printf("\nDeleting by a node with a value\n");
    // head = DeletingAtValue(head, 12);
    // TraversalC_LL(head);

    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}
