#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
Bubble Sort - sends the large elements to the end
1) No of passes - (n-1)
2) No of comparisons - n(n-1)/2
3) Time Complexity- O(n^2)

4) Non adaptive by default but can be made adaptive by
doing first pass & check if the array is sorted or not if yes
ignore next passes.
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

// This is Bubble Sort Function
void bubbleSort1(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d pass\n", i + 1);
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Passing address of address of the elements
                swap1(&arr[j], &arr[j + 1]);

                // Passing address
                // swap2(&arr[j], &arr[j + 1]);

                // // Swapping using third variable
                // int temp=arr[j];
                // arr[j]=arr[j+1];
                // arr[j+1]=temp;

                // Swapping without third variable
                // arr[j]=arr[j]+arr[j+1];
                // arr[j+1]=arr[j]-arr[j+1];
                // arr[j]=arr[j]-arr[j+1];
            }
        }
    }
}
// This Bubble Sort Function is Adaptive
void bubbleSort2(int *arr, int size)
{
    int isSorted = 0;
    for (int i = 0; i < size - 1; i++)
    {
        isSorted = 1;
        printf("%d pass\n", i + 1);
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Passing address of address of the elements
                swap1(&arr[j], &arr[j + 1]);

                // Passing address
                // swap2(&arr[j], &arr[j + 1]);

                // // Swapping using third variable
                // int temp=arr[j];
                // arr[j]=arr[j+1];
                // arr[j+1]=temp;

                // Swapping without third variable
                // arr[j]=arr[j]+arr[j+1];
                // arr[j+1]=arr[j]-arr[j+1];
                // arr[j]=arr[j]-arr[j+1];
                isSorted = 0;
            }
        }
        if (isSorted == 1)
        {
            break;
        }
    }
}

int main()
{
    int array2[] = {1, 34, 54, 45, 23, 41, 50, 67, 34};
    // int array2[] = {1, 13, 5, 7, 9, 11};
    // int size = sizeof(array) / sizeof(int);
    int size = sizeof(array2) / sizeof(int);
    printf("Array Before Sorting\n");
    printArray(array2, size);
    bubbleSort1(array2, size);
    printf("Array After Sorting\n");
    printArray(array2, size);

    bubbleSort2(array2, size);
    printf("Array After Sorting Adaptively\n");
    printArray(array2, size);

    return 0;
}