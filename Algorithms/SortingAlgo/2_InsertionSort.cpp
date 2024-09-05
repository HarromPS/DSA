#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
Insertion Sort-
1) Insertion Sort is efficient for small values
2) It is default Adaptive algorithm, it is in place sorting algorithm
3) Intermediate result is not useful.
4) No of Passes - (size-1)
5) No of Comparisons = n(n-1)/2 i.e n(n-1) => O(n^2) T.C
6) Best case T.C - O(n),    7) Stable.
*/

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

void swap1(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap2(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

// Insertion Sort without reverse
void insertionSort1(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            printf("Pass %d\n", i + 1);
            if (arr[j] < arr[j - 1])
            {
                swap1(&arr[j], &arr[j - 1]);
            }
            else
            {
                break;
            }
        }
    }
}

void reverse(int arr[], int size);
// Insertion Sort with reverse
void insertionSort2(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            if (arr[j] > arr[j - 1])
            {
                swap1(&arr[j], &arr[j - 1]);
            }
        }
    }
    reverse(arr, size);
}

void reverse(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        swap1(&arr[i], &arr[size - i - 1]);
    }
}
int main()
{
    // int array2[] = {1, 34, 54, 45, 23, 41, 50, 67, 34};
    // int array2[] = {3, 2, 4, 0, 5, 1};
    int array2[] = {0, 1, 2, 3, 4, 5};
    // int array2[] = {1, 13, 5, 7, 9, 11};
    // int size = sizeof(array) / sizeof(int);
    int size = sizeof(array2) / sizeof(int);
    printf("Array Before Sorting\n");
    printArray(array2, size);

    insertionSort1(array2, size);
    printf("Array After Sorting\n");
    // reverse(array2,size);
    printArray(array2, size);
    return 0;
}