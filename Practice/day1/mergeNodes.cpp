#include <iostream>
#include <cstdio>
using namespace std;
typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;
class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *i = head->next;
        int sum=0;
        while (i != NULL)
        {
            sum=0;
            ListNode *j = i;
            while(j->val!=0)
            {
                sum+=j->val;
                j=j->next;
            }
            i->val=sum;
            i->next=j->next;
            i=i->next;
        }
        return head->next;
    }
    void printList(ListNode *head)
    {
        while (head != NULL)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

int main()
{
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->val = 0;
    ListNode *two = (ListNode *)malloc(sizeof(ListNode));
    two->val = 3;
    ListNode *three = (ListNode *)malloc(sizeof(ListNode));
    three->val = 1;
    ListNode *four = (ListNode *)malloc(sizeof(ListNode));
    four->val = 0;
    ListNode *five = (ListNode *)malloc(sizeof(ListNode));
    five->val = 4;
    ListNode *six = (ListNode *)malloc(sizeof(ListNode));
    six->val = 5;
    ListNode *seven = (ListNode *)malloc(sizeof(ListNode));
    seven->val = 2;
    ListNode *eight = (ListNode *)malloc(sizeof(ListNode));
    eight->val = 0;

    head->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = seven;
    seven->next = eight;
    eight->next = NULL;

    Solution s;
    s.printList(head);
    head = s.mergeNodes(head);
    s.printList(head);
    return 0;
}