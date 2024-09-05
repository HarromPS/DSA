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

// Unsorted Insertion Code
int indInsertion(int arr[], int index, int element, int size, int capacity)
{
    if (size >= capacity) // if the size of the array is in overflow
                          // then return -1
    {
        return -1;
    }

    // Shifting all the elements after the index
    for (int i = size - 1; i >= index; --i)
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
    int size = 5, index = 2, element = 45;

    printf("Before Insertion operation\nThe array is: ");
    Display(arr, size);

    int x = indInsertion(arr, index, element, size, 100);

    size += 1;
    if (x == index)
    {
        printf("\nInsertion Successful\nElement Inserted at index: %d ", x);
        printf("\nThe array is: ");
        Display(arr, size);
    }
    else
    {
        printf("The array is in overflow condition\n");
    }
    return 0;
}