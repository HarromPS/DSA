


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
    
    void getString(Node* root, string& s){
        if(root==nullptr){
            s+="#,";
            return;
        }

        s+=to_string(root->data)+",";
        getString(root->left,s);
        getString(root->right,s);
    }

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        // collect and return a string 
        string s="";
        getString(root,s);
       return s;
    }

    Node* build(vector<int>& arr){
        if(i >= arr.size()){
            return nullptr;
        }

        if(arr[i]==-1001){
            return nullptr;
        }

        Node* node = new Node(arr[i]);
        i++;
        node->left = build(arr);
        i++;
        node->right = build(arr);
        return node;
    }

    int i=0;
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        // convert the string to integers
        vector<int> arr;
        string nums="";
        int n=data.size();
        for(int i=0;i<n;i++){
            if(data[i]=='#'){
                if(nums.size()!=0){
                    arr.push_back(stoi(nums));
                    nums="";
                }
                arr.push_back(-1001);   // null
                continue;
            }
            else if(data[i]==','){
                if(nums.size()!=0){
                    arr.push_back(stoi(nums));
                    nums="";
                }
                continue;
            }
            nums+=data[i];
        }
        Node* node = build(arr);
        printTree(node);
        return nullptr;
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

    Node* tree = s.deserialize(serialized);
    s.printTree(tree);
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
