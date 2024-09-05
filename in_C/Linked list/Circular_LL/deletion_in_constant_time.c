#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Creation, Transversal  & Deletion in constant time in a Circular Linked List
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
// Case 1: Delete at the head node
struct Node *DeletingAtHead(struct Node *head,struct Node * last)
{
    // *p points to the next node of head
    struct Node *temp = head;
    struct Node *q = last;
   
    q->next=head->next;
    head=head->next;

    free(temp);
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
    printf("\nDeletion at the Beginning\n");
    head = DeletingAtHead(head,fourth);
    TraversalC_LL(head);

    

    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}
