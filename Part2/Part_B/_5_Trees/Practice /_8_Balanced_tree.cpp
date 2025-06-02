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
    int getHeight(Node* root){
        // recursively find depth of tree 
        // base condition
        if(root==nullptr){
            return 0;
        }

        // recursive function calls 
        int left = getHeight(root->left);
        int right = getHeight(root->right);

        return 1 + max(left,right);
    }

    bool isBalancedTreeIteratively(Node* root){
        // using queue ds 
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            // check left and right subtree for every node
            Node* n = q.front();
            q.pop();

            int leftsubtree = getHeight(n->left);
            int rightsubtree = getHeight(n->right);

            // check if height diff is in range 0, -1 ,1 
            if(abs(leftsubtree-rightsubtree) > 1){
                return false;   // i.e tree is not balanced
            }

            if(n->left!=nullptr) q.push(n->left);
            if(n->right!=nullptr) q.push(n->right);
        }
        return true;
    }

    // a bit optimized
    int dfsHeight(Node* root){
        if(root==nullptr) return 0;
        int leftHeight = dfsHeight(root->left);
        if(leftHeight == -1) return -1;     // if not balanced return -1

        int rightHeight = dfsHeight(root->right);
        if(rightHeight == -1) return -1;

        // check height balance
        if(abs(leftHeight - rightHeight) > 1) return -1;
        return 1 + max(leftHeight, rightHeight);    // if balanced return height
    }
    bool isBalancedTreeRecursive(Node* root){
        return ((dfsHeight(root) == -1) ? false: true);
    }
};

/*
        1
       /  \
      2    7
     /  \
     3  4
       /  \
       5   6

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
    two.right=&four;
    four.left=&five;
    four.right=&six;

    // root.left = &two;
    // root.right = &five;

    // two.left=&three;
    // two.right=&four;

    // five.left=&six;
    // five.right=&seven;

    Solution s;
    bool res = s.isBalancedTreeIteratively(&root);
    cout<<res<<endl;
    res = s.isBalancedTreeRecursive(&root);
    cout<<res<<endl;
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


