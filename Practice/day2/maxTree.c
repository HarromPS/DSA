#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *createTree(int *arr, int originalSize)
{
    if (originalSize == 0)
    {
        return NULL;
    }
    int k = 0, index = 0;
    for (int i = 0; i < originalSize; i++)
    {
        if (k < arr[i])
        {
            k = arr[i];
            index = i;
        }
    }

    struct TreeNode *n = (struct TreeNode *)malloc(sizeof(struct TreeNode) * 1);
    n->val = k;
    printf("%d ", n->val);
    n->left = createTree(arr, index);
    n->right = createTree(arr + index + 1, originalSize - index - 1);
    return n;
}
struct TreeNode *constructMaximumBinaryTree(int *nums, int numsSize)
{
    return createTree(nums, numsSize);
}
void inOrder(struct TreeNode *node)
{
    if (node != NULL)
    {
        printf("%d ", node->val);
        inOrder(node->left);
        inOrder(node->right);
    }
}
int main()
{
    int arr[] = {3, 2, 1, 6, 0, 5};
    struct TreeNode *n = constructMaximumBinaryTree(arr, 6);

    return 0;
}
