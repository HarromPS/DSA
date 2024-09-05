#include <iostream>
#include <cstdio>
#include <math.h>
#include <climits>
using namespace std;

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

// height of a tree
int height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}

int diameter(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int dl = diameter(root->left);
    int dr = diameter(root->right);

    int current = height(root->left) + height(root->right) + 1;

    return max(current, max(dl, dr));
}

// optimized height code gives direct diameter
int dia = 0;
int height2(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int hl = height2(root->left);
    int hr = height2(root->right);

    dia = max(dia, (hl, hr + 1));
    return max(hl, hr) + 1;
}

int main()
{

    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    struct node *p5 = createNode(10);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4
    //      /
    //     10

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p2->left = NULL;
    p2->right = NULL;
    p3->left = NULL;
    p3->right = NULL;
    p1->right = p4;
    p4->left = p5;
    p4->right = NULL;
    p5->left = NULL;
    p5->right = NULL;

    return 0;
}