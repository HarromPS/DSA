#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Creation, Transversal  & Insertion of Circular Linked List
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
struct Node *InsertAtHead(struct Node *head, int d)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = d;
    // *p points to the next node of head
    struct Node *p = head->next;
    // Reaching the last node
    while (p->next != head)
    {
        p = p->next;
    }
    // At this point we are now at the last node
    // Now linking the last node to the new Node as head node
    p->next = newNode;

    // head becomes the new node
    newNode->next = head;
    head = newNode;
    return head;
}

// Case 2: Inserting at the lasst node
struct Node *InsertAtEnd(struct Node *head, int d)
{
    struct Node *newNode2 = (struct Node *)malloc(sizeof(struct Node));
    newNode2->data = d;

    // *p points to the next node of head
    struct Node *p = head->next;
    // Reaching the last node
    while (p->next != head)
    {
        p = p->next;
    }
    // At this point we are now at the last node
    // Now linking the last node to the new Node as end node
    p->next=newNode2;
    newNode2->next=head;
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
    head = InsertAtHead(head, 5);
    head = InsertAtHead(head, 10);
    head = InsertAtHead(head, 15);
    TraversalC_LL(head);

    printf("\nInsertion at the End\n");
    head = InsertAtEnd(head, 15);
    TraversalC_LL(head);

    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}
