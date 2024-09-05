#include<iostream>
#include<cstdio>
using namespace std;

// Creating a Queue
class Queue
{
    public: 
    int front,rear,size;
    int * arr;

    int isEmpty(){
        if(front == rear){
            // cout<<"Empty"<<endl;
            return 1;
        }
        else {
            return 0;
        }
    }

    int isFull(){
        if(rear==(size-1)){
            // cout<<"Full"<<endl;
            return 1;
        }
        else {
            return 0;
        }
    }

    void enQueue(int val){
        if(isFull())
        {
            cout<<"Queue is Full"<<endl;
            return ;
        }
        else {
            rear++;
            arr[rear]=val;
            // cout<<"Enqueued "<<arr[rear]<<endl;
        }
    }
    int deQueue(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
        }
        front++;
        return arr[front];
    }
    void printQueue()
    {
        for(int i=front+1;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};
int main(){
    Queue q;//=(Queue*)malloc(sizeof(Queue));
    q.front=-1;
    q.rear=-1;
    q.size=10;
    q.arr=(int*)calloc(sizeof(int),q.size);
    
    // BFS Traversal 
    int adj_matrix[4][4]=
    {
        {0,1,0,1},
        {1,0,1,0},
        {0,1,0,1},
        {1,0,1,0},
    };
    // initially no node is visited
    int visited[4]={0,0,0,0};
    int i;  // first node to be visited
    cout<<"Enter the first node: ";
    cin>>i;
    cout<<i<<" ";
    q.enQueue(i);
    visited[i]=i;
    while(!q.isEmpty()){
        int node=q.deQueue();
        for(int j=0;j<4;j++)
        {
            if(adj_matrix[node][j]==1 && visited[j]==0){
                cout<<j<<" ";
                visited[j]=i;
                q.enQueue(j);
            }
        }
    }
    q.printQueue();
    return 0; 
}