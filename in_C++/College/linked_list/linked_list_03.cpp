#include <iostream>
#include <cstdio>
using namespace std;

// Defining a structure for linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Creating a Linked list with one head & one tail Pointer Globally
struct Node *head = NULL; // first pointer
struct Node *tail = NULL; // second pointer

// Creating a function for Node formation
void NewNode(int a)
{
    // Creating a new node pointer of type struct Node
    // & providing dynamic memory allocation
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = a;
    newNode->next = NULL;
    if (head == NULL)
    {
        // cout << "Head Node Created" << endl;
        tail = newNode;
        // cout << "Tail Node Created" << endl
        //  << endl;
        head = tail; // head and tail now become newNode
    }
    else
    {
        tail->next = newNode;
        tail = newNode; // A new node is fomed
        tail->next = NULL;
        // cout << "New node for Tail is Created" << endl
        //  << endl;
    }
}

void Display()
{
    struct Node *Current_Node = head;
    if (Current_Node == NULL)
    {
        cout << "Linked List is Empty" << endl;
    }
    else
    {
        while (Current_Node != NULL)
        {
            cout << Current_Node->data << "->";
            // printf("The value at %d Node is: %d\n", i, Current_Node->data);
            Current_Node = Current_Node->next;
            // cout << endl;
        }
    }
}

// You have provided a linked list of marks of students varies from 0 to 30 
// WAP to which will print how many students got 25 marks

int marks(int mark)
{
    int count = 0;
    struct Node *Now = head;
    while (Now != NULL)
    {
        if ((Now->data) == mark)
        {
            count += 1;
        }
        Now = Now->next;
    }
    return count;
}
int main()
{
    int x, mark=25;
    for (int i = 0; i < 8; i++)
    {
        cout << "Enter data of " << i + 1 << " Node: ";
        cin >> x;
        NewNode(x);
    }

    cout<<"The Linked List is ==>"<<endl;
    Display();
    cout<<"NULL"<<endl;
    
    int result = marks(mark);
    cout << result << " student got 25 marks" << endl;

    return 0;
}