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

struct node* LCA(struct node* root,int a,int b){
    if(root==NULL){
        return root;
    }
    if(root->data==a || root->data==b){
        return root;
    }
    struct node* left=LCA(root->left,a,b);
    struct node* right=LCA(root->right,a,b);

    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }

    return root;

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

    // for node 10 & 1 the lowest common ancestor is => 3  found both 1 & 10 so left&right!=NULL return node(3)
    // for node 10 & 3 the lowest common ancestor is => 3  found 3 as left & right as NULL return node(3)
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

    struct node* lca = LCA(p,1,10);
    printf("%d ",lca->data);

    return 0;
}