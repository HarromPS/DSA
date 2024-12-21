#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

// Trees - Can be made with the use of linked list
// In tree we have a vertex, left branch/child & right branch/child

// Binary Tree is represented in two ways - Arrays & Linked
// There are limitations of Arrays of size
// In linked representations we use doubly Linked list
// int data, node* left, node* right -> linked representation

// In C++
typedef class Node
{
public:
    int data;
    class Node *left, *right;
} Node;

// newNode for the childs of parent nodes
Node *newNode(int val)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// function for the creation of a Binary Tree
Node *createTree(Node *root)
{
    if (root == NULL)
    {
        cout << "Enter the data of your node: ";
        int data;
        cin >> data;
        root = newNode(data);
    }
    cout << "Do you have left child\nyes '1' no '0'==>";
    int x;
    cin >> x;
    cout << endl;
    if (x == 1)
    {
        root->left = createTree(root->left);
    }
    cout << "Do you have right child\nyes '1' no '0'==>";
    cin >> x;
    cout << endl;
    if (x == 1)
    {
        root->right = createTree(root->right);
    }
    return root;
}

// traversing the tree in preorder
void perOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data<<" ";
        perOrder(root->left);
        perOrder(root->right);
    }
}
// traversing the tree in postOrder
void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data<<" ";
    }
}
// traversing the tree in inorder
void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data<<" ";
        inOrder(root->right);
    }
}
int main()
{
    Node *root = NULL;
    cout << "Enter the data of root node\n";
    root = createTree(root);
    cout<<"perOrder Traversal"<<endl;
    perOrder(root);
    cout<<"\npostOrder Traversal"<<endl;
    postOrder(root);
    cout<<"\ninOrder Traversal"<<endl;
    inOrder(root);

    return 0;
}