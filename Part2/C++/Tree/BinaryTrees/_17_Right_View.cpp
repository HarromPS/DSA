#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given the root of a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.

        1
       /  \
      2    5
     / \  / \
    3   4 6  7
       /  \
       8   9

right=>[1 5 7 9]
left=>[1 2 3 8]

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
    vector<int> rightSideView(Node *root){
        vector<int> right;
        if(root==nullptr) return right;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){ 
                Node* node = q.front();
                q.pop();
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
                if(i==(n-1)) right.push_back(node->data);
            }
        }
        return right;
    }

    void treeTraversal(Node* root,int level,vector<int>& ds){
        if(root==nullptr) return;
        if(ds.size()==level) ds.push_back(root->data);  

        // right view, go right first
        treeTraversal(root->right,level+1,ds);
        treeTraversal(root->left,level+1,ds);
    }

    vector<int> rightSideViewRecursive(Node *root){
        vector<int> right;
        treeTraversal(root,0,right);
        return right;
    }
};

/*
        1
       /  \
      2    5
     / \  / \
    3   4 6  7
       /  \
       8   9

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
    root.right = &five;

    two.left=&three;
    two.right=&four;

    five.left=&six;
    five.right=&seven;

    four.left = &eight;
    six.right  = &nine;
    Solution s;

    vector<int> ans = s.rightSideView(&root);
    for(auto iter:ans){
        cout<<iter<<" ";
    }
    cout<<endl;
    ans = s.rightSideViewRecursive(&root);
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


