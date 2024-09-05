#include<iostream>
#include<cstdio>
using namespace std;

#include<queue>

int main(){
    // max heap
    priority_queue<int> q;
    q.push(5);
    q.push(10);
    q.push(15);
    cout<<q.size()<<endl;
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }

    // min heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
}