#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
Selection Sort- 
1) brings minimum element from the array to the beginning. (opp of bubble algo).
2) Minimum no of swaps.
3) No of passes = (n-1).
4) total no of comparisons = n(n-1)/2. 
5) Time complexity O(n^2).
6) not Stable,  nor Adaptive.

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
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
// Selection Sort function 
void selectionSort(int arr[],int size)
{
    int k;  // index of ith index element;
    int l,min;  // l= index of minimum element found, min= minimum element
    for(int i=0;i<size-1;i++)
    {
        min=arr[i];
        k=i;
        for(int j=i+1;j<size;j++)
        {
            if(min>arr[j])
            {
                min=arr[j];
                l=j;
            }
        }
        if(arr[k]>arr[l])
        {
            swap(&arr[k],&arr[l]);
        }
    }
}

int main()
{
    int array2[] = {1, 34, 54, 45, 23, 41, 50, 67, 34};
    // int array2[] = {8,0,7,1,3};
    // int array2[] = {3,2,4,0,5,1};
    // int array2[] = {1, 13, 5, 7, 9, 11};
    // int size = sizeof(array) / sizeof(int);

    int size = sizeof(array2) / sizeof(int);
    printf("Array Before Sorting\n");
    printArray(array2, size);

    selectionSort(array2, size);
    printf("Array After Sorting\n");
    printArray(array2, size);
    return 0;
}