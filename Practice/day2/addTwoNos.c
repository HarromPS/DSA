#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    // first reverse the two lists
    if (l1 == NULL && l2 == NULL)
    {
        return NULL;
    }
    else if (l1->next == NULL && l2->next == NULL)
    {
        if ((l1->val + l2->val) > 9)
        {
            struct ListNode *n = (struct ListNode *)malloc(sizeof(struct ListNode) * 1);
            n->val = 1;
            n->next = NULL;
            l1->val = (l1->val + l2->val) % 10;
            l1->next = n;
            return l1;
        }
        else
        {
            l1->val += l2->val;
            return l1;
        }
    }

    struct ListNode *i = l1;
    struct ListNode *j = l2;
    int len1 = 1, len2 = 1;

    while (i != NULL)
    {
        i = i->next;
        len1++;
    }
    while (j != NULL)
    {
        j = j->next;
        len2++;
    }
    i = l1;
    j = l2;
    int carry = 0;
    while (l1 != NULL && l2 != NULL)
    {
        int sum = 0;
        sum = l1->val + l2->val + carry;
        carry = sum / 10;
        if (len1 >= len2)
        {
            l1->val = sum % 10;
        }
        else
        {
            l2->val = sum % 10;
        }
        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1 != NULL)
    {
        int sum = l1->val + carry;
        carry = sum / 10;
        l1->val = sum % 10;
        if (l1->next == NULL && carry == 1)
        {
            struct ListNode *n = (struct ListNode *)malloc(sizeof(struct ListNode) * 1);
            n->val = carry;
            n->next = NULL;
            l1->next = n;
            break;
        }
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        int sum = l2->val + carry;
        carry = sum / 10;
        l2->val = sum % 10;
        if (l2->next == NULL && carry == 1)
        {
            struct ListNode *n = (struct ListNode *)malloc(sizeof(struct ListNode) * 1);
            n->val = carry;
            n->next = NULL;
            l2->next = n;
            break;
        }
        l2 = l2->next;
    }

    if (len1 == len2)
    {
        l1 = i;
        while (l1->next != NULL)
        {
            l1 = l1->next;
        }
        if (carry == 1)
        {
            struct ListNode *n = (struct ListNode *)malloc(sizeof(struct ListNode) * 1);
            n->val = 1;
            n->next = NULL;
            l1->next = n;
        }
    }
    return (len1 >= len2 ? i : j);
}
int main()
{
    return 0;
}
