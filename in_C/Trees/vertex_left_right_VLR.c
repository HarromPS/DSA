#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

// Trees - Can be made with the use of linked list
// In tree we have a vertex, left branch/child & right branch/child

struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right;
};
// Create a function to create branches and their nodes
// Passing the arguments, so no return to main - to update the vertex
void Create(struct Tree **vertex)
{
    int ch;
    if (*vertex != NULL)
    {
        printf("\nEnter 1 to create a left branch node\n");
        printf("Enter 2 to create a right branch node\n");
        printf("Enter 3 to exit\n==>");
        scanf("%d", &ch);
    }
    if (*vertex == NULL)
    {
        struct Tree *newNode = (struct Tree *)malloc(sizeof(struct Tree));
        printf("Enter the data for vertex node: ");
        int data;
        scanf("%d", &newNode->data);
        newNode->left = NULL;
        newNode->right = NULL;
        (*vertex) = newNode;
        Create(&vertex);
    }
    else if (ch == 1)
    {
        struct Tree *newNode = (struct Tree *)malloc(sizeof(struct Tree));
        printf("Enter the data for the left node created: ");
        int data;
        scanf("%d", &newNode->data);
        newNode->left = NULL;
        newNode->right = NULL;
        (*vertex)->left = newNode;
        Create(&(*vertex)->left);
    }
    else if (ch == 2)
    {
        struct Tree *newNode = (struct Tree *)malloc(sizeof(struct Tree));
        printf("Enter the data for the right node created: ");
        int data;
        scanf("%d", &newNode->data);
        newNode->left = NULL;
        newNode->right = NULL;
        (*vertex)->right = newNode;
        Create(&(*vertex)->right);
    }
    else
    {
        return;
    }
}

// function to transverse the tree
void TransTree(struct Tree *node)
{
    // Transversing vertex -> left -> right
    if(node==NULL)
    {
        return;
    }
    else{
        printf("(%d)->",node->data);
        TransTree(node->left);
        TransTree(node->right);
    }
}
int main()
{
    struct Tree *vertex = (struct Tree *)malloc(sizeof(struct Tree));
    vertex = NULL;
    // Creating for the left branch
    printf("Enter the details for the left branch\n");
    Create(&vertex);
    // Creating for the right branch
    printf("\nEnter the details for the right branch\n");
    Create(vertex);
    TransTree(vertex);

    return 0;
}