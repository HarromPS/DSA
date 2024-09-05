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
Max heap-> parents are larger than the childrens

                50
               /  \
            40      45
           /  \    /  \
          30  20  35   25

Min heap-> parents are smaller than the childrens

                20
               /  \
            30      40
           /  \    /  \
          50  55  60   65

Note: Max-min heaps can have different configurations
*/

/*
1) Heapify: array to heap complete binary tree
2) Insertion: inserting into the array such that it satifies heaps property & remains complete binary tree
3) Deletion: deleting node from the array & from the tree as well & tree remains complete binary tree
4) peek: topmost node of the binary tree
*/

void heapify(int arr[],int i,int size);
// coverting the array into heaped array

// sustains complete binary tree properties & heap properties also
void buildHeap(int arr[],int size){
    // start from the n/2 size as we are adjusting the parent size

    for(int i=size/2;i>0;i--){
        heapify(arr,i,size);
    }
}

void heapify(int arr[],int i,int size)
{
    // let current node be the largest one
    int large=i;
    int left_child=2*i;     // left child of current node
    int right_child=2*i+1;     // right child of current node

    // if left is from the tree & left is > current, current is left
    if(left_child<=size && arr[left_child]>arr[large]){
        large=left_child;
    }

    // if right child is from the tree & right is > current, current is right
    if(right_child<=size && arr[right_child]>arr[large]){
        large=right_child;
    }

    // if somehow current large changes, then
    if(large!=i){
        // swap
        int temp=arr[i];
        arr[i]=arr[large];
        arr[large]=temp;

        // again adjust the tree from the larges node
        heapify(arr,large,size);
    }
    else {
        return;
    }
}

void change(int arr[],int size){
    for(int i=0;i<size;i++){
        arr[i]=0;
    }
}
int main()
{
    // complete binary tree random tree
    int array[]={0,10,30,50,20,35,15};
    int size=sizeof(array)/sizeof(int);
    for(int i=1;i<size;i++){
        printf("%d ",array[i]);
    }
    printf("\n");

    buildHeap(array,size-1);
    for(int i=1;i<size;i++ ){
        printf("%d ",array[i]);
    }

    // max heap insertion
    // TreeNode *one = (TreeNode *)malloc(sizeof(TreeNode) * 1);
    // one->data = 50;

    // TreeNode *two = (TreeNode *)malloc(sizeof(TreeNode) * 1);
    // two->data = 40;

    // TreeNode *three = (TreeNode *)malloc(sizeof(TreeNode) * 1);
    // three->data = 45;

    // TreeNode *four = (TreeNode *)malloc(sizeof(TreeNode) * 1);
    // four->data = 30;

    // TreeNode *five = (TreeNode *)malloc(sizeof(TreeNode) * 1);
    // five->data = 20;

    // TreeNode *six = (TreeNode *)malloc(sizeof(TreeNode) * 1);
    // six->data = 35;

    // TreeNode *seven = (TreeNode *)malloc(sizeof(TreeNode) * 1);
    // seven->data = 25;

    // one->left = two;
    // one->right = three;
    // two->left = four;
    // two->right = five;
    // three->left = six;
    // three->right = seven;
    // four->left = four->right = NULL;
    // five->left = five->right = NULL;
    // six->left = NULL;
    // seven->left = NULL;
    // six->right = NULL;
    // seven->right = NULL;

    // int h = height(one);
    // // for(int i=h;i>0;i--){
    // //     levelOrder(one,i);
    // //     printf("\n");
    // // }
    // int *array = (int *)calloc(sizeof(int), 15);
    // for (int i = 1; i <= h; i++)
    // {
    //     levelOrder(one, i, array);
    //     printf("\n");
    // }

    return 0;
}