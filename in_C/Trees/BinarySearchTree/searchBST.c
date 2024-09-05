#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

// Binary Tree is represented in two ways - Arrays & Linked
// There are limitations of Arrays of size
// In linked representationswe use doubly Linked list
// int data, node* left, node* right

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
        root->left=createNode(root->left);
    }

    printf("Do you have right node?\n1 for yes, 0 for no\n=>");
    scanf("%d", &x);
    if (x == 1)
    {
        root->right=createNode(root->right);
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

// function to search a key in the Binary Search Tree
int search(Node* root,int key){
    if(root==NULL){
        return -1;
    }
    while(root!=NULL){
        if(key==root->data){
            return root->data;
        }
        else if(key<root->data){
            root=root->left;
        }
        else if(key>root->data){
            root=root->right;
        }
    }
    return -1;
}
int main()
{
    Node *root = NULL;
    root = createNode(root);
    // transversal(root);
    // // printf("NULL\n");
    // printf("The preOrder transversal\n");
    // preOrder(root);
    // printf("NULL\n");

    // printf("The inOrder transversal\n");
    // inOrder(root);
    // printf("NULL\n");

    // printf("The postOrder transversal\n");
    // postOrder(root);
    // printf("NULL\n");
    int element;
    printf("Enter node to search in the element: ");
    scanf("%d",&element);
    int p=search(root,element);
    if(p!=-1)
    {
        printf("Element found: %d\n",p);
    }
    else{
        printf("Element Not found");

    }

    return 0;
}