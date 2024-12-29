


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.
Input:
target node = 50
k = 2 (dist)
Binary tree
       50
      /  \
     7     2
    / \   / \
    3  5 1  30

output: [3, 5, 1, 30]

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
    Node two(7);
    Node three(2);
    Node four(3);
    Node five(5);
    Node six(1);
    Node seven(30);
    Node eight(8);
    Node nine(9);

    root.left = &two;
    root.right = &three;

    two.left=&four;
    two.right=&five;

    three.left=&six;
    three.right=&seven;

    Solution s;

    s.printTree(&root);
    cout<<endl;
    // s.changeTree(&root);
    s.changeTreeOptimized(&root);
    s.printTree(&root);
    cout<<endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
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


