#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Trees - Creating a single node - vertex
typedef struct Tree
{
    struct Tree *left_node;  // left leave
    int data;                // data in the node
    struct Tree *right_node; // right leave
} Tree;

// Function to transverse Tree
void transversal(Tree *Node)
{
    if (Node == NULL)
    {
        return;
    }
    else
    {
        printf("(%d)->", Node->data);
        transversal(Node->left_node);
        transversal(Node->right_node);
    }
}
int main()
{
    // Statically assigining the values and allocating the memory
    // & printing the data stored in the nodes
    Tree *vertex /*head*/ = (Tree *)malloc(sizeof(Tree));
    vertex->left_node = NULL;
    vertex->data = 10;
    vertex->right_node = NULL;

    printf("\nThe data of the vertex node is==> %d\n", vertex->data);

    // Now adding a left node in the tree by allocating the memory
    vertex->left_node = (Tree *)malloc(sizeof(Tree));
    vertex->left_node->left_node = NULL;
    vertex->left_node->data = 20;
    vertex->left_node->right_node = NULL;
    printf("\nThe data of the vertex's left node is==> %d\n", vertex->left_node->data);

    // Now adding a right node to the vertex by allocating the memory
    vertex->right_node = (Tree *)malloc(sizeof(Tree));
    vertex->right_node->left_node = NULL;
    vertex->right_node->data = 30;
    vertex->right_node->right_node = NULL;
    printf("\nThe data of the vertex's right node is==> %d\n", vertex->right_node->data);
    transversal(vertex);

    return 0;
}