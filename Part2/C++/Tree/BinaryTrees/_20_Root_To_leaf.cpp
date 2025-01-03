#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given a Binary Tree, you need to 
find all the possible paths from the root node to all the leaf nodes of the binary tree.

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

    void rootLeafTraversal(Node* node, vector<vector<int>>& ans,vector<int>& ds){
        if(node == nullptr) return; 

        // add node value 
        ds.push_back(node->data);

        // if its a leaf node, add it and return
        if(node->left==nullptr && node->right==nullptr){
            ans.push_back(ds);
            
            // 1 pop out of leaf node, to add next root node
            ds.pop_back();
            return;
        }
        rootLeafTraversal(node->left,ans,ds);
        rootLeafTraversal(node->right,ans,ds);
        
        // take out 
        ds.pop_back();
    }

    void Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        rootLeafTraversal(root,ans,temp);
        for(auto it:ans){
            for(auto iter: it) cout<<iter<<" ";
            cout<<endl;
        }
        return;
    }

    bool traversal(Node* node,vector<int>& v,int targetNode){
        if(node==nullptr){
            return false;
        }

        v.push_back(node->data);
        if(node->data==targetNode){
            return true;
        }

        // in mirror, left = right and vice versa
        bool l = traversal(node->left,v,targetNode);
        if(l==true) return true;

        bool r = traversal(node->right,v,targetNode);
        if(r==true) return true;

        // take out previous node, after both way traversal 
        v.pop_back();

        return false;
    }

    void rootToNode(Node* root) {
        vector<int> v;
        traversal(root,v,7);
        for(auto it:v) cout<<it<<" ";
        cout<<endl;
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
    Node seven(7);
    Node eight(8);
    Node nine(9);

    root.left = &two;
    root.right = &three;

    two.left=&four;
    two.right=&five;

    five.left=&six;
    five.right=&seven;

    Solution s;

    s.rootToNode(&root);
    s.Paths(&root);
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


