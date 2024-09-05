#include <iostream>
#include <cstdio>
using namespace std;

class Solution
{
public:
    int findPivotElement(int *arr, int low, int high)
    {
        int pivot = arr[low];
        int i = low + 1;
        int j = high;
        do
        {
            if (j >= 0 && i <= high)
            {

                while (arr[i] <= pivot)
                {
                    i++;
                }
                while (arr[j] > pivot)
                {
                    j--;
                }
                if (i < j)
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        } while (i < j);
        int temp = arr[j];
        arr[j] = arr[low];
        arr[low] = temp;
        return j;
    }
    void quickSort(int *arr, int low, int high)
    {
        if (low < high)
        {
            int pivot = findPivotElement(arr, low, high);
            quickSort(arr, low, pivot - 1);
            quickSort(arr, pivot + 1, high);
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
    s->quickSort(arr, 0, n - 1);
    s->printArray(arr, n);
    return 0;
}