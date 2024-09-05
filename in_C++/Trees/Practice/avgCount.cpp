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

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
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

int isBST(struct node *root)
{
    static struct node *prev = NULL;
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
struct node *search(struct node *root, int ele)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == ele)
    {
        return root;
    }
    else if (root->data < ele)
    {
        return search(root->right, ele);
    }
    else
    {
        return search(root->left, ele);
    }
}

int Height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(Height(root->left), Height(root->right)) + 1;
}

int maxEdge(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(Height(root->left), Height(root->right));
}

int maxNode(struct node *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data, max(maxNode(root->left), maxNode(root->right)));
}

// returns the height of the tree
int Nodes(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return (Nodes(root->left) + Nodes(root->right)) + 1;
}

// returns the count
int Count(struct node *root, int *count)
{
    if (root == NULL)
    {
        return 0;
    }
    int h = Nodes(root);
    int val = (Count(root->left, count) + Count(root->right, count) + root->data);
    int average = val / h;
    if (average == root->data)
    {
        *count += 1;
    }
    return val;
}
int averageOfSubtree(struct node *root)
{
    int count = 0;
    Count(root, &count);
    return count;
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

    int max = Height(p);
    printf("%d\n", max);

    max = maxEdge(p);
    printf("%d\n", max);

    max = maxNode(p);
    printf("%d\n", max);

    max = averageOfSubtree(p);
    cout << max << endl;
    return 0;
}
///////////////////////////////////////

