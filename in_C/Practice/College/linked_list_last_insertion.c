#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Linked List Last insertion

// Creating a structure to create a linked list
typedef struct Node
{
    int data;          //
    struct Node *next; // struct Node *Node::next : Pointer of Structure
} Node;

// Creat
// void

int main()
{
    Node A;
    Node *ptr;
    ptr = &A;
    ptr->next = (Node *)malloc(3 * sizeof(Node));
    printf("Enter Data to created a linked list\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Enter %d Data: ", i + 1);
        scanf("%d", &(ptr[i].data));
    }
    printf("The Data entered in the Linked list is: \n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d Data: %d \n", i + 1, (ptr[i].data));
    }
    return 0;
}