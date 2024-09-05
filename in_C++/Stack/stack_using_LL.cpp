#include <iostream>
#include <cstdio>
using namespace std;

// We can create stack using linked list also
class Node
{
public:
    int data;
    class Node *next;
};
// function to check if the stack is full
int isFull(class Node *top)
{
    class Node *last = (class Node *)malloc(sizeof(class Node));
    if (last == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// function to check if the stack is empty
int isEmpty(class Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// function to add the node at the end of the top element
class Node *push(class Node *top, int Data)
{
    if (isFull(top))
    {
        cout << "Stack Overflow\n";
    }
    else
    {
        class Node *newNode = (class Node *)malloc(sizeof(class Node));
        newNode->data = Data;
        newNode->next = top;
        top = newNode;
        cout << "Element pushed in stack: " << top->data << endl;
    }
    return top;
}
// function to pop out the top node
int pop(class Node *top)
{
    if (isEmpty(top))
    {
        cout << "Stack Underflow\n";
    }
    else
    {
        int val = top->data;
        class Node *temp = top;
        top = top->next;
        delete (temp);
        return val;
    }
}
// peek function to give the element at the top of the stack/position
int peek(class Node *top)
{
    // Check if there is any node present or not, if not then return.
    // Otherwise return the value of top node of the linked list
    if (isEmpty(top))
    {
        cout << "Stack is Empty==> No top element" << endl;
    }
    else
    {
        return top->data;
    }
}
// stackTop() - element at the top
int stackTop(class Node *top)
{
    if (isEmpty(top))
    {
        cout << "Stack is empty\n";
    }
    else
    {
        return top->data;
    }
}
// stackBottom() - element at the top
int stackBottom(class Node *top)
{
    if (isEmpty(top))
    {
        cout << "Stack is empty\n";
        return 1;
    }
    class Node *p = top;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p->data;
}
// transversal of the stack
void Transversal(class Node *current)
{
    if (current == NULL)
    {
        return;
    }
    else
    {
        cout << "(" << current->data << ")->";
        Transversal(current->next);
    }
}
int main()
{
    class Node *top = NULL; // Initially the stack is null
    // Pushing elements in the stack
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 40);
    class Node *current = top;
    // if(current==NULL) cout<<"l";
    Transversal(current);
    cout << "NULL\n";

    // Finding the peek element
    cout<<"The top element is: "<<peek(current)<<endl;
    cout<<"The stackTop element is: "<<stackTop(current)<<endl;
    cout<<"The stackBottom element is: "<<stackBottom(current)<<endl;
    return 0;
}