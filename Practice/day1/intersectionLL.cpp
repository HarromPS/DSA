#include <iostream>
#include <cstdio>
using namespace std;

typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

class Solution
{
public:
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB)
    {
        ListNode *i = headA;
        ListNode *j = headB;

        while (i != NULL)
        {
            j = headB;
            while (j != NULL)
            {
                if (i == j)
                {
                    return i;
                }
                j = j->next;
            }
            i = i->next;
        }
        return NULL;
    }
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB)
    {
        // if nodes are null return null
        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }
        // pointer to the heads of two linked lists
        ListNode *i = headA;
        ListNode *j = headB;

        // iterate until find the common address node else return null
        // first iteration ->
        while (i != j)
        {
            // if i is null i.e end -> point to head of other list B
            if (i == NULL)
            {
                i = headB;
            }
            else
            {
                i = i->next;
            }

            // if j is null i.e end -> point to head of other list A
            if (j == NULL)
            {
                j = headA;
            }
            else
            {
                j = j->next;
            }
        }
        return i; // if intersect found ->return interesected address else
                  // else reach end & return NULL
    }
};
int main()
{
    /*
    Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'*/
    return 0;
}