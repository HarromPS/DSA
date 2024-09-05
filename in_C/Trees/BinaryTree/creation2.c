#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* create(int data)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void transversal(Node* r)
{
    if(r==NULL)
    {
        return ;
    }
    else
    {
        printf("%d->",r->data);
        transversal(r->left);
        transversal(r->right);
    }
}
int main()
{
    struct Node* root=create(1);
    struct Node* rLchild=create(2);
    struct Node* rRchild=create(3);

    root->left=rLchild;
    root->right=rRchild;
    transversal(root);
    return 0;
}