#include <iostream>
#include <cstdio>
using namespace std;

// Insert to its correct position

class Solution
{
public:
    void insertionSort(int *arr, int N)
    {
        for (int i = 0; i < N - 1; i++)
        {
            int curr = i;
            for (int j = i + 1; j < N; j++)
            {
                if (arr[j] < arr[curr])
                {
                    curr = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[curr];
            arr[curr] = temp;
        }
    }

    void printArray(int *arr, int N)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Solution s;
    int n = 6;
    int *a = (int *)calloc(sizeof(int), n);
    int temp[] = {40, 20, 60, 10, 50, 30};
    for (int i = 0; i < n; i++)
    {
        a[i] = temp[i];
    }
    s.insertionSort(a, n);
    s.printArray(a,n);
    return 0;
}