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
    // Tree Traversals
    // TC:O(N) SC:O(N)    
  
    void PreOrderTraversal(Node* root){
        if(root==nullptr) return;

        cout<<(root->data)<<" ";
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }

    void InOrderTraversal(Node* root){
        if(root==nullptr) return;

        InOrderTraversal(root->left);
        cout<<(root->data)<<" ";
        InOrderTraversal(root->right);
    }

    void PostOrderTraversal(Node* root){
        if(root==nullptr) return;

        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        cout<<(root->data)<<" ";
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
    Node* root;
    root->data = 1;
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(4);

    Solution s;
    
    s.PreOrderTraversal(root);
    cout<<endl;
    s.InOrderTraversal(root);
    cout<<endl;
    s.PostOrderTraversal(root);
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


