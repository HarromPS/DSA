#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Heighr Balanced
A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node 
never differs by more than one.

if(diff of leftSubtree - rightSubtree >=2 ) => not height balanced tree

it should be <=1 
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
    // using recursive solutions
    // TC:O(N) SC:O(height)
    int getheightOfTree(Node* root){
        if(root==nullptr) return 0;

        int leftHeight = getheightOfTree(root->left);
        int rightHeight = getheightOfTree(root->right);

        return (1 + max(leftHeight, rightHeight));    // 1 for current node
    }
    // TC:O(N^2) SC:O(N + height)
    bool isBalanced_1(Node* root){
        if(root==nullptr) return true;
        stack<Node*> st;
        st.push(root);

        // traverse tree iteratively
        while(!st.empty()){
            Node* n = st.top();
            st.pop();

            int left=0,right=0;
            if(n->left!=nullptr){
                st.push(n->left);
                left = getheightOfTree(n->left);
            }
            if(n->right!=nullptr){
                st.push(n->right);
                right = getheightOfTree(n->right);
            }

            // check if height balanced
            if(abs(left-right) > 1) return false;
        }
        return true;
    }

    int dfsHeight(Node* root){
        if(root==nullptr) return 0;

        int leftHeight = dfsHeight(root->left);
        if(leftHeight == -1) return -1;

        int rightHeight = dfsHeight(root->right);
        if(rightHeight == -1) return -1;

        if(abs(leftHeight - rightHeight) > 1) return -1;

        return 1+max(leftHeight, rightHeight);
    }

    // TC:O(N) SC:O(height)
    bool isbalanced(Node *root){
        int getans = dfsHeight(root);
        if(getans == -1) return false;
        return true;
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

    bool ans = s.isBalanced_1(&root);
    cout<<ans<<endl;

    ans = s.isbalanced(&root);
    cout<<ans<<endl;
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


