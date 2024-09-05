#include <iostream>
#include <cstdio>
using namespace std;

// Linear Search

int linearSearch(int arr[], int element, int size)
{
    int i = 0;
    while (i < size)
    {
        if (arr[i] == element)
        {
            return i;
        }
        else
        {
            i++;
        }
    }
    return 0;
}

int linearSearchRecursive(int arr[], int element, int size)
{
    static int i;
    if (i == size)
    {
        return 0;
    }
    else if (arr[i] == element)
    {
        return i;
    }
    else
    {
        i++;
        return linearSearchRecursive(arr, element, size);
    }
}
int main()
{
    int arr[] = {12, 2, 354, 32, 434, 24, 4, 56, 565};
    int size = sizeof(arr) / sizeof(int);
    int ele;
    printf("Enter the element to search: ");
    scanf("%d", &ele);
    int result = linearSearch(arr, ele, size);
    if (result == 0)
    {
        cout << ele << " Not Found" << endl;
    }
    else
    {
        cout << ele << " Found at index " << result << endl;
    }
    printf("Enter the element to search recursively: ");
    scanf("%d", &ele);
    result = linearSearchRecursive(arr, ele, size);
    if (result == 0)
    {
        cout << ele << " Not Found" << endl;
    }
    else
    {
        cout << ele << " Found at index " << result << endl;
    }
    return 0;
}