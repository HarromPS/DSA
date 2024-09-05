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

int partition1(int *nums, int low, int high)
{
    int pivot = nums[low];
    int i = low + 1;
    int j = high;
    do
    {
        if (j >= 0 && i <= high)
        {
            while (nums[i] <= pivot)
            {
                i++;
            }
            while (nums[j] > pivot)
            {
                j--;
            }
            if (i < j)
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    } while (i < j);
    int temp = nums[j];
    nums[j] = nums[low];
    nums[low] = temp;
    return j;
}
void QuickSort(int *nums, int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition1(nums, low, high);
        QuickSort(nums, low, partitionIndex - 1);
        QuickSort(nums, partitionIndex + 1, high);
    }
}
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
    int j = high; // size-1

    do
    {
        while (arr[i] <= pivot && i < high)
        {
            i++;
        }
        while (arr[j] > pivot && j >= 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    } while (i < j);

    // Swap arr[low] & arr[j]
    swap(&arr[low], &arr[j]);

    return j;
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

    // quickSort(array2, low, high);
    QuickSort(array2, low, high);
    printf("Array After Sorting\n");
    printArray(array2, size);
    return 0;
}