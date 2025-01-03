#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
 Problem statement

You are given a binary tree having 'n' nodes.
The boundary nodes of a binary tree include the nodes from the left and right boundaries and 
the leaf nodes, each node considered once.

Figure out the boundary nodes of this binary tree in an Anti-Clockwise direction starting from the root node.


Example :

Input: Consider the binary tree A as shown in the figure:
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
    vector<int> traverseBoundary(Node* root){
	    vector<int> ans;
        if(root==nullptr) return ans;
        if(!leafNode(root)) ans.push_back(root->data);
        addLeftBoundary(root,ans);
        addLeafNodes(root,ans);
        addRightBoundary(root,ans);
        return ans;
    }

    bool leafNode(Node* node){
        if(node->left==nullptr && node->right==nullptr) return true;
        return false;
    }


    void addLeftBoundary(Node* root,vector<int>& ans){
        Node* curr = root->left;
        while(curr!=nullptr){
            if(leafNode(curr)==false) ans.push_back(curr->data);
            if(curr->left!=nullptr) curr = curr->left;
            else curr = curr->right;
        }
    }

    // inorder traversal 
    void addLeafNodes(Node* root,vector<int>& ans){
        if(root==nullptr) return;
        
        if(leafNode(root)==true){
            ans.push_back(root->data);
            return;
        }

        addLeafNodes(root->left,ans);
        addLeafNodes(root->right,ans);
    }

    void addRightBoundary(Node* root,vector<int>& ans){
        Node* curr = root->right;
        vector<int> temp;
        while(curr!=nullptr){
            if(leafNode(curr)==false) temp.push_back(curr->data);
            if(curr->right!=nullptr) curr = curr->right;
            else curr = curr->left;
        }

        for(int i=temp.size()-1;i>=0;i--){
            ans.push_back(temp[i]);
        }
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

    vector<int> ans = s.traverseBoundary(&root);
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


