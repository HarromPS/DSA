
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given a binary tree of nodes 'N', you need to modify the value of its nodes, such that the tree holds the Children sum property. 
You can only increment data values in any node (You cannot change the structure of the tree and cannot decrement the value of any node). 

Input:
Binary tree
       50
      /  \
     7     2
    / \   / \
    3  5 1  30

    Below tree satisfy childrem sum property 

       50
      /  \
     19   31
    / \   / \
   14  5 1  30
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

    void incrementSubtree(Node* node, int diff){
        // either left or right subtree increment
        if(node->left!=nullptr){
            node->left->data+=diff;
            incrementSubtree(node->left, diff);
        }else if(node->right!=nullptr){
            node->right+=diff;
            incrementSubtree(node->right, diff);
        }
    }

    void changeTree(Node* root) {
        // base condition 
        if(root==nullptr) return;

        changeTree(root->left);
        changeTree(root->right);

        // check current node
        int leftData = root->left==nullptr?0:root->left->data;
        int rightData = root->right==nullptr?0:root->right->data;
        int diff = leftData+rightData - root->data;

        // if node is smaller make it equivalent to sum of its child 
        if(diff > 0){
            root->data+=diff;
        }

        // if node is greater then, increment its left or right subtree and its subtree also
        // to make it equivalent to root node
        if(diff < 0){
            incrementSubtree(root, abs(diff));
        }
    }    

    void changeTreeOptimized(Node* root){
        if(root==nullptr) return;

        int leftVal = (root->left!=nullptr)?root->left->data:0;
        int rightVal = (root->right!=nullptr)?root->right->data:0;
        int diff = (leftVal+rightVal)-root->data;
        
        // if root is greater 
        if(diff < 0){
            // increment l & r by root value, so there should not be shortage when returning 
            if(root->left!=nullptr){
                root->left->data = root->data;
            }
            if(root->right!=nullptr){
                root->right->data = root->data;
            }
        }

        // go left and right subtree
        changeTreeOptimized(root->left);
        changeTreeOptimized(root->right);

        // if not leaf node, add left and right val to root node 
        if(!(leftVal==0 && rightVal==0)){
            // add updated left and right values 
            leftVal = (root->left!=nullptr)?root->left->data:0;
            rightVal = (root->right!=nullptr)?root->right->data:0; 
            root->data = leftVal+rightVal;
        }
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


