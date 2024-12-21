#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

/*
Binary Search Tree (BST)->
1) All the nodes in left subtree are lesser than root node.
2) All the nodes in right subtree are greater than root node.
3) Left & right subtree are also BST node.
4) There are no duplicate nodes in BST.
4) Inorder tree traversal of BST gives the ascending order sorted array.
*/

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

// Iterative Search in BST
Node* searchNode(Node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    else if(key<root->data){
        return searchNode(root->left,key);
    }
    else{
        return searchNode(root->right,key);
    }
}
int main()
{
    /*
               9
            /     \
           4       11
         /   \   /    \
        2     7   10   12
    
    */
    Node *root = NULL;
    cout << "Enter the data of root node\n";
    root = createTree(root);
    perOrder(root);
    cout<<endl;
    cout<<"Enter the key to search in Binary Search Tree: ";
    int key;
    cin>>key;
    if(searchNode(root,key)==NULL){
        cout<<"Key not found"<<endl;
    }
    else{
        Node* p=searchNode(root,key);
        cout<<"Key Found: "<<p->data<<endl;
    }

    return 0;
}