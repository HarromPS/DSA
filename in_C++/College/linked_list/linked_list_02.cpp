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
        cout<<"Head Node Created"<<endl;
        tail = newNode;
        cout<<"Tail Node Created"<<endl<<endl;
        head = tail; // head and tail now become newNode
    }
    else
    {
        // else tail ke next me new node means new addess
        // i.e tail-> next = new address of type struct Node* pointer

        /* tail->next=(struct Node*)malloc(sizeof(struct Node));

         // Now tail pointer itself the address
         tail=(struct Node*)malloc(sizeof(struct Node));
         */

        //  This can be written in more better way
        tail->next = newNode;
        tail = newNode;     // A new node is fomed
        tail->next=NULL;
        cout<<"New node for Tail is Created"<<endl<<endl;

    }
}

// In above function only nodes were created & there was no linking 
// of head node with other nodes
// Now linking head node with other nodes one-by-one


// Function to display the Node formed
void Display()
{
    int i=0;
    // Allocating a dynamic memory to print the data in all Nodes
    // i.e Transversing through all the nodes
    struct Node* Current_Node = head;

    if(Current_Node==NULL)       // Means head = NULL (one time condition)
    {
        cout<<"Linked List is Empty"<<endl;
    }
    else
    {
        while(Current_Node!=NULL)
        {
            i++;
            printf("The value at %d Node is: %d\n",i,Current_Node->data);
            printf("The address of %d Node is: %d\n",i,Current_Node);
            printf("The address in next of %d Node is: %d\n",i,Current_Node->next);

            Current_Node=Current_Node->next;
            cout<<endl;
            
        }
    }
}
int main()
{
    // Calling the function and passing argument to create first
    // or head node
    NewNode(10);

    // Second Node
    NewNode(20);

    // Third Node
    NewNode(30);
    Display();


    return 0;
}