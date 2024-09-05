
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
/*
Recursive Merge Sorting
void mergeSort(int arr[],int loe,int mid,int high)
{
    if(low<high)
    {
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        mergeArray(arr,low,mid,high);
    }
}

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
void MergeArray(int *arr1, int low, int mid, int high);

void mergeSort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        MergeArray(arr, low, mid, high);
    }
}
void MergeArray(int *arr1, int low, int mid, int high)
{
    int size=high+1-low;
    int mergeArray[size];
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
    for (int i = low; i < high; i++)
    {
        arr1[i] = mergeArray[i];
    }
}

int main()
{
    int array[] = {7, 4, 16, 21, 8, 19, 10};
    // 7,14,16 are Sorted
    // 2,8,9,10 are Sorted

    int size = sizeof(array) / sizeof(int);
    printf("%d\n", size);

    printf("Array Before Sorting\n");
    printArray(array, size);

    // indexes low= 0, mid= 2, high= 6
    mergeSort(array, 0, size);
    printf("Array After Sorting\n");
    printArray(array, size);

    return 0;
}