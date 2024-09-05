#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *prev;
    struct Node *next;
    struct Node *child;
} Node;

Node *flatten(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *i = head;
    while (i != NULL && i->child == NULL)
    {
        i = i->next;
    }
    if (i == NULL)
    {
        return head;
    }
    Node *j;
    if (i != NULL && i->child != NULL)
    {
        j = i->next;
    }

    Node *nodeChild = flatten(i->child);
    i->child = NULL;
    i->next = nodeChild;
    nodeChild->prev = i;
    while (i->next != NULL)
    {
        i = i->next;
    }
    i->next = j;
    if (j != NULL)
    {
        j->prev = i;
    }

    return head;
}
int main()
{
    return 0;
}