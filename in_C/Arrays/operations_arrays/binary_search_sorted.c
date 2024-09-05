#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Binary Search of a Sorted Array
int BinarySearch(int arr[], int size, int element)
{
    int low = 0, high = size - 1,mid = (low + high) / 2;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
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

// Sorting the array
void Sort(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        temp = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void Display(int arr[], int size_arr)
{
    for (int i = 0; i < size_arr; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()

{
    int array[] = {12, 3, 5, 4, 67, 14, 32, 15, 42};
    int size = sizeof(array) / sizeof(int), element;
    printf("The array is: ");
    Display(array, size);

    printf("The Sorted array is: ");
    Sort(array, size);
    Display(array, size);

    printf("Enter a element to search: ");
    scanf("%d", &element);
    int x = BinarySearch(array, size, element);
    if (x == -1)
    {
        printf("Element Not Found\n");
    }
    else
    {
        printf("The element %d found at index %d\n", element, x);
    }
    return 0;
}