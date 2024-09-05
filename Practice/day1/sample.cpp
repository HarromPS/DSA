#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *list1, ListNode *list2)
    {
        // if (list1->next == NULL || list2->next)
        // {
        //     list1->val += list2->val;
        //     return list1;
        // }

        int carry=0;
        ListNode *i1 = NULL, *j1 = list1->next, *i2 = NULL, *j2 = list2->next;
        while (j1 != NULL && j2 != NULL)
        {
            list1->next = i1;
            i1 = list1;
            list1 = j1;
            j1 = j1->next;

            list2->next = i2;
            i2 = list2;
            if(i1->val+i2->val > 10){
                carry=1;
            }
            i2->val+=(i1->val);
            list2 = j2;
            j2 = j2->next;
        }
        list1->next = i1;
        i1=list1;
        list1 = j1;

        list2->next = i2;
        i2=list2;
        list2 = j2;
        return i1;
    }
    void printList(ListNode *l)
    {
        while (l != NULL)
        {
            cout << l->val << " ";
            l = l->next;
        }
        cout << endl;
    }
};

int main()
{
    Solution s;
    ListNode *list1 = (ListNode *)malloc(sizeof(ListNode) * 1);
    list1->val = 2;
    ListNode *list11 = (ListNode *)malloc(sizeof(ListNode) * 1);
    list11->val = 4;
    ListNode *list12 = (ListNode *)malloc(sizeof(ListNode) * 1);
    list12->val = 3;

    list1->next = list11;
    list11->next = list12;
    list12->next = NULL;

    ListNode *list2 = (ListNode *)malloc(sizeof(ListNode) * 1);
    list2->val = 5;
    ListNode *list21 = (ListNode *)malloc(sizeof(ListNode) * 1);
    list21->val = 6;
    ListNode *list22 = (ListNode *)malloc(sizeof(ListNode) * 1);
    list22->val = 4;

    list2->next = list21;
    list21->next = list22;
    list22->next = NULL;
    s.printList(list1);
    s.printList(list2);
    list1 = s.addTwoNumbers(list1, list2);
    s.printList(list1);
    list2 = s.addTwoNumbers(list1, list2);
    s.printList(list2);
    // int t;
    // cin >> t;
    // while (t--)
    // {
    // }
    return 0;
}