#include <iostream>
#include <cstdio>
using namespace std;
// Jump Search
// Jump Search is performed on Sorted elements

int jumpSearch1(int arr[], int element, int size)
{
    for (int i = 0; i <= size / 3; i++)
    {
        if (element <= arr[3 * i])
        {
            for (int j = (3 * i) - 3; j <= 3 * i; j++)
            {
                if (arr[j] == element)
                {
                    return j;
                }
            }
        }
    }
    for (int k = size - 3; k < size; k++)
    {
        if (arr[k] == element)
        {
            return k;
        }
    }

    return -1;
}
int jumpSearch2(int arr[], int element, int size, int key)
{
    for (int i = 0; i <= size / key; i++)
    {
        if (element <= arr[key * i])
        {
            for (int j = (key * i) - key; j <= key * i; j++)
            {
                if (arr[j] == element)
                {
                    return j;
                }
            }
        }
    }
    for (int k = size - key; k < size; k++)
    {
        if (arr[k] == element)
        {
            return k;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29};
    int size = sizeof(arr) / sizeof(int);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int ele;
    printf("Enter the element to search: ");
    scanf("%d", &ele);
    int result = jumpSearch1(arr, ele, size);
    if (result == -1)
    {
        cout << ele << " Not Found" << endl;
    }
    else
    {
        cout << ele << " Found at index " << result << endl;
    }
    
    int key;
    cout << "Enter the block size to jump: ";
    cin >> key;
    result = jumpSearch2(arr, ele, size, key);
    if (result == -1)
    {
        cout << ele << " Not Found" << endl;
    }
    else
    {
        cout << ele << " Found at index " << result << endl;
    }
    // printf("Enter the element to search recursively: ");
    // scanf("%d", &ele);
    // int low = 0, high = size - 1, mid;
    // result = binarySearchRecursive(arr, ele, low, high, mid);
    // if (result == -1)
    // {
    //     cout << ele << " Not Found" << endl;
    // }
    // else
    // {
    //     cout << ele << " Found at index " << result << endl;
    // }

    return 0;
}