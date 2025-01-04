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
    void printTree(Node * root){
        if(root==nullptr) return;
        cout<<root->data<<" ";
        printTree(root->left);
        printTree(root->right);
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
    s.printTree(root);
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


