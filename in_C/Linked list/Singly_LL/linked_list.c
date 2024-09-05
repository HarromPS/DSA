#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Creating NODE(element in a linked list) using struct datatype
// NODE==> "DATA" + "LINK"
// # Data--> Actual content/info
// # Link--> To point to the next node

// let us create a linked list named struct Node(element in a linked list)
struct Node
{
    int Data;
    struct Node *link_next; // link as pointer of struct Node type ==> will point to whole struct Node
};
int main()
{
    // A linked list is an ordered collection of finite, homogenous
    // data elements called nodes where "linear ordered" is maintained
    // using pointer(links).

    // Dynamic memory allocation for the head pointer but its data is
    // Here struct Node is a datatype and *head2 is a pointer object

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *head2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *head3 = (struct Node *)malloc(sizeof(struct Node));

    // like int *ptr = new int[1]

    (*head).Data = 2;          // head->Data
    (*head).link_next = head2; // head->link
    printf("%d\n", (head->link_next));
    printf("%d\n", head);
    printf("%d\n", &head);

    // printf("%d \n",head->Data);
    // printf("%d \n",head->link_next);

    (*head2).Data = 10;        // head->Data
    (*head2).link_next = head; // head->link
    // printf("%d \n",head2->Data);
    printf("%d \n", *(head2->link_next));

    (*head3).Data = 30;        // head->Data
    (*head3).link_next = NULL; // head->link
    // printf("%d \n",head3->Data);
    // printf("%d \n",head3->link_next);

    free(head);
    free(head2);
    free(head3);

    return 0;
}