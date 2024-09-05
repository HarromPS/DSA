#include <iostream>
#include <cstdio>
using namespace std;
// Binary Search
// Binary Search is performed on Sorted elements

int swap(int *a, int *b);
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int swap(int *a, int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}
int binarySearch(int arr[], int element, int size)
{
    int low = 0, high = size - 1, mid;
    if (arr[low] == element)
    {
        return low;
    }
    else if (arr[high] == element)
    {
        return high;
    }
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int binarySearchRecursive(int arr[], int element, int low, int high, int mid)
{
    if (arr[low] == element)
    {
        return low;
    }
    else if (arr[high] == element)
    {
        return high;
    }
    if (low <= high)
    {
        mid = (high + low) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
            return binarySearchRecursive(arr, element, low, high, mid);
        }
        else
        {
            high = mid - 1;
            return binarySearchRecursive(arr, element, low, high, mid);
        }
    }
    else
    {
        return -1;
    }
}
int main()
{
    int arr[] = {12, 2, 35, 32, 43, 24, 4, 56, 58};
    int size = sizeof(arr) / sizeof(int);
    bubbleSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int ele;
    printf("Enter the element to search: ");
    scanf("%d", &ele);
    int result = binarySearch(arr, ele, size);
    if (result == -1)
    {
        cout << ele << " Not Found" << endl;
    }
    else
    {
        cout << ele << " Found at index " << result << endl;
    }
    printf("Enter the element to search recursively: ");
    scanf("%d", &ele);
    int low = 0, high = size - 1, mid;
    result = binarySearchRecursive(arr, ele, low, high, mid);
    if (result == -1)
    {
        cout << ele << " Not Found" << endl;
    }
    else
    {
        cout << ele << " Found at index " << result << endl;
    }

    return 0;
}