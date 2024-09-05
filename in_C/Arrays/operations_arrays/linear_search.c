#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Linear Search can be done with both Sorted as well as Unsorted array
// Complexity O(n)

// Function for linear Search
int LinearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int array[]={12,3,5,4,67,4,32,5,42};
    int size=sizeof(array)/sizeof(int),element;
    printf("Enter a element to search: ");
    scanf("%d",&element);
    int x=LinearSearch(array,size,element);
    if(x==-1)
    {
        printf("Element Not Found\n");
    }
    else
    {
        printf("The element %d found at index %d\n",element,x);
    }
    return 0;
}