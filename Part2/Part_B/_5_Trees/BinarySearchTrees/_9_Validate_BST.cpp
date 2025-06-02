#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left
subtree
of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


     10
    /  \
   5    11
  / \ 
 4   7
      \
       8

True
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
    void inorderTraversal(Node* node, vector<int>&v){
        if(node==nullptr) return ;
        inorderTraversal(node->left,v);
        v.push_back(node->data);
        inorderTraversal(node->right,v);
    }

    bool isValidBSTBrute(Node* root){
        vector<int> inorder;
        inorderTraversal(root,inorder);
        // check if all node are sorted
        for(int i=1;i<inorder.size();i++){
            if(inorder[i]<=inorder[i-1]){
                return false;
            }
        }
        return true;
    }

    bool solution(Node* root,int low,int high){
        if(root==nullptr) return true;

        // check node in range 
        if(!(low<root->data && root->data<high)){
            // if not in range
            return false;
        }

        // check for left and right subtree 
        bool left = solution(root->left,low,root->data);
        bool right = solution(root->right,root->data,high);
        if(!left || !right) return false;
        return true;
    }
    bool isValidBSTBetter(Node* root){
        // using ranges to solve this 
        return solution(root,INT_MIN,INT_MAX);
    }
  
};

void solve(){
    Node root(10);
    Node two(5);
    Node three(13);
    Node four(3);
    Node five(6);
    Node six(11);
    Node seven(14);
    Node eight(2);
    Node nine(4);
    Node ten(9);

    root.left = &two;
    root.right = &three;

    two.left=&four;
    two.right=&five;

    three.left=&six;
    three.right=&seven;

    four.left=&eight;
    four.right=&nine;

    five.right=&ten;

    Solution s;
    bool res =s.isValidBSTBrute(&root);
    cout<<res<<endl;
    res =s.isValidBSTBetter(&root);
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
