#include <stdio.h>
#include <stdlib.h>

// Q1) Count the number of Positive, negative, even, odd numbers
// in a given LL
// A) With different functions
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
        printf("(%d)", (current->data));
        if (current != NULL)
        {
            printf("->");
        }
        current = current->next;
    }
    printf("\n");
}

// function to find the count of positive numbers
int PositiveCount(int count)
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
            count += 1;
        }
        temp = temp->next;
    }
    return count;
}

// function to find the count of negative numbers
int NegativeCount(int count)
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("Empty\n");
    }
    while (temp != NULL)
    {
        if ((temp->data) < 0)
        {
            count += 1;
        }
        temp = temp->next;
    }
    return count;
}

// function to find the count of even numbers
int EvenCount(int count)
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("Empty\n");
    }
    while (temp != NULL)
    {
        if ((temp->data) % 2 == 0)
        {
            count += 1;
        }
        temp = temp->next;
    }
    return count;
}

// function to find the count of odd numbers
int OddCount(int count)
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("Empty\n");
    }
    while (temp != NULL)
    {
        if ((temp->data) % 2 != 0)
        {
            count += 1;
        }
        temp = temp->next;
    }
    return count;
}

int main()
{
    int x = 0, y = 0;
    int result, count;
    printf("Choose\n1) Create Node\n2) Display Node\n");
    printf("3) Positive Number count\n4) Negative Number count\n5) Odd Number count\n6) Even Number count\n");
    printf("7) Exit\n==>");
    scanf("%d", &y);
    while (y != 7)
    {
        count = 0;
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
            result = PositiveCount(count);
            printf("The Positive numbers in your linkd list is: %d\n", result);
            break;

        case 4:
            result = NegativeCount(count);
            printf("The Negative numbers in your linkd list is: %d\n", result);
            printf("Exit\n");
            break;

        case 5:
            result = OddCount(count);
            printf("The Positive numbers in your linkd list is: %d\n", result);
            break;

        case 6:
            result = EvenCount(count);
            printf("The Positive numbers in your linkd list is: %d\n", result);
            printf("Exit\n");
            break;

        case 7:
            printf("Exit\n");
            break;

        default:
            printf("Finish\n");
        }
        printf("Choose\n1) Create Node\n2) Display Node\n");
        printf("3) Positive Number count\n4) Negative Number count\n5)Odd Number count\n6) Even Number count\n");
        printf("7) Exit\n==>");
        scanf("%d", &y);
    }

    return 0;
}
