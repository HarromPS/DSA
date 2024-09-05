#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

/* Floyds Algorithm
=> finding out a loop in the linked list
=> finding the meeting point in the linked list

Another method to solve this problem is using Hash maps

*/
typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

class Solution
{
public:

    void floydsAlgo(ListNode *head)
    {
        // Fast & slow pointer approach
        ListNode* slow=head;
        ListNode* fast=head;

        // slow -> one node && fast ->2 node

        // put this in a loop
        while(fast!=NULL && fast->next!=NULL){

            // finding the loop while the outer loop runs
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                cout<<"Common Node: "<<slow->val<<" "<<endl;
                break;
            }
        }
        // now if there is any loop present inside the linked list
        // then we got the common node

        // finding the meet point
        slow=head;
        while(slow!=fast && slow!=NULL && fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        cout<<"Entry Node: "<<slow->val<<endl;
    }

    // for a looped list there is no end point
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
    ListNode *head = (ListNode *)malloc(sizeof(ListNode) * 1);
    head->val = 1;
    ListNode *two = (ListNode *)malloc(sizeof(ListNode) * 1);
    two->val = 2;
    ListNode *three = (ListNode *)malloc(sizeof(ListNode) * 1);
    three->val = 3;
    ListNode *four = (ListNode *)malloc(sizeof(ListNode) * 1);
    four->val = 4;
    ListNode *five = (ListNode *)malloc(sizeof(ListNode) * 1);
    five->val = 5;
    ListNode *six = (ListNode *)malloc(sizeof(ListNode) * 1);
    six->val = 6;
    ListNode *seven = (ListNode *)malloc(sizeof(ListNode) * 1);
    seven->val = 7;

    // looped list created
    head->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = seven;
    seven->next = three;

    Solution s;
    s.floydsAlgo(head);
    return 0;
}

