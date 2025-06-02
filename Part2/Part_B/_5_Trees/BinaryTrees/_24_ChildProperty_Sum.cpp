

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
You are given the root of a binary tree that consists of exactly 3 nodes: the root, its left child, and its right child.

Return true if the value of the root is equal to the sum of the values of its two children, or false otherwise.

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
    void printTree(Node* node){
        if(node==nullptr) return;
        cout<<node->data<<" ";
        printTree(node->left);
        printTree(node->right);
    }

    bool checkTree(Node* root) {
        return (root->left->data + root->right->data) == root->data;
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
    Node root(50);
    Node two(30);
    Node three(20);
    Node four(3);
    Node five(5);
    Node six(1);
    Node seven(30);
    Node eight(8);
    Node nine(9);

    root.left = &two;
    root.right = &three;

    // two.left=&four;
    // two.right=&five;

    // three.left=&six;
    // three.right=&seven;

    Solution s;
    bool res=s.checkTree(&root);
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

    // ll test;
    // cin>>test;
    // while(test--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}


