#include <iostream>
#include <cstdio>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(struct Node *node, int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node) * 1);
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    node = newNode;
    return node;
}

// function to create a Tree
struct Node *createTree(struct Node *root)
{
    if (root == NULL)
    {
        cout << "Data: ";
        int val;
        cin >> val;
        root = newNode(root, val);
    }
    cout << "Do you have LEFT child\n'1' for Yes & '0' for No";
    int x;
    cin >> x;
    if (x == 1)
    {
        root->left = createTree(root->left);
    }
    cout << "Do you have RIGHT child\n'1' for Yes & '0' for No";
    cin >> x;
    if (x == 1)
    {
        root->right = createTree(root->right);
    }
    return root;
}

//  Tree Traversal
void preOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void postOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// finding inorder predecessor
struct Node *inorderPredecessor(struct Node *node)
{
    // Inorder perdecessor is the just left node
    node = node->left;
    while (node->right != NULL)
    {
        // rightmost node in the leftSubtree is the Inorder Predecessor
        node = node->right;
    }
    return node;
}

// function to remove the node recursively
struct Node *deleteNode(struct Node *root, int val)
{
    struct Node *iPre;
    if (root == NULL)
    {
        return root;
    }
    if (root->left == NULL && root->right == NULL)
    {
        // leaf node deletion
        free(root);
        return NULL;
    }
    if (root->data > val)
    {
        root->left = deleteNode(root->left, val);
    }
    else if (root->data < val)
    {
        root->right = deleteNode(root->right, val);
    }
    // when the val is found i.e root->left->data !< val &&
    // root->right->data !> val
    else
    {
        // finding the iPre
        iPre = inorderPredecessor(root);

        // changing the val of the node to inOrder predecessor's val
        root->data = iPre->data;

        // deleting the  inOrder predecessor's now
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}
int main()
{
    struct Node *root = NULL;
    // root = createTree(root);

    struct Node *one = (struct Node *)malloc(sizeof(struct Node) * 1);
    one->data = 8;
    struct Node *two = (struct Node *)malloc(sizeof(struct Node) * 1);
    two->data = 3;
    struct Node *three = (struct Node *)malloc(sizeof(struct Node) * 1);
    three->data = 10;
    struct Node *four = (struct Node *)malloc(sizeof(struct Node) * 1);
    four->data = 1;
    struct Node *five = (struct Node *)malloc(sizeof(struct Node) * 1);
    five->data = 6;

    one->left = two;
    one->right = three;

    two->left = four;
    two->right = five;

    three->left = NULL;
    three->right = NULL;

    four->left = NULL;
    four->right = NULL;

    five->left = NULL;
    five->right = NULL;

    // inOrder(root);
    // cout << "PreOrder Travaversal:" << endl;
    // preOrder(one);
    cout << "\nInOrder Travaversal:" << endl;
    inOrder(one);
    // cout << "\nPostOrder Travaversal:" << endl;
    // postOrder(one);

    one = deleteNode(one, two->data);
    cout << "\nAfter deletion InOrder Travaversal:" << endl;
    inOrder(one);

    return 0;
}