#include <iostream>
#include <cstdio>
using namespace std;

// Peek operation in Stack -- finding the top index element

// Let us create a stack of arrays-
class Stack
{
public:
    int size, top;
    int *arr;
};
// function to check whether the stack is empty
int isEmpty(class Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// function to check if stack is full
int isFull(class Stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// function to push the elements in the stack 
void Push(class Stack **s,int element)
{
    if(isFull(*s))
    {
        cout<<"Stack OverFlow\n";
    }
    else{
        (*s)->top+=1;
        (*s)->arr[(*s)->top]=element;
        cout<<"Element pushed in the stack: "<<(*s)->arr[(*s)->top]<<endl;
        // return element;

    }
}
// function to pop elemen out of the stack
int Pop(class Stack**s)
{
    if(isEmpty(*s))
    {
        cout<<"Stack UnderFlow\n";
    }
    else{
        int val = (*s)->arr[(*s)->top];
         (*s)->top-=1;
         return val;
    }
}
// function to find the element at the peek position 
int main()
{
    // Pointer points to the objects of the class Stack
    class Stack *s;
    // Dynamic memory allocation for the pointer
    s = (class Stack *)malloc(sizeof(class Stack));
    // Now the stack is created, now giving a size for the array(container)
    //  of the the stack
    s->size = 10; // s's=>array's=>size
    s->top = -1;  // s's=>array>top   initially zero.
    s->arr = (int *)malloc(s->size * sizeof(int));
    // Array is created ,now filling the array

    // let us check whether the status of our stack
    if(isEmpty(s)){
        cout<<"The stack is Empty\n";
    }
    else{
        cout<<"The Stack is Not Empty\n";
    }
    if(isFull(s)){
        cout<<"The stack is Full\n";
    }
    else{
        cout<<"The Stack is Not Full\n";
    }

    // let us push the elements in the stack 
    Push(&s,10);
    Push(&s,20);
    Push(&s,30);
    return 0;
}