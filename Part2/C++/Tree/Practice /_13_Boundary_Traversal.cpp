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
    void inorder(Node* node,vector<int>& v){
        if(node==nullptr) return;

        inorder(node->left,v);
        if(node->left == nullptr && node->right == nullptr){
            v.push_back(node->data);
            return;
        }
        inorder(node->right,v);

    }

    void BoundaryTraversal(Node* node){
        // left boundary
        // bottom leat nodes
        // right boundary 

        if(node==nullptr) return;

        vector<int> leftBoundary, leafNodes, rightBoundary;

        // add root node in left boundary first 
        // dont add if its a leaf node
        if(node->left!=nullptr && node->right!=nullptr)
            leftBoundary.push_back(node->data);

        Node* curr = node->left;
        while(curr!=nullptr){
            if(curr->left!=nullptr && curr->right!=nullptr){
                leftBoundary.push_back(curr->data);
            }
            if(curr->left!=nullptr){
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }

        // only leaf nodes 
        inorder(node, leafNodes);

        // right boundary 
        curr = node->right;
        while(curr!=nullptr){
            if(curr->left!=nullptr && curr->right!=nullptr){
                rightBoundary.push_back(curr->data);
            }
            if(curr->right!=nullptr){
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }

        // add it all up
        for(auto it:leftBoundary) cout<<it<<" ";
        for(auto it:leafNodes) cout<<it<<" ";
        for(auto it:rightBoundary) cout<<it<<" ";
        cout<<endl;
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
    // Node eight(8);

    root.left = &two;
    root.right = &five;

    two.left=&three;
    two.right=&four;

    five.left=&six;
    five.right=&seven;

    Solution s;
    s.BoundaryTraversal(&root);

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


