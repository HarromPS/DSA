


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. 
It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.
Input:

Binary tree
       50
      /  \
     7     2
    / \  
    3  5 
nodes: 5

if left height == right height in a complete bt then 
number of nodes = 2^(lh + rh + 1)
else 1 + number of nodes from left subtree + number of nodes from right subtree

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
    
    int countNodesBruteForce(Node* root) {
        // brute force: any order traversal 
        if(root==nullptr) return 0;

        int left = countNodesBruteForce(root->left);
        int right = countNodesBruteForce(root->right);
        return 1+left+right;
    }

    int getLeftHeight(Node* root){
       int h=0;
       while(root!=nullptr){
            h+=1;
            root=root->left;
       }
       return h;
    }

    int getRightHeight(Node* root){
        int h=0;
        while(root!=nullptr){
            h+=1;
            root=root->right;
        }
        return h;
    }

    int countNodes(Node* root) {
        // if left height == right height in a complete bt then 
        // number of nodes = 2^(lh + rh + 1)
        // else 1 + number of nodes from left subtree + number of nodes from right subtree
        if(root==nullptr) return 0;

        int leftH = getLeftHeight(root->left);
        int rightH = getRightHeight(root->right);

        if(leftH == rightH) {
            return pow(2,1+leftH)-1;
        }

        return 1+countNodes(root->left)+countNodes(root->right);

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
    Node root(3);
    Node two(5);
    Node three(1);
    Node four(6);
    Node five(2);
    Node six(0);
    Node seven(8);
    Node eight(7);
    Node nine(4);

    root.left = &two;
    root.right = &five;

    two.left=&three;
    two.right=&four;

    five.left=&six;
    // five.right=&seven;

    Solution s;

    int ans=s.countNodesBruteForce(&root);
    cout<<ans<<endl;
    ans=s.countNodes(&root);
    cout<<ans<<endl;
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
