#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Insertion operation in linked list at the beginning

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
void TransversalLL(struct Node *head)
{
    int i = 0;
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    printf("The elements in the linked list are:: \n");
    while (head != NULL)
    {
        printf("(%d,%d)->", head->data, i);
        head = head->next;
        i++;
    }
    printf("NULL\n");
}

// Function to insert Node at the beginning
// struct Node* InsertAtFirst ==> means the return type is a
// struct Node* type i.e a pointer of that type
// will return the head Node pointer
struct Node *InsertAtFirst(struct Node *head, int d)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // to insert
    newNode->next = head;
    newNode->data = d;
    head = newNode;

    return head;
}

// Function at the end of the linked list
struct Node *InserAtEnd(struct Node *head, int data)
{
    struct Node *newNode3 = (struct Node *)malloc(sizeof(struct Node));
    newNode3->data = data;
    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode3;
    newNode3->next = NULL;
    return head;
}

// Function to insert the Node in between
struct Node *InsertBetween(struct Node *head, int data1, int index)
{
    int i = 0;
    struct Node *newNode2 = (struct Node *)malloc(sizeof(struct Node));
    newNode2->data = data1;
    struct Node *x = head;
    while (i != index - 1)
    {
        x = x->next;
        i++;
    }
    newNode2->next = x->next;
    x->next = newNode2;
    return head;
}

// Function to insert after a Node
struct Node *InserAfterNode(struct Node *previousNode, int d)
{
    struct Node *newNode4 = (struct Node *)malloc(sizeof(struct Node));
    newNode4->data = d;
    newNode4->next = previousNode->next;
    previousNode->next = newNode4;
    return previousNode;
}
// Reverse the linked list
struct Node *reverseList(struct Node *head)
{
    struct Node *newhead = NULL;
    struct Node *next_ptr = head->next;
    while (next_ptr != NULL)
    {
        head->next = newhead;
        newhead = head;
        head = next_ptr;
        next_ptr = next_ptr->next;
    }
    head->next = newhead;
    newhead = head;
    head = next_ptr;
    return newhead;
}
int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    // Linking nodes
    head->data = 7;
    head->next = second;

    // Linking nodes
    second->data = 8;
    second->next = third;

    // Linking nodes
    third->data = 9;
    third->next = fourth;

    // Linking nodes
    fourth->data = 10;
    fourth->next = NULL;

    TransversalLL(head);

    // Updating the head
    head = InsertAtFirst(head, 6);
    TransversalLL(head);

    // function call to insert in between
    head = InsertBetween(head, 12, 5);
    TransversalLL(head);

    // function call to inset at the end
    head = InserAtEnd(head, 22);
    TransversalLL(head);

    // function call to inset after a Node
    third = InserAfterNode(third, 37);
    TransversalLL(head);

    // function call to inset after a Node
    second = InserAfterNode(second, 56);
    TransversalLL(head);

    // // function call to inset after a Node
    // fourth = InserAfterNode(fourth, 100);
    // TransversalLL(head);
    // This won't work because there are many allocations in function
    // which has been alloted so fourth is not fourth one
    head = reverseList(head);
    TransversalLL(head);
    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}