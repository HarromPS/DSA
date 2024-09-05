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
Heap -> Tree Based data structure given that the tree is a complete binary tree & satisfies heap's property

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
*/

/*
1) Heapify: array to heap complete binary tree
2) Insertion: inserting into the array such that it satifies heaps property & remains complete binary tree
3) Deletion: deleting node from the array & from the tree as well & tree remains complete binary tree
4) peek: topmost node of the binary tree
*/

int k = 1;
void levelOrder(TreeNode *root, int level, int *arr)
{
    if (root == NULL)
    {
        return;
    }
    if (level == 1)
    {
        printf("%d ", root->data);
        arr[k] = root->data;
        k++;
    }
    else if (level > 1)
    {
        levelOrder(root->left, level - 1, arr);
        levelOrder(root->right, level - 1, arr);
    }
}

int height(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);
    return (left > right ? left : right) + 1;
}

/*
Insertion in heap array
- index starts from 1 & is upto size of array
*/
void insert(int *arr, int nodes, int val)
{
    nodes += 1;
    arr[nodes] = val;
    int temp = nodes;
    while (temp > 1)
    {
        int parent = temp/2;
        if (arr[parent] < arr[temp])
        {
            int x = arr[parent];
            arr[parent] = arr[temp];
            arr[temp] = x;
            temp=parent;
        }
        else {
            break;
        }
    }
}

void deleteNode(int *arr, int nodes)
{
    arr[1] = arr[nodes];
    nodes -= 1;
    int i = 1;
    while (i < nodes)
    {
        if (2 * i > nodes || (2 * i + 1) > nodes)
        {
            break;
        }
        else
        {
            int left = arr[2 * i];
            int right = arr[2 * i + 1];
            int larger = (left > right ? 2 * i : 2 * i + 1);
            if (arr[i] > larger)
            {
                int x = arr[i];
                arr[i] = arr[larger];
                arr[larger] = x;
                i=larger;
            }
        }
    }
}
int main()
{
    // max heap insertion
    TreeNode *one = (TreeNode *)malloc(sizeof(TreeNode) * 1);
    one->data = 50;

    TreeNode *two = (TreeNode *)malloc(sizeof(TreeNode) * 1);
    two->data = 40;

    TreeNode *three = (TreeNode *)malloc(sizeof(TreeNode) * 1);
    three->data = 45;

    TreeNode *four = (TreeNode *)malloc(sizeof(TreeNode) * 1);
    four->data = 30;

    TreeNode *five = (TreeNode *)malloc(sizeof(TreeNode) * 1);
    five->data = 20;

    TreeNode *six = (TreeNode *)malloc(sizeof(TreeNode) * 1);
    six->data = 35;

    TreeNode *seven = (TreeNode *)malloc(sizeof(TreeNode) * 1);
    seven->data = 25;

    one->left = two;
    one->right = three;
    two->left = four;
    two->right = five;
    three->left = six;
    three->right = seven;
    four->left = four->right = NULL;
    five->left = five->right = NULL;
    six->left = NULL;
    seven->left = NULL;
    six->right = NULL;
    seven->right = NULL;

    int h = height(one);
    // for(int i=h;i>0;i--){
    //     levelOrder(one,i);
    //     printf("\n");
    // }
    int *array = (int *)calloc(sizeof(int), 15);
    for (int i = 1; i <= h; i++)
    {
        levelOrder(one, i, array);
        printf("\n");
    }

    for (int i = 1; i <= 7; i++)
    {
        printf("%d ", array[i]);
    }

    // get inserted into the array
    printf("\n");
    insert(array, 7, 60);   // 7 is the current size & will get increased by one after going through the function
    for (int i = 1; i <= 8; i++)
    {
        printf("(%d %d), ", array[i], i);
    }
    printf("\n");

    // deletion
    deleteNode(array,8);    // current size
    for(int i=1;i<=7;i++){
        printf("%d ",array[i]);
    }
    return 0;
}