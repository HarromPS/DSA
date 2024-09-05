#include <stdio.h>
#include <stdlib.h>

// Q2) Occurance of a particular number in a given LL
// A) With different function
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
        printf("(%d)", (current->data)); //  if(current->data==current->next->data) count++;
        if (current != NULL)
        {
            printf("->");
        }
        current = current->next;
    }
    printf("NULL\n");
}

// function to find the count
int Occurance(int count, int num)
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("Empty\n");
    }
    while (temp != NULL)
    {
        if ((temp->data) == (num))
        {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

int main()
{
    int x = 0, y = 0;
    int count, num;
    printf("Choose\n1) Create Node\n2) Display Node\n");
    printf("3) Find occurance\n4) Exit\n==>");
    scanf("%d", &y);
    while (y != 4)
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
            printf("Enter a number from to find its occurance in the linked list :: ");
            scanf("%d", &num);
            int result = Occurance(count, num);
            if (result > 1)
            {
                printf("The occurance of %d is: %d\n", num, result);
            }
            else
            {
                printf("The number not found\n");
            }
            break;

        case 4:
            printf("Exit\n");
            break;

        default:
            printf("Finish\n");
        }
        printf("\nChoose\n1) Create Node\n2) Display Node\n");
        printf("3) Find occurance\n4) Exit\n==>");
        scanf("%d", &y);
    }

    return 0;
}
