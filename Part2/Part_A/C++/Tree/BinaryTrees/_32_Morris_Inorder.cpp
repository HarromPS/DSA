


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
    // TC:O(N) SC:O(1)
    vector<int> morrisInorder(Node* root){
        // iterative traversal
        vector<int> inorder;
        Node* curr=root;
        while(curr!=nullptr){
            // 1st case 
            if(curr->left==nullptr){
                inorder.push_back(curr->data);
                curr = curr->right;
            }
            else{
                Node* prev=curr->left;  // rightmost guy on left subtree
                while(prev->right!=nullptr && prev->right!=curr){
                    prev=prev->right;
                }
                // if no theread 
                if(prev->right==nullptr){
                    // create one
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    // remove it 
                    prev->right=nullptr;
                    inorder.push_back(curr->data);  // add it to inorder
                    curr=curr->right;
                }
            }
        }
        return inorder;
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
    Node root(1);
    Node two(2);
    Node three(3);
    Node four(4);
    Node five(5);

    Node six(6);
    Node seven(8);
    Node eight(7);
    Node nine(4);

    root.left = &two;
    root.right = &three;

    two.left=&four;
    two.right=&five;

    five.right=&six;

    Solution s;
    vector<int> inorder = s.morrisInorder(&root);
    for(auto it:inorder) cout<<it<<" ";
    cout<<endl;
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
