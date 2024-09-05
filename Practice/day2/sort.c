#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void QuickSort(int *nums)
{
    for (int i = 0; i < 10; i++)
    {
        *(nums + i) = 1 - i;
    }
}

int *sortArray(int *nums)
{
    QuickSort(nums);
}

int main()
{
    int *arr = (int *)malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++)
    {
        *(arr + i) = i + 1;
    }
    sortArray(arr);
    for (int i = 9; i >=0; i--)
    {
        printf("%d ", *(arr + i));
    }
    return 0;
}