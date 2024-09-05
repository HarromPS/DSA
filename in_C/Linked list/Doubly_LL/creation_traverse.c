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
    struct Node *current = head;
    if (head == NULL)
    {
        printf("The Doubly Linked List is Empty\n");
    }
    printf("Head (Left) to Tail (Right)\n");
    // do
    // {
    //     printf("%d->", current->data);
    //     current = current->next;
    // } while (current->next != NULL);
    // OR

    while (current->next!= NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("%d->NULL\nTail (Left) to Head (Right)\n",current->data);
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->previous;
    }
    printf("NULL\n");
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
    Display(head);
    return 0;
}