#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/*
Count Sort-
1) One of the Fastest Sorting algorithm
2) Find max element in the array & create an auxillary array with size
(max element + 1)
3) And inititlaize all elements with zero.
4) Traverse from the original array and put 1 at the index number of the element
else put zero (0)
e.g 1, 12, 4, 9, 13, 4, 4
e.g 0  1  2  3  4  5  6  7  8  9  10  11  12  13
    0, 1, 0, 0, 3, 0, 0, 0, 0, 1, 0,  0,  1,  1
Increment of the elements of the "original array elements as the indexes"

5) Traverse the Auxillary array.
6) Decrement the elment of the auxillary arry element until the element in it is not equal to zero & put array's jth position j++;
*/

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

int maxElement(int arr[],int size)
{
    int max=arr[0];
    for(int i=1;i<size;i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
        }
    }
    return max;
}
void countSort(int *arr, int size)
{
    int max=maxElement(arr,size)+1;
    int *cout = (int *)calloc(max, sizeof(int));
    int j=0;
    for(int i=0;i<size;i++)
    {
        cout[arr[i]]++;
    }
    for(int i=0;i<max;i++)
    {
        if(cout[i]!=0)
        {
            while(cout[i]>0)
            {
                cout[i]--;
                arr[j]=i;
                j++;
            }
        }
    }
}
int main()
{
    // int array2[] = {3, 1, 9, 7, 1, 2, 4};
    int array2[] = {7,6,5,4,3,2,1};
    int size = sizeof(array2) / sizeof(int);
    printf("Array Before Sorting\n");
    printArray(array2, size);

    countSort(array2, size);
    printf("Array After Sorting\n");
    printArray(array2, size);
    return 0;
}