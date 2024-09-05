#include <stdio.h>
#include <stdlib.h>

// Q1) Count the number of Positive, negative, even, odd numbers
// in a given LL
// B) With Same Function
// Creating a structure for a linked list
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

// Creating a function for node creation
void CreateNode(int x)
{
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));

    NewNode->data = x;
    NewNode->next = NULL;
    if (head == NULL)
    {
        tail = NewNode;
        head = tail;
    }
    else
    {
        NewNode->next = (struct Node *)malloc(sizeof(struct Node));
        tail->next = NewNode;
        tail = NewNode;
        tail->next = NULL;
    }
}

// Function to display the linked list
void Display()
{
    struct Node *current = head;
    if (head == NULL)
    {
        printf("Empty Linked list\n");
        return;
    }

    while (current != NULL)
    {
        printf("(%d)", (current->data));//  if(current->data==current->next->data) count++;
        if (current != NULL)
        {
            printf("->");
        }
        current = current->next;
    }
    printf("\n");
}

// function to find the count
int Count(int countp, int countn, int counte, int counto)
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("Empty\n");
    }
    while (temp != NULL)
    {
        if ((temp->data) > 0)
        {
            countp += 1;
        }
        else
        {
            countn += 1;
        }
        if ((temp->data) % 2 == 0)
        {
            counte += 1;
        }
        else
        {
            counto += 1;
        }
        temp = temp->next;
    }
    printf("The count of positive number in linked list: %d\n", countp);
    printf("The count of negative number in linked list: %d\n", countn);
    printf("The count of even number in linked list: %d\n", counte);
    printf("The count of odd number in linked list: %d\n", counto);
}

int main()
{
    int x = 0, y = 0;
    int countp,countn,counte,counto;
    printf("Choose\n1) Create Node\n2) Display Node\n");
    printf("3) Show the count\n4) Exit\n==>");
    scanf("%d", &y);
    while (y != 4)
    {
        countp=0,countn=0,counte=0,counto=0;
        switch (y)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &x);
            CreateNode(x);
            break;

        case 2:
            Display();
            break;

        case 3:
            Count(countp,countn,counte,counto);
            break;

        case 4:
            printf("Exit\n");
            break;

        default:
            printf("Finish\n");
        }
        printf("Choose\n1) Create Node\n2) Display Node\n");
        printf("3) Show the count\n4) Exit\n==>");
        scanf("%d", &y);
    }

    return 0;
}
