#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Transverse Code
void Display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// function for Sorting the array
void Sort(int arr[], int size_array)
{
    int temp=0;
    for (int i = 0; i <= size_array; i++)
    {
        for (int j = 0; j <(size_array - i-1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp=arr[j];
                arr[j] = arr[j + 1];
                arr[j+1]=temp;
            }
        }
    }
}

// Sorted Insertion Code
int InsertionInd(int arr[], int index, int element, int size_array, int capacity_array)
{
    if (size_array >= capacity_array) // if the size of the array is in overflow
                                      // then return -1
    {
        return -1;
    }
    // Shifting all the elements after the index
    for (int i = size_array - 1; i >= index; --i)
    {
        arr[i + 1] = arr[i];
    }
    // When all the elements are shifted inset the element at the given index
    arr[index] = element;
    return index;
}
int main()
{
    int arr[10] = {7, 18, 12, 27, 9};
    int size_array = 5, index = 2, element = 45;

    printf("Before Insertion operation\nThe array is: ");
    Display(arr, size_array);
    Sort(arr, size_array);
    printf("The Sorted array is: ");
    Display(arr,size_array);

    int x = InsertionInd(arr, index, element, size_array, 100);

    size_array += 1;
    if (x == index)
    {
        printf("\nInsertion Successful\nElement Inserted at index: %d ", x);
        printf("\nThe array is: ");
        Display(arr, size_array);
    }
    else if (x == -1)
    {
        printf("The array is in overflow condition\n");
    }
    else
    {
        printf("\nInsertion Unuccessful");
        printf("\nThe array is: ");
        Display(arr, size_array);
    }
    return 0;
}