#include <iostream>
#include <cstdio>
using namespace std;

// MaxHeap is based on Tree data structure & implemented using array or priority queue

// Implementation may change
class MaxHeap
{
public:
    int *heapArr;
    int n;
    MaxHeap(int n)
    {
        this->n = n;
        this->heapArr = (int *)malloc(sizeof(int) * this->n);
        for (int i = 0; i < this->n; i++)
        {
            this->heapArr[i] = 0;
        }
    }
    void insertion(int val,int size) // O(log n)
    {
        // insert at the last
        if(size>=this->n){
            cout<<"Array size full cannot insert"<<endl;
            return ;
        }
        this->heapArr[size] = val;

        int temp = size;

        // now place it to the correct position
        while(temp>0){
            int parent = temp/2;
            if(this->heapArr[parent] < this->heapArr[temp]){
                int curr = this->heapArr[parent];
                this->heapArr[parent] = this->heapArr[temp];
                this->heapArr[temp] = curr;

                temp=parent;
            }
            else {
                break;
            }
        }
        // cout<<"Insertion Successfull"<<endl;
    }

    void printArray()
    {
        for (int j = 0; j < this->n; j++)
        {
            cout << this->heapArr[j] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n = 6;
    int *a = (int *)malloc(sizeof(int) * n);
    int temp[] = {40, 20, 60, 10, 50, 30,89};
    for (int i = 0; i < n; i++)
    {
        a[i] = temp[i];
    }
    MaxHeap s(n);
    for(int i=0;i<n+1;i++){
        s.insertion(a[i],i);
    }
    s.printArray();

    return 0;
}