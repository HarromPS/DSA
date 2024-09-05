#include <iostream>
#include <cstdio>
using namespace std;

// MaxHeap is based on Tree data structure & implemented using array or priority queue

// Implementation has changed a/c to the insertion & deletion, check below
class MaxHeap
{
public:
    int *heapArr;
    int n;
    MaxHeap(int *arr,int n){
        this->n = n+1;
        this->heapArr = (int *)malloc(sizeof(int) * this->n+1);
        this->heapArr[0]=0;

        // index starts from 1
        for (int i = 1; i < this->n; i++){
            this->heapArr[i] = arr[i-1];
        }
    }

    void buildHeap() // O(n)
    {
        // start from mid level i.e n/2 (as it will serve as the last second level)
        for(int i=(this->n-1)/2;i>0;i--){
            // now heapify(make the randomized array follow the properties of heap)
            // cout<<i<<endl;
            heapify(i);
        }
    }

    void heapify(int curr){
        int maxInd = curr;

        int leftChild = 2*curr;
        int rightChild = (2*curr)+1;

        // find swapping node
        if((leftChild <= (this->n-1)) && (this->heapArr[leftChild] > this->heapArr[maxInd])){
            maxInd = leftChild;
        }
        if((rightChild <= (this->n-1)) && (this->heapArr[rightChild] > this->heapArr[maxInd] )){
            maxInd = rightChild;
        }

        // if found the node greater than currrent node
        if(maxInd != curr){
            int temp = this->heapArr[maxInd];
            this->heapArr[maxInd] = this->heapArr[curr];
            this->heapArr[curr] = temp;

            // run the same function for the swapped node, means there can be mode bottom node > swapped node
        heapify(maxInd);
        }
        else{
            return;
        }
    }

    void printArray()
    {
        for (int j = 1; j < this->n; j++)
        {
            cout << this->heapArr[j] <<" ";
        }
        cout<<endl;
    }
};

int main()
{
    int n = 7;
    int *a = (int *)malloc(sizeof(int) * n);
    int temp[] = {40, 20, 60, 10, 50, 30,90};
    for (int i = 0; i < n; i++)
    {
        a[i] = temp[i];
    }

    // Given an random array of numbers, convert/build heap tree from it
    MaxHeap s(a,n);
    s.printArray();
    s.buildHeap();
    s.printArray();

    return 0;
}