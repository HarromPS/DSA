#include<iostream>
#include<cstdio>
#include <unordered_map>
#include<queue>
#include <utility>
using namespace std;

struct node
{
    int data;
    int hd;
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

void horizontaiDist(struct node *root,int mag)
{
    if (root != NULL)
    {
        // printf("%d ", root->data);
        root->hd = mag;
        horizontaiDist(root->left,mag-1);
        horizontaiDist(root->right,mag+1);
    }
}
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        // printf("%d ", root->hd);
        printf("%d ", root->data);
        inOrder(root->left);
        inOrder(root->right);
    }
}

int Height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return (Height(root->left) > Height(root->right) ? Height(root->left) : Height(root->right)) + 1;
}

void g(unordered_map<int ,int>& mp){
    for(int i=0;i<3;i++){
        mp[i-1]=i+1;
    }
}

typedef struct Pair{
    int hd;
    int node;
};

Pair* setPair(struct node* node){
    Pair* p=(Pair* )malloc(sizeof(Pair)*1);
    p->hd = node->hd;
    p->node = node->data;
    return p;
}
void topView(struct node* root){
    vector<int> v;
    queue<Pair> q;

    Pair* p = setPair(root);
    // q.push(p);

    q.pop();
    // cout<<i;
    // while(!q.empty())
    // {
    //      = q.pop();
    // }


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

    // Top view -> 1 3 8 10 14
    // Right view -> 8 10 14 13
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
    horizontaiDist(p,0);
    // inOrder(p);

    int size = Height(p);
    unordered_map<int, int> umap;
    // vector<int> v=topView();
    topView(p);
    return 0;
}
