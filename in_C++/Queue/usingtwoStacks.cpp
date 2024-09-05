#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

// Queue using two stacks
// Method 1 - enQueue O(n)
//            deQueue O(1)
class Queue
{
public:
    vector<int> s1, s2;
    void enQueue(int val)
    {
        // copy all the elements to s2
        while (!s1.empty())
        {
            s2.push_back(s1.front());
            s1.pop_back();
        }
        s1.push_back(val); // last entered to s1
        cout << "Enqueued " << s1.front() << endl;

        // copy back all the elements from s2 to s1
        while (!s2.empty())
        {
            s1.push_back(s2.front());
            s2.pop_back();
        }
    }

    int deQueue()
    {
        if (s1.empty())
        {
            cout << "Queue is Empty\n";
        }
        int x;
        x = s1.front();
        s1.pop_back();
    }
    void printQueue()
    {
        cout<<"Printing Queue:: "<<endl;
        int x=s1.size();
        for (int i = 0; i <x; i++)
        {
            cout << s1[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Queue q;
    q.enQueue(12);
    q.enQueue(112);
    q.enQueue(43);
    q.enQueue(6);
    q.printQueue();
    cout<<"Dequeued "<<q.deQueue()<<endl;

    return 0;
}