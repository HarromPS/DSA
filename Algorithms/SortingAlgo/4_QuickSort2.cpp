#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
Quick Sort-
1) Uses Divide & conquor rule
2) Uses Recursion
3) Pick 1st element as the pivot element 
4) It is a partition where smaller elements are on left side of pivot
& greater elements are on the right side of pivot.
5) Worst case O(n^2) & Best case O(n log n)
6) Not Stable, Not Adaptive, In-place Algorithm

*/

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    do
    {
        if (j >= 0 && i <= high)
        {
            // while (pivot > arr[i])
            // {
            //     i++;
            // }
            // while (pivot <= arr[j])
            // {
            //     j--;
            // }
            // if (i < j)
            // {
            //     swap(&arr[i], &arr[j]);
            // }
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
                swap(&arr[i], &arr[j]);
            }
        }
    } while (i < j);

    // swap the pivot element and element at jth postion(element > than pivot)
    swap(&arr[low], &arr[j]);

    // return the position of the pivot placed to its correct position
    return j;
}
void quickSort(int *arr, int low, int high)
{
    int partitionIndex = 0;
    if (low < high)
    {
        partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);  // partition on left
        quickSort(arr, partitionIndex + 1, high); // partition on right
    }
}
int main()
{
    int array2[] = {2, 4, 3, 9, 1, 4, 8, 7, 5, 6};
    // int size = sizeof(array) / sizeof(int);
    int size = sizeof(array2) / sizeof(int);
    printf("Array Before Sorting\n");
    printArray(array2, size);
    int low = 0;
    int high = size - 1;

    quickSort(array2, low, high);
    printf("Array After Sorting\n");
    printArray(array2, size);
    return 0;
}