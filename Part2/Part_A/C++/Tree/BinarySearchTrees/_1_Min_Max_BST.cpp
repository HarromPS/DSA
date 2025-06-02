#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

/*

Given the root of a Binary Search Tree.
The task is to find the minimum/maximum valued element in this given BST. 
 */
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(){}
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
}typedef Node;

class Solution{
public: 
    int minValue(Node* root) {
        int curr = INT_MAX;
        Node* node=root;
        while(node!=nullptr){
            curr=node->data;
            node=node->left;
        }
        return curr;
    }

    int maxValue(Node* root){
        int curr=INT_MIN;
        Node* node=root;
        while(node!=nullptr){
            curr=node->data;
            node=node->right;
        }
        return curr;
    }
};

/*
        1
       /  \
      2    2
     / \  / \
    3   4 4  3
       /  \ 
       5   5

*/
void solve(){
    Node root(10);
    Node two(5);
    Node three(20);
    Node four(2);
    Node five(5);

    Node six(6);
    Node seven(7);
    Node eight(8);
    Node nine(4);

    root.left = &two;
    root.right = &three;

    two.left=&four;
    // two.right=&five;

    // five.left=&six;
    // five.right=&seven;

    Solution s;
    int res=s.minValue(&root);
    cout<<res<<endl;
    res=s.maxValue(&root);
    cout<<res<<endl;
    
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    solve();
    return 0;
}
