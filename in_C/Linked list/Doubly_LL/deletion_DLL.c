#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Creation & Transversal of Doubly Linked List
// Structure of Doubly Linked list(DLL)
/*
1) In DLL we can traverse in both previous & next direction
*/
struct Node
{
    struct Node *previous;
    int data;
    struct Node *next;
};

// Transversal of DLL
void Display(struct Node *head)
{
    int i = 0, j = 0;
    struct Node *current = head;
    if (head == NULL)
    {
        printf("The Doubly Linked List is Empty\n");
    }
    printf("Head to Tail\n");
    while (current->next != NULL)
    {
        printf("(%d,%d)->", current->data, i);
        current = current->next;
        ++i;
    }
    printf("(%d,%d)->NULL\nTail to Head\n", current->data, i);
    while (current != NULL)
    {
        printf("(%d,%d)->", current->data, j);
        current = current->previous;
        ++j;
    }
    printf("NULL\n");
}

// Function for Node Deletion at head
struct Node *DeleteAtHead(struct Node *head)
{
    // Linking to the head node
    struct Node *p = head;
    (p->next)->previous = NULL;
    head = p->next;
    free(p);

    return head;
}

// Function for Node Deletion at last O(n)
struct Node *DeleteAtLast1(struct Node *last)
{
    struct Node *p = last;
    p->previous->next = NULL;
    last = p->previous;
    free(p);
    return last;
}

// Function for Node Deletion at last O(1)
struct Node *DeleteAtLast(struct Node *head)
{
    struct Node *p = head;
    // Reaching the last node
    while (p->next != NULL)
    {
        p = p->next;
    }
    // P now at the last node
    (p->previous)->next = NULL;
    free(p);
    return head;
}
// Function for Node Deletion at after a node
struct Node *DeleteAfterNode(struct Node *head, int index)
{
    int i = 0;
    struct Node *p=head, *q = head;
    q = q->next;
    // Reaching that node after which a node is to be inserted
    while (i != index-1)
    {
        p = p->next;
        q = q->next;
        ++i;
    }
    // At this point the current pointer is at the indexed node
    p->next = q->next;
    (q->next)->previous = p;
    free(q);
    // Linking new node
    return head;
}
// Function for Node Deletion at before a node
struct Node *DeleteBeforeNode(struct Node *head, int index)
{
    int i = 0;
    struct Node *current = head;
    // Reaching that node after which a node is to be inserted
    // while (i != index)
    // {
    //     current = current->next;
    //     ++i;
    // }
    for (i = 0; i != index; ++i)
    {
        current = current->next;
    }
    // // At this point the current pointer is at the indexed node

    // Linking new node

    return head;
}
int main()
{
    // Creation of Nodes
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    // Linking and setting values
    head->previous = NULL;
    head->data = 23;
    head->next = second;

    second->previous = head;
    second->data = 34;
    second->next = third;

    third->previous = second;
    third->data = 56;
    third->next = fourth;

    fourth->previous = third;
    fourth->data = 52;
    fourth->next = NULL;
    // Function call for DLL transversal
    printf("Transversal of Doubly linked list\n");
    Display(head);

    // // Deletion At the head Node
    // printf("\nDeletion At the head Node\n");
    // head = DeleteAtHead(head);
    // Display(head);

    // // Deletion At the last Node O(1)
    // printf("\nDeletion At the last Node\n");
    // fourth = DeleteAtLast1(fourth);
    // Display(head);

    // // Deletion At the last Node O(n)
    // printf("\nDeletion At the last Node\n");
    // head = DeleteAtLast(head);
    // Display(head);

    // // Deletion After a node O(n)/O(1) if that node is given/known
    // printf("\nDeletion After a Node\n");
    // head = DeleteAfterNode(head, 2);
    // Display(head);

    // // Deletion before a node O(n)/( O(1) if that node is given/known)
    // printf("\nDeletion before a Node\n");
    // head = DeleteBeforeNode(head, 2);
    // Display(head);

    return 0;
}