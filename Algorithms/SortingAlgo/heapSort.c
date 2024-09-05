#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

/*
Heap Sort-> using heap to sort the array
1) convert the array into heap using heapbuild function
2) start deleting nodes(just swap the 1st & last positions) from root value & heapify the array
*/

void heapify(int arr[], int i, int size);
// coverting the array into heaped array

// sustains complete binary tree properties & heap properties also
void buildHeap(int arr[], int size)
{
    // start from the n/2 nodes as we are adjusting the parent nodes

    for (int i = size / 2; i > 0; i--)
    {
        heapify(arr, i, size);
    }
}

void heapify(int arr[], int i, int size)
{
    // let current node be the largest one
    int large = i;
    int left_child = 2 * i;      // left child of current node
    int right_child = 2 * i + 1; // right child of current node

    // if left is from the tree & left is > current, current is left
    if (left_child <= size && arr[left_child] > arr[large])
    {
        large = left_child;
    }

    // if right child is from the tree & right is > current, current is right
    if (right_child <= size && arr[right_child] > arr[large])
    {
        large = right_child;
    }

    // if somehow current large changes, then
    if (large != i)
    {
        // swap
        int temp = arr[i];
        arr[i] = arr[large];
        arr[large] = temp;

        // again adjust the tree from the larges node
        heapify(arr, large, size);
    }
    else
    {
        return;
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapSort(int arr[], int size)
{
    // 1) build the heap from the array
    buildHeap(arr, size);

    // 2) delete root nodes one by one
    for (int i = size; i > 1; i--)
    {
        // just swap the first & last node
        swap(&arr[1], &arr[i]);

        // heapify the array from root node
        // i - 1 i.e remove the swapped largest node
        heapify(arr, 1, i-1);
    }
}

int main()
{
    // complete binary tree random tree
    int array[] = {0, 40, 10, 30, 50, 60, 15};
    int size = sizeof(array) / sizeof(int);
    // swap(&array[0],&array[6]);
    for (int i = 1; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    heapSort(array, size - 1);
    for (int i = 1; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}