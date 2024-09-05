#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Deletion in an Sorted Array

// Function to Display the array
void Display(int arr[], int size_arr)
{
    for (int i = 0; i < size_arr; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort the elements in the array
void Sort(int arr[], int size_array)
{
    int temp;
    for (int i = 0; i < size_array; i++)
    {
        for (int j = 0; j < (size_array - 1 - i); j++)
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

// Function for the deletion of an element at an index
int Deletion_ind(int arr[], int size_arr, int capacity_arr, int index)
{
    if (size_arr <0)

    {
        return -1;
    }
    for (int i = index; i < size_arr - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    return index;
}

int main()
{
    int array[10] = {7, 23, 3, 42, 2};
    int arr_size = 5;   // used size of the array
    int arr_capacity = 10, delete_index = 2;
    printf("The array before Deletion is: ");
    Display(array, arr_size);
    printf("The Sorted array is: ");
    Sort(array, arr_size);
    Display(array, arr_size);
    int x = Deletion_ind(array, arr_size, arr_capacity, delete_index);
    arr_size -= 1;
    if (x == delete_index)
    {
        printf("\nDeletion Successful\nElement at index %d is deleted\n", delete_index);
        printf("The array after Deletion is: ");
        Display(array, arr_size);
    }
    else if (x == -1)
    {
        printf("The array is in overflow condition\n");
    }
    else
    {
        printf("\nDeletion Unuccessful");
        printf("\nThe array is: ");
        Display(array, arr_size);
    }

    return 0;
}