#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Creation & Transversal of Circular Linked List 
struct Node
{
    int data;
    struct Node* next;
};

void TraversalC_LL(struct Node * head)
{
    struct Node* current=head;
    if(current->next==current)
    {
        printf("Circular Linked list is Empty\n");
    }
    // control will not enter the while loop because current is already==head
    // So
    // printf("%d->",current->data);
    // current=current->next;
    // while(current!=head)
    // {
    //     printf("%d",current->data);
    //     if(current->next!=head)
    //     {
    //         printf("->");
    //     }
    //     current=current->next;
    // }

    // The clean way to do this is using a do while loop
    do
    {
        printf("%d",current->data);
        if(current->next!=head)
        {
            printf("->");
        }
        current=current->next;
    }while(current!=head);
}
int main()
{
    // Struct Node pointer variables
    struct Node* head=(struct Node*)malloc(sizeof(struct Node));
    struct Node* second=(struct Node*)malloc(sizeof(struct Node));
    struct Node* third=(struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth=(struct Node*)malloc(sizeof(struct Node));

    // filling the data and linking the nodes
    head->data=4;
    head->next=second;
    
    // filling the data and linking the nodes
    second->data=3;
    second->next=third;

    // filling the data and linking the nodes
    third->data=6;
    third->next=fourth;

    // filling the data and linking the nodes
    fourth->data=1;
    fourth->next=head;

    // Calling the Transversal function of circular linked List 
    printf("Circular Linked list transversal\n");
    TraversalC_LL(head);

    return 0;
}