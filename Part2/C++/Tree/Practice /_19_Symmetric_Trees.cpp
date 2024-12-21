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
    bool traversal(Node* node1, Node* node2){
        if(node1==nullptr || node2==nullptr){
            if(node1==node2) return true;
            return false;
        }

        if(node1->data!=node2->data) return false;
        
        return traversal(node1->left, node2->right) && traversal(node1->right, node2->left);
    }
    // check if left and right subtree are symmetric or not
    bool isSymmetric(Node* root){
        if(root==nullptr) return true;
        return traversal(root->left, root->right);
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
    Node five(2);
    Node six(4);
    Node seven(3);
    // Node eight(8);

    root.left = &two;
    root.right = &five;

    two.left=&three;
    two.right=&four;

    five.left=&six;
    five.right=&seven;

    Solution s;
    bool res = s.isSymmetric(&root);
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


