#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

struct Node
{
    struct Node *left;
    int data;
    struct Node *right;

};

struct Node* create(int val){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left=NULL;
    node->right=NULL;
    return node;
}

// traverse the tree
void inOrder(struct Node *n)
{
    if (n == NULL)
    {
        return;
    }
    else
    {
        inOrder(n->left);
        printf("%d ", n->data);
        inOrder(n->right);
    }
}

struct Node* solve(vector<struct Node*>& v,int low,int high){
    if(low>high){
        return NULL;
    }

    // using binary search approach to solve the problem
    struct Node* temp = v[(low+high)/2];
    temp->left = solve(v,low,((low+high)/2)-1);
    temp->right = solve(v,((low+high)/2)+1,high);

    return temp;
}
int main()
{
    // get the inOrder sequence of the BST
    struct Node* one = create(1);
    struct Node* two = create(2);
    struct Node* three = create(3);
    struct Node* four= create(4);
    struct Node* five= create(5);

    vector<struct Node*> v;
    for (int i=0;i<5;i++){
        v.push_back(create(i+1));
    }
    // for(int i=0;i<v.size();i++){
    //     // cout<<v[i]->data<<" ";
    //     printf("%d ",v[i]->data);
    // }
    struct Node* head=solve(v,0,v.size()-1);
    inOrder(head);
    return 0;
}