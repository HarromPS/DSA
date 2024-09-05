#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

/*
Binary Search Tree where
-- all nodes in left side is lesser than root node
-- all nodes in right side is greater than root node
-- no duplicate nodes
-- inOrder traversal gives a ascending order sorted array
*/

// Syntax for structure:
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;
// Function for the creation of a tree
Node *newNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node *createNode(Node *root)
{
    if (root == NULL)
    {
        printf("Enter the data for the node\n");
        int data;
        scanf("%d", &data);
        root = newNode(data);
    }

    printf("Do you have left node?\n1 for yes, 0 for no\n=>");
    int x;
    scanf("%d", &x);
    if (x == 1)
    {
        root->left = createNode(root->left);
    }

    printf("Do you have right node?\n1 for yes, 0 for no\n=>");
    scanf("%d", &x);
    if (x == 1)
    {
        root->right = createNode(root->right);
    }

    return root;
}
void transversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("(%d)->", root->data);
        transversal(root->left);
        transversal(root->right);
    }
}
void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("(%d)->", root->data);
        transversal(root->left);
        transversal(root->right);
    }
}
void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        transversal(root->left);
        printf("(%d)->", root->data);
        transversal(root->right);
    }
}
void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        transversal(root->left);
        transversal(root->right);
        printf("(%d)->", root->data);
    }
}
int isBST(Node *root)
{
    static Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}
int main()
{
    Node *root = NULL;
    root = createNode(root);
    // transversal(root);
    // printf("NULL\n");
    // printf("The preOrder transversal\n");
    // preOrder(root);
    // printf("NULL\n");

    // printf("The inOrder transversal\n");
    // inOrder(root);
    // printf("NULL\n");

    // printf("The postOrder transversal\n");
    // postOrder(root);
    // printf("NULL\n");
    int result=isBST(root);
    if(result==1)
    {
        printf("\nThis is a BST\n");
    }
    else{
        printf("\nThis is not a BST\n");
    }
    return 0;
}