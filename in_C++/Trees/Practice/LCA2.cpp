#include <iostream>
#include <cstdio>
#include <vector>
#include <stdbool.h>
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

bool lowestAncestor(struct node *root, vector<int> &v, int n)
{
    if (root == NULL)
    {
        return false;
    }
    v.push_back(root->data);
    if (root->data == n)
    {
        return true;
    }
    bool left = lowestAncestor(root->left, v, n);
    bool right = lowestAncestor(root->right, v, n);

    if (left == true)
    {
        return true;
    }
    if (right == true)
    {
        return true;
    }

    v.pop_back();
    return false;
}
int LCA(struct node *root, int n1, int n2)
{
    vector<int> a;
    vector<int> b;

    bool a1 = lowestAncestor(root, a, n1);
    bool b1 = lowestAncestor(root, b, n2);
    if (a1 == false && b1 == false)
    {
        return -1;
    }

    int i;
    for (i = 0; i < a.size() && b.size(); i++)
    {
        if (a[i] != b[i])
        {
            break;
        }
    }

    return a[i - 1];
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

    int result = LCA(p, 1, 10);
    if (result != -1)
    {
        cout << "Found: " << result << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
    // vector<int> v;
    // v.push_back(10);
    // v.push_back(20);
    // v.push_back(30);
    // v.push_back(40);

    // v.pop_back();
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
    // // cout<<v[0];

    return 0;
}
