#include <iostream>
#include <cstdio>
using namespace std;

// Creating NODE(element in a linked list) using class datatype
// NODE==> "DATA" + "LINK"
// # Data--> Actual content/info
// # Link--> To point to the next node

// let us create a linked list named class Node(element in a linked list)
class Node
{
public:
    int Data;
    class Node *link_next; // link as pointer of struct Node type ==> will point to whole struct Node
};

// Function for the traversal of linked list 
void TransversalLL(class Node* head)
{
    if(head==NULL)
    {
        cout<<"Linked list is empty\n";
    }
    cout<<"The elements in  the linked list is "<<endl;
    while(head!=NULL)
    {
        cout<<"("<<head->Data<<")"<<"->";
        head=head->link_next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    // Accessing any eleemnt is easy in array
    int arr[10] = {1, 2, 3, 4, 5, 67, 7, 8, 9};
    int x = (*arr) + (sizeof(int) * 6);
    // cout << (arr) << endl;
    // cout << x<<endl;

    // A linked list is an ordered collection of finite, homogenous
    // data elements called nodes where "linear ordered" is maintained
    // using pointer(links).

    // Dynamic memory allocation in HEAP   
    class Node *head = (class Node *)malloc(sizeof(class Node));
    class Node *second = (class Node *)malloc(sizeof(class Node));
    class Node *third = (class Node *)malloc(sizeof(class Node));
    class Node *fourth = (class Node *)malloc(sizeof(class Node));

    // link first & second node
    head->Data=7;
    head->link_next=second;

    // link second & third node
    second->Data=11;
    second->link_next=third;

    // link third & fourth node
    third->Data=24;
    third->link_next=fourth;

    // last node
    fourth->Data=12;
    fourth->link_next=NULL;

    // Function call
    TransversalLL(head);
    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}