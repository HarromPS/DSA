
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

    // pivot (Element to be placed at right position)
    int pivot = arr[high];
    int i = (low - 1); // Index of smaller element and indicates the
                       // right position of pivot found so far
    int j;

    for (j = low; j <= high - 1; j++)
    {

        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int *arr, int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(arr, low, high);
        // printArray(arr,6);
        // printArray(arr,6);
        quickSort(arr, low, partitionIndex - 1);  // sort left array
        quickSort(arr, partitionIndex + 1, high); // sort right array
    }
}
int main()
{
    // int array2[] = {1, 34, 54, 45, 23, 41, 50, 67, 34};
    // int array2[] = {8,0,7,1,3};
    // int array2[] = {3,2,4,0,5,1};
    int array2[] = {1, 13, 5, 7, 1, 9, 11};
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