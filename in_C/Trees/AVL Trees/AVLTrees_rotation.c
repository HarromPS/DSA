#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
1) AVL Tree is a Height balancing tree
2) Diff Betn (Height right subtree - Height left subtree) is <=1 .
3) Balanaced Factor (B.F = Height right subtree - Height left subtree)
    B.F ranges (-1,0,1).
    for all nodes for a balanced tree " mod(B.f) <= 1 "
4) if (B.F > 1) => performs AVL tree Rotations
*/

struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
    int height;
};

int getHeight(struct Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

struct Node *create(int val)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int getBalanceFactor(struct Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    else
    {
        return getHeight(n->left) - getHeight(n->right);
    }
}

int max(int left, int right)
{
    if (left > right)
    {
        return left;
    }
    return right;
}
struct Node *rightRotate(struct Node *y) // root of left subtree
{
    struct Node *x = y->left;   // x will be the root then
    struct Node *t2 = x->right; // t2 as the left node of y

    x->right = y;
    y->left = t2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right; // setting the previous tree
    struct Node *t2 = y->left;

    y->left = x;    // setting the rotated tree
    x->right = t2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return y;
}

// Insertion in BST=> Bottom to Top approach
struct Node *insert(struct Node *node, int val)
{
    if (node == NULL)
    {
        return create(val);
    }

    if (val < node->data)
    {
        node->left = insert(node->left, val);
    }
    else if (val > node->data)
    {
        node->right = insert(node->right, val);
    }

    // updates the height of every node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int bF = getBalanceFactor(node);
    // node->balanceFactor = bF;

    // INSERT + ROTATE
    // left left rotation
    if (bF > 1 && val < node->left->data)
    {
        return rightRotate(node);
    }

    // right right rotation
    if (bF < -1 && val > node->right->data)
    {
        return leftRotate(node);
    }

    // left right rotation
    if (bF > 1 && val > node->left->data)
    {
        // left rotate w.r.t first child of the first unbalanced node
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // right left rotation
    if (bF < -1 && val < node->right->data)
    {
        // right rotate w.r.t first child of the first unbalanced node
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

// traverse the tree
void inOrder(struct Node *n)
{
    if (n == NULL)
    {
        return;
    }
    else
    {
        inOrder(n->left);
        printf("%d ", n->data);
        inOrder(n->right);
    }
}
int main()
{
    struct Node *head = NULL;

    for(int i=0;i<6;i++){
        head = insert(head, i+1);
    }
    printf("The tree is created::\n");
    inOrder(head);
    return 0;
}