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


int isBST(struct node* root){
    static struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }

        if(prev!=NULL && root->data <= prev->data)
        {
            return 0;
        }

        prev=root;

        return isBST(root->right);
    }
    return 1;
}
int main()
{

    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4
    //

    // Linking the root node with left and right children
    p->left = p1;   p->right = p2;
    p1->left = p3;   p1->right = p4;

    p2->left = NULL;
    p2->right = NULL;

    p3->left = NULL;
    p3->right = NULL;

    p4->left = NULL;
    p4->right = NULL;

    int r=isBST(p);
    if(r==1){
        cout<<"BST"<<endl;
    }
    else{
        cout<<"NO BST"<<endl;

    }

    return 0;
}