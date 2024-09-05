#include <iostream>
#include <cstdio>
using namespace std;

// Reversing a given linked list
class Node
{
public:
    int data;
    class Node *next;
};
void Transversal(class Node *head)
{
    class Node *current1=NULL;
    current1 = head;
    if (head == NULL)
    {
        cout << "Empty Linked list" << endl;
    }
    while (current1 != NULL)
    {
        cout << "(" << current1->data << ")->";
        current1 = current1->next;
    }
    cout << "NULL" << endl;
}
// function to revese the linked list
class Node *Reverse(class Node *head)
{
    class Node *prev = head;
    class Node *current = head->next;
    class Node *nex = head->next->next;
    if (head->next->next == NULL)
    {
        prev->next = NULL;
        current->next = prev;
        head = current;
    }
    
    else
    {
        prev->next = NULL;
        current->next = prev;
        while (nex != NULL)
        {
            prev = current;
            current = nex;
            nex = nex->next;
            current->next = prev;
        }
    }
    head = current;
    return head;
}
int main()
{
    class Node *head = (class Node *)malloc(sizeof(class Node));
    class Node *second = (class Node *)malloc(sizeof(class Node));
    class Node *third = (class Node *)malloc(sizeof(class Node));
    class Node *fourth = (class Node *)malloc(sizeof(class Node));
    class Node *fourth1 = (class Node *)malloc(sizeof(class Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fourth1;

    fourth1->data = 50;
    fourth1->next = NULL;
    cout << "The linked list is ::" << endl;
    Transversal(head);
    cout << "The reversed linked list is ::" << endl;
    head=Reverse(head);
    Transversal(head);
    return 0;
}
