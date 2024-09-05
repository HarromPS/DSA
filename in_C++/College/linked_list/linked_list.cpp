#include<iostream>
#include<cstdio>
using namespace std;

// Creating a linked list program
typedef struct Node
{
    int data;
    struct Node* next;
}Node;

int main()
{
    int n;
    cout<<"Type how many data members are there: ";
    cin>>n;
    // Dynamic memory allocation
    Node *ptr=(Node*)malloc(sizeof(Node)*n);
    for(int i=0;i<n;i++)
    {
        cout<<"Enter data of "<<i+1<<" Node: ";
        cin>>ptr->data;        
        ptr->next=ptr;
        ptr++;
    }
    cout<<"The data in the Node are: "<<endl;
    for(int i=0;i<n;i++)
    {
        ptr--;
        if(i<(n-1)){
        cout<<ptr->data<<"->";
        }
        else{
            cout<<ptr->data;
        }
   
        
    }

    return 0; 
}