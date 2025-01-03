


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
    
    vector<int> arr;
    int n=0;    

    void countNodes(Node* node,int * count){
        if(node==nullptr){
            return;
        }

        *count+=1;
        countNodes(node->left,count);
        countNodes(node->right,count);
    }

    void preorder(Node* node,int ind){
        if(node==nullptr) {
            return;
        }
        arr[ind]=node->data;
        preorder(node->left, ind*2+1);
        preorder(node->right, ind*2+2);
    }

    // Encodes a tree to a single string.
    string serialize(Node* root) {
       // using segment tree concepts 

       int cnt=0;
       countNodes(root, &cnt);
       arr.resize(4*cnt,-1001);

       preorder(root,0);
       n = arr.size();
       return "";
    }

    Node* buildTree(int ind){
        if(ind >= n){
            return nullptr;
        }

        if(arr[ind]==-1001){  // points to a null value 
            return nullptr; 
        }

        Node* node = new Node(arr[ind]);
        node->left = buildTree(2*ind+1);
        node->right = buildTree(2*ind+2);

        return node;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        return buildTree(0);
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

    Node six(0);
    Node seven(8);
    Node eight(7);
    Node nine(4);

    root.left = &two;
    root.right = &three;

    three.left=&four;
    three.right=&five;

    Solution s;

    string serialized=s.serialize(&root);
    // cout<<serialized<<endl;
    // s.printTree(&root);

    Node* tree = s.deserialize(serialized);
    s.printTree(tree);

    string ss="10";
    for(int i=0;i<ss.size();i++){
        cout<<ss[i]<<" ";
    }
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
    solve();
    return 0;
}
