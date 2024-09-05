#include <iostream>
#include <cstdio>
using namespace std;

typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
} ListNode;

class Solution
{
public:
    ListNode *createReverse(ListNode *head, int *length)
    {
        ListNode *newNode = NULL;
        ListNode *j = head->next;
        while (j != NULL)
        {
            head->next = newNode;
            newNode = head;
            head = j;
            j = j->next;
            *length += 1;
        }
        head->next = newNode;
        return newNode;
    }
    void length(ListNode *head, int *length)
    {
        while (head != NULL)
        {
            *length += 1;
            head = head->next;
        }
    }
    void reorderList(ListNode *head)
    {
        // we can make the a reverse list & then make Reordered list
        int len = 0;
        length(head, &len);
        ListNode *i = head;
        int arr[len];
        int k = 0, x = -1, y = len;
        while (k < len)
        {
            arr[k] = i->val;
            i = i->next;
            k++;
        }

        k = 0;
        i = head;
        while (k < len && i != NULL)
        {
            if (k % 2 == 0)
            {
                x++;
                i->val = arr[x];
            }
            else
            {
                y--;
                i->val = arr[y];
            }
            k++;
            i = i->next;
        }
    }

    void traversal(ListNode *head)
    {
        while (head != NULL)
        {
            cout << head->val << " ";
            head = head->next;
        }
    }
};
int main()
{
    ListNode *head = (ListNode *)malloc(sizeof(ListNode) * 1);
    head->val = 1;
    ListNode *tw = (ListNode *)malloc(sizeof(ListNode) * 1);
    tw->val = 2;
    ListNode *th = (ListNode *)malloc(sizeof(ListNode) * 1);
    th->val = 3;
    ListNode *f = (ListNode *)malloc(sizeof(ListNode) * 1);
    f->val = 4;
    head->next = tw;
    tw->next = th;
    th->next = f;
    f->next = NULL;

    Solution s;
    s.reorderList(head);
    s.traversal(head);

    return 0;
}
