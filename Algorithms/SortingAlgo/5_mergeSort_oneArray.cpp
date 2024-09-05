
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
/*
Merge Sort of Array elements Sorted in two different regions in the same array
int array[] = {7,14,16,2,8,9,10};
    // 7,14,16 are Sorted before index 3
    // 2,8,9,10 are Sorted after index 2
And Copied all the merged Array in the original array

1) Uses Divide & conquor rule
2) Uses Recursion
3) Merges two Sorted array of the same array 
4) Uses Auxillary -> Not in-place algorithm
5) Not Stable, Not Adaptive
5) Worst case O(n^2) 
*/

void printArray(int *arr, int size)
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
void mergeSort(int *arr1, int low, int mid, int high)
{
    int mergeArray[high];
    int k = low, i = low, j = mid + 1;
    while (i <= mid && j < high)
    {

        if (arr1[i] < arr1[j])
        {
            mergeArray[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            mergeArray[k] = arr1[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        mergeArray[k] = arr1[i];
        k++;
        i++;
    }

    while (j < high)
    {
        {
            mergeArray[k] = arr1[j];
            k++;
            j++;
        }
    }
    for (int i = 0; i < high; i++)
    {
        arr1[i] = mergeArray[i];
    }
}

int main()
{
    int array[] = {7, 14, 16, 2, 8, 9, 10};
    // 7,14,16 are Sorted
    // 2,8,9,10 are Sorted

    int size = sizeof(array) / sizeof(int);
    printf("%d\n", size);

    printf("Array Before Sorting\n");
    printArray(array, size);

    // indexes low= 0, mid= 2, high= 6
    mergeSort(array, 0, 2, size);
    printf("Array After Sorting\n");
    printArray(array, size);

    return 0;
}