#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int Data;
    struct Node *link_next; // link as pointer of type struct Node
};
int main()
{
    // 3 nodes head ==>start linked list
    struct Node *head1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *head2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *head3 = (struct Node *)malloc(sizeof(struct Node));
    // 3rd pointer is NULL

    (*head1).Data = 10;         // head->Data
    (*head1).link_next = head2; // head->link
    printf("Address of pointer of head: %d \n", &(head1));
    printf("Data of Head Node: %d \n", head1->Data);
    printf("Address which Head Node is storing: %d \n", (&head1->link_next));

    (*head2).Data = 20;         // head->Data
    (*head2).link_next = head3; // head->link
    printf("\nAddress of pointer of Second Node: %d \n", &(head2));
    printf("Data of Second Node: %d \n", head2->Data);
    printf("Address which Second Node is storing: %d \n", head2->link_next);

    (*head3).Data = 30;        // head->Data
    (*head3).link_next = NULL; // head->link
    printf("\nAddress of pointer of Third Node: %d \n", &(head3));
    printf("Data of Third Node: %d \n", head3->Data);
    printf("Address which Third Node is storing: %d \n", head3->link_next);

    struct Node *ptr=(struct Node*)malloc(5*sizeof(struct Node));
    printf("New pointer show addresses\n");
    for(int i=0;i<5;i++)
    {
        printf("\n%d ",(ptr->link_next)[i]);//(ptr->Data)[i]=i;
    }
    

    free(head1);
    free(head2);
    free(head3);
    free(ptr);


    return 0;
}