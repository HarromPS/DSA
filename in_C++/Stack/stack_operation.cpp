#include <iostream>
#include <cstdio>
using namespace std;

// Stack creation, operations on stack
// Creating a class for stack
class Stack
{
public:
    int *arr;
    int total_size;
    int top;
};
// function to check whether stack is empty or not
int isEmpty(class Stack *st){
    if(st->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
// function to check whether stack is full or not
int isFull(class Stack* s)
{
    if(s->top==s->total_size-1){
        return 1;
    }
    else{
        return 0;
    }
}
// Function to push the elements in the stack 
// Not necessary to return values from the function, 
int push(class Stack *s,int element)
{
    if(isFull(s)){
        cout<<"Stack Overflow\n";
        return 0;
    }
    else{
        s->top+=1;
        s->arr[s->top]=element;
        if(s->arr[s->top]==element){
            return element;
        }
    }
}
// Function to pop out elements from the stack 
int pop(class Stack *s)
{
    if(isEmpty(s)){
        cout<<"Stack Underflow\n";
        return 0;
    }
    else{
        int value=s->arr[s->top];
        s->top-=1;
        return value;
    }
}
// Function to display the stack 
void Display(class Stack **s,int count){
    cout<<"\nThe elements in the stack are:\n";
    for(int i=0;i<count;i++){
        cout<<(*s)->arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n,count=0;
    cout << "Enter a size of your stack: ";
    cin >> n;
    class Stack *S1; // creating a pointer for n stacks
    S1 = (class Stack *)malloc(sizeof(class Stack));
    S1->top = -1; // ijnitially the stack is empty
    S1->total_size = n;
    S1->arr = (int *)malloc(n * sizeof(int));

    // Checking if stack is Full/Empty
    cout<<"Stack Before Pushing elements\n";
    if(isEmpty(S1)){
    cout<<"The stack is empty"<<endl;
    }
    else{
        cout<<"The stack is not Empty"<<endl;
    }
    isFull(S1);
    if(isFull(S1)){
    cout<<"The stack is Full"<<endl;
    }
    else{
        cout<<"The stack is not Full"<<endl;
    }
    cout<<"Stack After Pushing elements\n";
            // push(S1,10);
            // count++;
            // push(S1,12);
            // count++;
            // push(S1,13);
            // count++;
            // push(S1,14);
            // count++;
            // push(S1,15);
            // count++;
            // // Display(S1);
            // // pop(S1);
            // // pop(S1);
            // cout<<endl;
            // Display((&S1),count);

    int x=0,v=0,element=0;
    while(x!=4){
    cout<<"\nChoose\n1) Push\n2) Pop\n3) Display\n4) Exit\n==>";
    cin>>x;
        switch(x){
            case 1:
            cout<<"Type the element to push in the stack: ";
            cin>>element;
            v=push(S1,element);
            if(v!=0){
            count++;
                cout<<"The element "<<element<<" is pushed in the stack"<<endl;
            }
            v=0;
                break;
            case 2:
            v=pop(S1);
            if(v!=0){
            count--;
                cout<<"Element popped out: "<<v<<endl;
            }
            if(v==0){
                cout<<"Stack is now empty"<<endl;
            }
                break;
            case 3:
            Display((&S1),count);
                break;
            case 4:
            cout<<"Exit"<<endl;
                break;
            default:
            cout<<"Enter a valid input"<<endl;
                break;
        }
    }

    return 0;
}