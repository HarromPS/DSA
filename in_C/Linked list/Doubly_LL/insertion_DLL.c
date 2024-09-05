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

// Function for Node insertion at head
struct Node *InsertAtHead(struct Node *head, int d)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = d;

    // Linking to the head node
    newNode->next = head;
    head->previous = newNode;
    newNode->previous = NULL;
    head = newNode;

    return head;
}

// Function for Node insertion at last O(n)
struct Node *InsertAtlast(struct Node *head, int d)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = d;
    struct Node *current = head;
    // Reaching to the last Node
    do
    {
        current = current->next;
    } while (current->next != NULL);
    // At this point the current pointer is at last node

    // Linking to the last node
    newNode->next = NULL;
    newNode->previous = current;
    current->next = newNode;
    return head;
}

// Function for Node insertion at last O(1)
struct Node *InsertAtlast1(struct Node *last, int d)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = d;
    // At this point the current pointer is at last node

    // Linking to the last node
    newNode->next = NULL;
    newNode->previous = last;
    last->next = newNode;
    return last;
}
// Function for Node insertion at after a node
struct Node *InsertAfterNode(struct Node *head, int d, int index)
{
    int i = 0;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = d;
    struct Node *current = head;
    // Reaching that node after which a node is to be inserted
    while (i != index)
    {
        current = current->next;
        ++i;
    }
    // At this point the current pointer is at the indexed node

    // Linking new node
    newNode->next = current->next;
    newNode->previous = current;
    current->next = newNode;
    (current->next)->previous = newNode;
    return head;
}
// Function for Node insertion at before a node
struct Node *InsertBeforeNode(struct Node *head, int d, int index)
{
    int i = 0;
    struct Node *newNode2 = (struct Node *)malloc(sizeof(struct Node));
    newNode2->data = d;
    struct Node *current = head;
    // Reaching that node after which a node is to be inserted
    // while (i != index)
    // {
    //     current = current->next;
    //     ++i;
    // }
    for(i=0;i!=index;++i)
    {
        current=current->next;
    }
    // // At this point the current pointer is at the indexed node

    // Linking new node
    newNode2->next = current;
    newNode2->previous = current->previous;
    current->previous = newNode2;
    (current->previous)->next = newNode2;
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

    // // Insertion At the head Node
    // printf("\nInsertion At the head Node\n");
    // head=InsertAtHead(head,20);
    // Display(head);

    // // Insertion At the last Node O(1)
    // printf("\nInsertion At the last Node\n");
    // fourth=InsertAtlast1(fourth,67);
    // Display(head);

    // // Insertion At the last Node O(n)
    // printf("\nInsertion At the last Node\n");
    // head=InsertAtlast(head,67);
    // Display(head);

    // // Insertion After a node O(n)/O(1) if that node is given/known
    // printf("\nInsertion After a Node\n");
    // head=InsertAfterNode(head,23,1);
    // Display(head);

    // Insertion before a node O(n)/( O(1) if that node is given/known)
    printf("\nInsertion before a Node\n");
    head = InsertBeforeNode(head, 45, 2);
    Display(head);

    return 0;
}