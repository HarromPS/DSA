#include <iostream>
#include <cstdio>
using namespace std;

class Solution
{
public:
    void merge(int *arr, int low, int mid, int high)
    {
        int i = low, j = mid + 1;
        int temp[high - low + 1];
        int k = low;
        while (i <= mid && j <= high)
        {
            if (arr[i] <= arr[j])
            {
                temp[k] = arr[i];
                k++;
                i++;
            }
            else if (arr[i] > arr[j])
            {
                temp[k] = arr[j];
                k++;
                j++;
            }
        }

        while (i <= mid)
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        while (j <= high)
        {
            temp[k] = arr[j];
            k++;
            j++;
        }

        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i];
        };
    }
    void mergeSort(int *arr, int low, int high)
    {
        if (low < high)
        {
            int mid = (low + high) / 2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            merge(arr, low, mid, high);
        }
    }
    void printArray(int *arr, int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n = 8;
    int *arr = (int *)calloc(sizeof(int), n);
    int temp[] = {35, 50, 15, 25, 80, 20, 90, 45};
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
    // arr = {35, 50, 15, 25, 80, 20, 90, 45};
    Solution *s = new Solution();
    s->mergeSort(arr, 0, n - 1);
    s->printArray(arr, n);
    return 0;
}