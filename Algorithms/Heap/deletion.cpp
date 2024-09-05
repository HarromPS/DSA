#include <iostream>
#include <cstdio>
using namespace std;

// MaxHeap is based on Tree data structure & implemented using array or priority queue

// Implementation has changed a/c to the insertion, check below
class MaxHeap
{
public:
    int *heapArr;
    int n;
    MaxHeap(int n,int *arr)
    {
        this->n = n+1;
        this->heapArr = (int *)malloc(sizeof(int) * this->n+1);
        this->heapArr[0]=0;

        // index starts from 1
        for (int i = 1; i < this->n+1; i++)
        {
            this->heapArr[i] = arr[i-1];
        }
    }
    void deletion() // O(log n)
    {
        // swap 1st with last value & delete last element, as last value is preserved on 0th index
        this->heapArr[1]=this->heapArr[this->n-1];
        this->heapArr[this->n-1] = 0;
        this->n-=1;

        // provide the least root element its position & make the heap satisfy heap properties
        int i = 1;
        while(i<n){
            int leftChild = this->heapArr[2*i];
            int rightChild = this->heapArr[(2*i)+1];

            // find max element
            int max = (leftChild>rightChild? (2*i) : ((2*i)+1));
            if(this->heapArr[i] < this->heapArr[max]){
                int temp = this->heapArr[i];
                this->heapArr[i]=this->heapArr[max];
                this->heapArr[max]=temp;
                i = max;
            }
            else{
                break;
            }
        }


    }

    void printArray()
    {
        for (int j = 1; j < this->n; j++)
        {
            cout << this->heapArr[j] <<" ";
        }
        cout << endl;
    }
};

int main()
{
    int n = 6;
    int *a = (int *)malloc(sizeof(int) * n);
    int temp[] = {60 ,50 ,40 ,10 ,20 ,30};
    for (int i = 0; i < n; i++)
    {
        a[i] = temp[i];
    }

    // Given an already filled heap
    // Perform 3 deletion operation
    MaxHeap s(n,a);
    s.printArray();
    for(int i=1;i<=3;i++){
        s.deletion();
    }

    s.printArray();

    return 0;
}