#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Creation & Transversal of Circular Linked List
// For Constant Time Complexity
struct Node
{
    int data;
    struct Node *next;
};

void TraversalC_LL(struct Node *head)
{
    int i = 1;
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
// Case 1: Insert at the head node
struct Node *InsertAtHead(struct Node *head, struct Node *last, int d)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = d;
    newNode->next = head;
    last->next = newNode;
    head = newNode;

    return head;
}

// Case 2: Inserting at the last node
struct Node *InsertAtEnd(struct Node *last, int d)
{
    struct Node *newNode2 = (struct Node *)malloc(sizeof(struct Node));
    newNode2->data = d;
    newNode2->next = last->next;
    last->next = newNode2;
    last = newNode2;
    return last;
}

// Case 3: Inserting at a given position in the circular linked list
struct Node *InsertAtIndex(struct Node *head, int d, int index)
{
    int i = 0;
    struct Node *newNode3 = (struct Node *)malloc(sizeof(struct Node));
    newNode3->data = d;
    struct Node *p = head;
    while (i != index - 1)
    {
        p = p->next;
        ++i;
    }
    newNode3->next = p->next;
    p->next = newNode3;
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
    printf("\nInsertion at the Beginning\n");
    head = InsertAtHead(head, fourth, 43);
    head = InsertAtHead(head, fourth, 51);
    TraversalC_LL(head);

    // Directly pass the last node &update the linked list
    printf("\nInsertion at the End\n");
    fourth = InsertAtEnd(fourth, 10);
    fourth = InsertAtEnd(fourth, 15);
    TraversalC_LL(head);
    
    // Inserting a node at a given index position
    printf("\nInsertion at the a given index\n");
    head = InsertAtIndex(head, 100, 3);

    TraversalC_LL(head);

    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}
