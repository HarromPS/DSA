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
}ListNode;

class Solution {
public:
     bool isPalindrome(ListNode *head){
        if (head == NULL){
            return false;
        }
        if(head->next==NULL)return true;
        int length = 0, y = 0;
        ListNode *i = head;
        while (i != NULL){
            i = i->next;
            length++;
        }
        if (length <= 2)
        {
            if(head->val == head->next->val)return true;
            else return false;
        }
        i = head;
        ListNode *j = head->next;
        ListNode *temp = NULL;
        int x = 0;
        y = length / 2;
        // reversing the list
        if (length % 2 == 0){
            while (x != y){
                i->next = temp;
                temp = i;
                i = j;
                j = j->next;
                //i = i->next;
                x++;
            }
            while (y > 0 && i != NULL && temp!=NULL){
                if (i->val != temp->val){
                    return false;
                }
                else{
                    i = i->next;
                    temp = temp->next;
                    y--;
                }
            }
        }
        else{
            while (x != y){
                i->next = temp;
                temp = i;
                i = j;
                j = j->next;
                x++;
            }
            i = i->next;
            while (y > 0 && i != NULL && temp!=NULL){
                if (i->val != temp->val){
                    return false;
                }
                else{
                    i = i->next;
                    temp = temp->next;
                    y--;
                }
            }
        }
        return true;
    }
};
int main()
{
    class Solution s;
    ListNode* head = (ListNode* )malloc(sizeof(ListNode)) ;
    ListNode* second = (ListNode* )malloc(sizeof(ListNode)) ;
    ListNode* third = (ListNode* )malloc(sizeof(ListNode)) ;
    ListNode* fourth = (ListNode* )malloc(sizeof(ListNode)) ;

    head->val = 1;
    head->next = second;
    second->val = 2;
    second->next = third;
    third->val = 2;
    third->next = fourth;
    fourth->val = 1;
    cout<<s.isPalindrome(head)<<endl;

    return 0;
}
