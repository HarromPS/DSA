#include<iostream>
#include<cstdio>
using namespace std;

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
void flatten(struct TreeNode *root)
{
    if (root != NULL)
    {
        // preOrder traversal
        flatten(root->left);
        flatten(root->right);
        struct TreeNode *left = root->left;
        struct TreeNode *right = root->right;
        root->left = NULL;
        root->right = left;
        left = root;
        while (left != NULL && left->right != NULL)
        {
            left = left->right;
        }
        left->right = right;
    }
}
int main(){

    return 0;
}

