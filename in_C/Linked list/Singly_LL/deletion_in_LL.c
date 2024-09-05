#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Deletion operation in linked list at the beginning

// Creating a struct for Node
struct Node
{
    int data;
    struct Node *next;
};

// function for transversal
// struct Node* head ==> means parameters of a (struct Node * type pointer)
// =>> Node pointer
// => holds the address/value of a data & address of a pointer which is holding
// the address/pointing to the next pointer/Node
void TransversalLL(struct Node *head) // Display Linked list
{
    int i = 0;
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    while (head != NULL)
    {
        printf("(%d,%d)->", head->data, i);
        head = head->next;
        i++;
    }
    printf("NULL\n");
}

// Case 1: Function to Delete Node at the beginning
struct Node *DeleteAtFirst(struct Node *head)
{
    struct Node *temp = head;
    head = head->next;
    // freed the memory of previous head
    free(temp);

    return head;
}

// Case 3: Function at the end of the linked list
struct Node *DeleteAtEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head;
    q = q->next;
    while ((q->next != NULL))
    {
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    free(q);

    return head;
}

// Case 2: Function to delete the Node at a index
struct Node *DeleteAtIndex(struct Node *head, int index)
{
    int i = 0;
    struct Node *p = head;
    // OR
    // struct Node* q=head->next;
    while (i != index - 1)
    {
        p = p->next;
        ++i;
    }
    struct Node *q = p->next;
    p->next = q->next;
    free(q);

    // OR
    /*
    for(int i=0;i<(index-1);i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    */

    return head;
}

// Case 4: Function to delete node with a given value
struct Node *DeleteAtValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head;
    q = q->next;
    while ((q->data != value) && (q->next != NULL))
    {
        q = q->next;
        p = p->next;
    }
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
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    // Linking nodes
    head->data = 4;
    head->next = second;

    // Linking nodes
    second->data = 8;
    second->next = third;

    // Linking nodes
    third->data = 12;
    third->next = fourth;

    // Linking nodes
    fourth->data = 16;
    fourth->next = NULL;

    printf("Linked list before deletion\n");
    TransversalLL(head);

    // // Delete at first
    // printf("Linked list after deletion\n");
    // // head=DeleteAtFirst(head);
    // TransversalLL(head);

    // // Delete at a index
    // printf("Linked list after deletion\n");
    // // head=DeleteAtIndex(head,2);
    // TransversalLL(head);

    // // Delete at the end
    // printf("Linked list after deletion\n");
    // // head = DeleteAtEnd(head);
    // TransversalLL(head);

    // // Delete at a value
    // printf("Linked list after deletion\n");
    // // head = DeleteAtValue(head, 18);
    // TransversalLL(head);

    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}