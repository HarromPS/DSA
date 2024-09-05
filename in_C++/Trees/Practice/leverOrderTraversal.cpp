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

// height of a tree
int Height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(Height(root->left), Height(root->right)) + 1;
}

// maxNo of edges in tree
int maxEdge(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(Height(root->left), Height(root->right));
}

// max size node in the tree
int maxNode(struct node *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data, max(maxNode(root->left), maxNode(root->right)));
}

// level order traversal
void levelOrderTraversal(struct node *root, int levelNo)
{
    if (root == NULL)
    {
        return;
    }
    else if (levelNo == 1)
    {
        printf("%d ", root->data);
    }
    else
    {
        levelOrderTraversal(root->left, levelNo-1);
        levelOrderTraversal(root->right, levelNo-1);
    }
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

    cout<<"LevelOrder Traversal is: "<<endl;
    for (int i = 1; i <= max; i++)
    {
        levelOrderTraversal(p, i);
    }

    cout << endl;
    max = maxEdge(p);
    printf("%d\n", max);

    max = maxNode(p);
    printf("%d\n", max);

    return 0;
}