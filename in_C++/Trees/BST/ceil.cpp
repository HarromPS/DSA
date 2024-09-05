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

// ceil -> value smaller than key but greater in the whole tree
int ceil(struct node* root,int key){
    int ans=INT_MIN;
    while(root!=NULL){
        if(root->data == key){
            return root->data;
        }

        if(root->data > key){
            ans=root->data;     // once find a big value go for the smaller value in left
            root=root->left;
        }
        else {
            root=root->right;    // go until find a big value
        }
    }
    return ans;
}
int main()
{

    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(8);
    struct node *p1 = createNode(6);
    struct node *p2 = createNode(21);
    struct node *p3 = createNode(15);
    struct node *p4 = createNode(26);
    struct node *p5 = createNode(13);
    // Finally The tree looks like this:
    //      8
    //     / \
    //    6   21
    //       /  \
    //      15   26
    //     / \
    //     13

    // Linking the root node with left and right children
    p->left = p1;   p->right = p2;
    p1->left = NULL;   p1->right =NULL;

    p2->left = p3;
    p2->right = p4;

    p3->left = p5;
    p3->right = NULL;

    p4->left = NULL;
    p4->right = NULL;

    p5->left = NULL;
    p5->right = NULL;

    int result=ceil(p,25);
    if(result!=INT_MIN){
        cout<<result<<endl;
    }
    else{
        cout<<result<<endl;
    }


    return 0;
}