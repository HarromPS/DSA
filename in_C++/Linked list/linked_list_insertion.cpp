#include <iostream>
#include <cstdio>
using namespace std;

// Inserting a node in a linked list
struct Node
{
    int data;
    struct Node *next_address;
};
struct Node *head = (struct Node *)malloc(sizeof(struct Node));
struct Node *tail = (struct Node *)malloc(sizeof(struct Node));

// Case 1: Inserting at head node
// struct Node* head ==> means parameters of a (struct Node * type pointer)
// =>> Node pointer
// => holds the address/value of a data & address of a pointer which is holding
// the address/pointing to the next pointer/Node
struct Node *InsertAtHead(int d)
{
    // Creating a new node to be inserted before head node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = d;
    newNode->next_address = head;
    head = newNode;
    return head;
}

// Case 2: Insert at the end of the linked list
// struct Node* InsertAtFirst ==> means the return type is a
// struct Node* type i.e a pointer of that type
// will return the head Node pointer
struct Node *InsertAtTail(int d)
{
    // Creating a new node to be inserted after tail node
    struct Node *newNode2 = (struct Node *)malloc(sizeof(struct Node));
    newNode2->data = d;
    struct Node *current = head;
    while (current->next_address != NULL)
    {
        current = current->next_address;
    }
    current->next_address = newNode2;
    newNode2->next_address = NULL;
    return head;
}

// Case 3: Insert at after a node
struct Node *InsertInBetween(int d, int index)
{
    // Creating a new node to be inserted between a node
    struct Node *newNode4 = (struct Node *)malloc(sizeof(struct Node));
    newNode4->data = d;
    struct Node *current = head;
    int i = 0;
    while (i != index - 1)
    {
        current = current->next_address;
    }
    newNode4->next_address = current->next_address;
    current->next_address = newNode4;
    return head;
}

// function to Create a node
void CreateNode(int d)
{
    struct Node *newNode_x = (struct Node *)malloc(sizeof(struct Node));
    newNode_x->data = d;
    if (head == NULL)
    {
        tail = newNode_x;
        head = tail;
    }
    else
    {
        struct Node *newNode_y = (struct Node *)malloc(sizeof(struct Node));
        tail->next_address = newNode_y;
        tail = newNode_y;
        tail->next_address = NULL; // nothing is in the next of tail
                                   // means no next node
    }
}

// Function to Display the linked list
void Display()
{
    struct Node *current = (struct Node *)malloc(sizeof(struct Node));
    current = head;
    int i = 0;
    if (head == NULL)
    {
        cout << "linked List is Null" << endl;
    }
    while (current != NULL)
    {
        cout << "(" << current->data << "," << i << ")"
             << "->";
        current = current->next_address;
        ++i;
    }
    cout << "NULL" << endl;
}
int main()
{
    int x = 0, data, index;

    while (x != 6)
    {
        cout << "\nChoose\n1) Create Node\n2) Display Linked list\n3) Insert a node at head";
        cout << "\n4) Insert a node at end\n5) Insert a node in between\n";
        cout << "6) Exit\n==>";
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "Enter the data for the node: ";
            cin >> data;
            cout << "New Node created" << endl;
            break;
            cout << "The Linked List are::" << endl;
            Display();
        case 2:
            Display();
            break;
        case 3:
            cout << "Enter the data for the inserting node: ";
            cin >> data;
            head = InsertAtHead(data);
            cout << "New Node Inserted" << endl;
            break;
        case 4:
            cout << "Enter the data for the inserting node: ";
            cin >> data;
            head = InsertAtTail(data);
            cout << "New Node Inserted" << endl;
            break;
        case 5:
            cout << "Enter the data for the inserting node: ";
            cin >> data;
            cout << "Enter the index for the inserting node: ";
            cin >> index;
            head = InsertInBetween(data, index);
            cout << "New Node Inserted" << endl;
            break;
        case 6:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Finish\n";
        }
    }

    return 0;
}