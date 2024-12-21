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

// function to do node insertion BST
void insertNode(Node* root,int key){
    Node* prev=NULL;
    if(root==NULL){
        cout<<"Cannot Insert"<<endl;
        return ;
    }
    while(root!=NULL){
        prev=root;
        if(root->data==key){
            cout<<"Cannot Insert Duplicate"<<endl;
            return ;
        }
        else if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=key;
    newNode->left=newNode->right=NULL;
    if(key<prev->data){
        prev->left=newNode;
    }
    else{
        prev->right=newNode;
    }
}
// traversing the tree in preorder
void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
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
    cout<<"Preorder Transversal"<<endl;
    preOrder(root);
    cout<<endl;
    insertNode(root,9);
    cout<<"Preorder Transversal"<<endl;
    preOrder(root);
    cout<<endl;
    return 0;
}