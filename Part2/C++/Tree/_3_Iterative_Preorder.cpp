#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Tree - non linear data structure
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

    // TC:O(n) SC:O(n) + O(n)
    void IterativePreOrderTraversal(Node* root){
        vector<int> preorder;
        if(root==nullptr) return ;

        stack<Node*> st;   // stack for DFS operation

        // initially add root to stack
        st.push(root);
        while(!st.empty()){
            Node* n=st.top();
            st.pop();
            // root left right 
            preorder.push_back(n->data);
            if(n->right!=nullptr) st.push(n->right);
            if(n->left!=nullptr) st.push(n->left);
        }

        for(auto it: preorder){
            cout<<it<<" ";
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
    Node eight(8);

    root.left = &two;
    root.right = &seven;

    two.left=&three;
    three.right=&four;
    four.right=&five;
    five.right=&six;
    seven.left=&eight;

    Solution s;
    s.IterativePreOrderTraversal(&root);
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


