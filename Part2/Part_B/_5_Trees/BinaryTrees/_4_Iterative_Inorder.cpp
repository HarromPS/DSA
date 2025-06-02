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
    void IterativeInorderTraversal(Node* root){
        vector<int> inorder;
        if(root==nullptr) return ;

        stack<Node*> st;   // stack for DFS operation
        Node* n=root;

        /*
        while(!st.empty()){
            // go to left 
            if(n->left!=nullptr){
                st.push(n->left);
                n=n->left;
                continue;
            }

            // go to stack top 
            inorder.push_back(st.top()->data);

            n=st.top();
            st.pop();

            // go to right
            if(n->right!=nullptr){
                st.push(n->right);
                n=n->right;
            }
        }
        */

        while(true){
            if(n!=nullptr){
                st.push(n);
                n=n->left;
            }
            else{
                if(st.empty()==true) break;
                n=st.top();
                st.pop();
                inorder.push_back(n->data);
                n=n->right;
            }
        }
        for(auto it: inorder){
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
    root.left = new Node(2);
    root.right = new Node(3);

    root.left->right = new Node(4);

    Solution s;
    s.IterativeInorderTraversal(&root);
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


