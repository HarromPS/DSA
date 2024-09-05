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

// Inorder Predecessor
struct node *inOrderPredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
// Deletion of a leaf Node
struct node *deleteLeaf(struct node *root, int val)
{
    struct node *iPre;

    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    // Step 1: Search the leaf node
    if (val < root->data)
    {
        root->left = deleteLeaf(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = deleteLeaf(root->right, val);
    }

    // Now the leaf node is found-> Deletion of the node
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteLeaf(root->left, iPre->data);
    }
    return root;
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
    inOrder(p);
    printf("\n");
    printf("\nThe root node is: %d\n",p->data);
    p = deleteLeaf(p, 8);
    printf("\nThe root node is: %d\n",p->data);
    inOrder(p);

    return 0;
}