#include <iostream>
#include <cstdio>
using namespace std;

// Q1. Find the missing element from the array
int Solution(int arr[], int n)
{
    // Sorting the array first
    int temp;
    for (int i = 0; i < n; ++i)
    {
        temp = 0;
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "\nThe Sorted array is:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    // Comparing & finding missing element
    for (int i = 1; i <= n; ++i)
    {
        if (i != arr[i])
        {
            return i;
        }
    }
}
int main()
{
    int n;
    cout << "Enter a size of array: ";
    cin >> n;
    // Array of Natural Numbers
    int array[n];
    cout << "Enter the elements of the array\n";
    for (int i = 0; i < n; ++i)
    {
        cout << i + 1 << ": ";
        cin >> array[i];
    }
    cout << "\nThe array is:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << array[i] << " ";
    }
    int result = Solution(array, n);
    cout << "\nThe missing element in your array is:: ";
    cout << result << endl;

    return 0;
}