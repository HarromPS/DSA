#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data;                                 // Setting the data
    n->left = NULL;                                 // Setting the left and right children to NULL
    n->right = NULL;                                // Setting the left and right children to NULL
    return n;                                       // Finally returning the created node
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int Height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return (Height(root->left) > Height(root->right) ? Height(root->left) : Height(root->right)) + 1;
}
void leftView(struct node *root, int *array, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (array[level] == -1)
    {
        array[level] = root->data;
    }
    leftView(root->left, array, level + 1);
    leftView(root->right, array, level + 1);
}

void rightView(struct node *root, int *array, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (array[level] == -1)
    {
        array[level] = root->data;
    }
    rightView(root->right, array, level + 1);
    rightView(root->left, array, level + 1);
}
int main()
{

    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(8);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(1);
    struct node *p3 = createNode(6);
    struct node *p4 = createNode(4);
    struct node *p5 = createNode(7);
    struct node *p6 = createNode(10);
    struct node *p7 = createNode(14);
    struct node *p8 = createNode(13);
    // Finally The tree looks like this:
    //      8
    //     / \
    //    3   10
    //   / \     \
    //  1  6      14
    //    /  \     /
    //   4   7    13

    // Left view -> 8 3 1 4
    // Right view -> 8 10 14 13
    // Linking the root node with left and right children
    p->left = p1;
    p->right = p6;
    p1->left = p2;
    p1->right = p3;
    p6->right = p7;
    p6->left = NULL;
    p2->left = p2->right = NULL;
    p3->left = p4;
    p3->right = p5;
    p7->left = p8;
    p7->right = NULL;
    p8->left = p8->right = NULL;

    int size = Height(p);
    // printf("%d ",size);
    int array[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = -1;
    }

    leftView(p, array, 0);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    for (int i = 0; i < size; i++)
    {
        array[i] = -1;
    }
    rightView(p, array, 0);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}