#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
You are given a Binary Tree of 'n' nodes.
The Top view of the binary tree is the set of nodes visible when we see the tree from the top.
Find the top view of the given binary tree, from left to right.

        1
       /  \
      2    5
     / \  / \
    3   4 6  7

ans=>[3 2 1 5 7]

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
    // WLL NOT WORK AS MARKING IS ALREADY DONE IN DEPTHS, SO WRONG ANS WE GET 
    // void preorder(Node* root,int vertical, map<int,int>& mp){
    //     if(root==nullptr) return;

    //     // mark if node vertical is not assigned to any other node 
    //     if(mp.find(vertical)==mp.end()){
    //         mp[vertical] = root->data;
    //     }
    //     preorder(root->left,vertical-1,mp);
    //     preorder(root->right,vertical+1,mp);
    // }
    // vector<int> getTopView(Node *root){
    //     // map all the nodes seen first in left and right travsersal 
    //     map<int,int> mp;    // vertical, node
    //     int vertical = 0;   // initial vertical for root is 0
    //     vector<int> ans;
    //     if(root==nullptr) return ans;

    //     preorder(root,vertical,mp);
    //     // take all and put in ans 
    //     for(auto it:mp) ans.push_back(it.second);
    //     return ans;
    // }

    vector<int> getTopViewIterative(Node *root){
        // map all the nodes seen first in left and right travsersal 
        map<int,int> mp;    // vertical, node
        int vertical = 0;   // initial vertical for root is 0
        vector<int> ans;
        if(root==nullptr) return ans;

        queue<pair<Node*,int>> q;   // node, vertical 
        q.push({root,vertical});

        while(!q.empty()){
            Node* n = q.front().first;
            int v = q.front().second;
            q.pop();

            if(mp.find(v)==mp.end()){
                mp[v]=n->data;
            }
            if(n->left!=nullptr) q.push({n->left,v-1});
            if(n->right!=nullptr) q.push({n->right,v+1});
        }

        // take all and put in ans 
        for(auto it:mp) ans.push_back(it.second);
        return ans;
    }
};

/*
        1
       /  \
      2    3
        \
        4

*/
void solve(){
    Node root(1);
    Node two(2);
    Node three(3);
    Node four(4);
    Node five(5);
    Node six(6);
    Node seven(7);

    root.left = &two;
    root.right = &five;

    two.left=&three;
    two.right=&four;

    five.left=&six;
    five.right=&seven;
    Solution s;

    // vector<int> ans = s.getTopView(&root);
    // for(auto iter:ans){
    //     cout<<iter<<" ";
    // }
    // cout<<endl;
    vector<int> ans = s.getTopViewIterative(&root);
    for(auto iter:ans){
        cout<<iter<<" ";
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

    // ll test;
    // cin>>test;
    // while(test--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}


