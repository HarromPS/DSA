#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

// AVL Trees -> height balancing trees

class Node
{
    int data;
    class Node *left;
    class Node *right;
    int height;

public:
    int getHeight(class Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return node->height;
    }

    int getBalanceFactor(class Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    int max(int left, int right)
    {
        return (left > right) ? left : right;
    }

    class Node *rightRotate(class Node *y)
    {
        class Node *x = y->left;
        class Node *t2 = x->right;

        x->right = y;
        y->left = t2;

        y->height = 1 + max(getHeight(y->right), getHeight(y->left));
        x->height = 1 + max(getHeight(x->right), getHeight(x->left));

        return x;
    }

    class Node *leftRotate(class Node *x)
    {
        class Node *y = x->right;
        class Node *t2 = y->left;

        y->left = x;
        x->right = t2;

        x->height = 1 + max(getHeight(x->right), getHeight(x->left));
        y->height = 1 + max(getHeight(y->right), getHeight(y->left));

        return y;
    }

    class Node *create(int val)
    {
        class Node *node = (class Node *)malloc(sizeof(class Node) * 1);
        node->data = val;
        node->right = node->left = NULL;
        node->height = 1;
        return node;
    }

    class Node *insert(class Node *node, int val)
    {
        if (node == NULL)
        {
            return create(val);
        }
        if (val < node->data)
        {
            node->left = insert(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = insert(node->right, val);
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int bf = getBalanceFactor(node);

        // left left rotation
        if (bf > 1 && val < node->left->data)
        {
            return rightRotate(node);
        }

        // left right rotation
        if (bf > 1 && val > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node->right);
        }

        // right right rotation
        if (bf < -1 && val > node->right->data)
        {
            return leftRotate(node);
        }

        // right left rotation
        if (bf < -1 && val < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inOrder(class Node *root)
    {
        if (root != NULL)
        {
            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        }
    }
};
int main()
{
    class Node *head = NULL;
    head = head->insert(head, 1);
    head = head->insert(head, 2);
    head = head->insert(head, 4);
    head = head->insert(head, 5);
    head = head->insert(head, 6);
    head = head->insert(head, 3);
    head->inOrder(head);

    return 0;
}