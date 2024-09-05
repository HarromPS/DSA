#include <iostream>
#include <cstdio>
using namespace std;

// Non-comparison based algorithm
// Works of floating point numbers in range 0 to 1
// Inputs should be uniformly & independtly distributed across [0-1] to get a
// running time of O(n)

class Solution
{
public:
    void bucketSort(int *arr, int n){

    }

    void printArray(int *arr, int n)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n = 6;
    int *a = (int *)malloc(sizeof(int) * n);
    int temp[] = {40, 20, 60, 10, 50, 30};
    for (int i = 0; i < n; i++)
    {
        a[i] = temp[i];
    }
    Solution s;
    s.bucketSort(a, n);
    s.printArray(a, n);
    return 0;
}