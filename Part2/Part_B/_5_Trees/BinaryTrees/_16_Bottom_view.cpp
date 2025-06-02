#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root,
then the latter one in the level traversal is considered. 
For example, in the below diagram,
3 and 4 are both the bottommost nodes at a horizontal distance of 0,
here 4 will be considered.

        1
       /  \
      2    5
     / \  / \
    3   4 6  7
       /  \
       8   9

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
    vector<int> bottomView(Node *root){
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

            mp[v]=n->data;
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

    vector<int> ans = s.bottomView(&root);
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


