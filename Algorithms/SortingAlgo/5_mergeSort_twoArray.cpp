
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
/*
Merge Sort of two Sorted arrays into a merged array
    array[] = {1, 8, 12, 22};
    array2[] = {5, 6, 11};
    mergedArray = 1, 5, 6, 8, 11, 12, 22

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
void mergeSort(int *arr1, int *arr2, int m, int n, int mergeArray[])
{
    int k = 0, i = 0, j = 0;
    while (i < m && j < n)
    {

        if (arr1[i] < arr2[j])
        {
            mergeArray[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            mergeArray[k] = arr2[j];
            k++;
            j++;
        }
    }

    while (i < m)
    {
        mergeArray[k] = arr1[i];
        k++;
        i++;
    }

    while (j < n)
    {
        {
            mergeArray[k] = arr2[j];
            k++;
            j++;
        }
    }
}

int main()
{
    int array[] = {1, 8, 12, 22};
    int array2[] = {5, 6, 11};

    int size = sizeof(array) / sizeof(int);
    int size2 = sizeof(array2) / sizeof(int);

    printf("Array Before Sorting\n");
    printf("First Array\n");
    printArray(array, size);

    printf("Second Array\n");
    printArray(array2, size2);

    int SortedArray[size + size2];
    mergeSort(array, array2, size, size2, SortedArray);
    printf("Array After Sorting\n");
    printArray(SortedArray, (size + size2));

    return 0;
}