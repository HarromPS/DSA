#include <iostream>
#include <cstdio>
using namespace std;

static int node_no;

// Creating a struct for Linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Globlally Declaring head & tail pointer of type struct Node
struct Node *head = NULL;
struct Node *tail = NULL;

// Creating a function to create linked list
int Create_list(int d1)
{
    // linking a new memory
    struct Node *New_node = (struct Node *)malloc(sizeof(struct Node));
    New_node->data = d1;
    New_node->next = NULL;
    if (head == NULL)
    {
        node_no++;
        cout << "Head Node is created " << endl;
        tail = New_node;
        head = tail;
    }
    else
    {
        node_no++;
        cout << node_no << " Node is created" << endl;
        tail->next = New_node;
        tail=New_node;
        tail->next = NULL;
    }
}
// Function to display the Nodes i.e Transversing through the nodes
int Display(void)
{

    struct Node *Current_node = head;
    if (Current_node == NULL)
    {
        cout << "Linked list is Empty" << endl;
    }
    else
    {
        while (Current_node != NULL)
        {
            cout << Current_node->data << "->";
            Current_node = Current_node->next;
        }
    }
}
int main()
{
    int n, d1;
    cout << "Enter how many nodes you want: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        // Calling function
        cout << "Enter data of " << i + 1 << " Node: ";
        cin >> d1;
        Create_list(d1);
    }
    cout << endl
         << "The Linked list is ==>" << endl;
    Display();
    cout<<"NULL"<<endl;

    // 
    return 0;
}