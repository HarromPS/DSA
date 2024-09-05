#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Insertion & deletion program

// Function to display the array
void Display(int arr[], int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", arr[i]);
    }
}
int Insertion(int arr[], int array_size, int element, int capacity, int index)
{
    if (array_size > capacity)
    {
        return -1;
    }
    for (int i = array_size - 1; i >= index; --i)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return index;
}

int Deletion(int arr[], int array_size, int index, int capacity)
{
    if (array_size < capacity)
    {
        return -1;
    }
    for (int i = index; i <= array_size; i++)
    {
        arr[i] = arr[i + 1];
    }
    return index;
}
int main()
{
    // Driver's code
    int array[10] = {12, 3, 4353, 23};
    int size = 4, capacity = 10, index, element, x = 0;
    printf("The array is: ");
    Display(array, size);

    while (x != 3)
    {
        printf("\nChoose\n1) Insertion\n2) Deletion\n3) Exit\n==>");
        scanf("%d", &x);
        index = 0;
        switch (x)
        {
        case 1:
            printf("Enter index & element to insert: \n");
            printf("Index: ");
            scanf("%d", &index);
            printf("Element: ");
            scanf("%d", &element);
            int result = Insertion(array, size, element, capacity, index);
            size += 1;
            if (result == -1)
            {
                printf("Insertion Failed\nSpace Full\n");
            }
            else
            {
                printf("Insertion Successful\nElement inserted at index %d\n", index);
                printf("The array is: ");
                Display(array, size);
                printf("\n");
            }
            break;
        case 2:
            printf("Enter index number to delete the element: \n");
            printf("Index: ");
            scanf("%d", &index);
            Deletion(array, size, index, capacity);
            size -= 1;
            if (result == -1)
            {
                printf("Deletion Failed\nNo element\n");
            }
            else
            {
                printf("Deletion Successful\nElement deleted at index %d", index);
                printf("h\nThe array is: ");
                Display(array, size);
                printf("\n");
            }
            break;
        case 3:
            printf("EXIT!\n");
            break;
        default:
            printf("Finish\n");
            break;
        }
    }
    return 0;
}