#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.

     10
    /  \
   5    11
  / \ 
 4   7
      \
       8

delete 7

output: 
     10
    /  \
   5    11
  / \ 
 4   8

Either replace with Inorder predecessor or Inorder Successor
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
    void printTree(Node* node){
        if(node==nullptr) return ;
        printTree(node->left);
        cout<<node->data<<" ";
        printTree(node->right);
    }

    Node* inorderPredecessorNode(Node* node){
        // rightmost guy in left subtree 
        if(node->left == nullptr) return nullptr;

        Node* curr=node->left;
        while(curr!=nullptr && curr->right!=nullptr){
            curr=curr->right;
        }
        return curr;
    }

    Node* inorderSuccessorNode(Node* node){
        // leftmost guy in right subtree
        if(node->right == nullptr) return nullptr;
        
        Node* curr=node->right;
        while(curr->left!=nullptr){
            curr=curr->left;
        }
        return curr;
    }
    
    Node* deleteNode(Node* root, int key) {
        // search and find that key node
        if(root==nullptr) return root;

        if(key < root->data){
            // must be on left
            root->left = deleteNode(root->left, key);
        }
        else if(root->data < key){
            // must be on right
            root->right = deleteNode(root->right, key);
        }else{
            // found the key
            // if leaf node
            if(root->left==nullptr && root->right==nullptr){
                root = nullptr;   // points to null
            }
            else if(root->left!=nullptr && root->right!=nullptr){
                // 2 children
                Node* pre=inorderPredecessorNode(root);
                root->data = pre->data;
                // delete the predecessor node from left subtree
                root->left = deleteNode(root->left, pre->data);
            }else{
                // only one child
                Node* child=nullptr;
                if(root->left==nullptr){
                    child=root->right;
                }else{
                    child=root->left;
                }
                root = child;     // points to child
            }
        }
        return root;
    }
};

/*
        1
       /  \
      2    2
     / \  / \
    3   4 4  3
       /  \ 
       5   5

*/
void solve(){
    Node root(10);
    Node two(5);
    Node three(13);
    Node four(3);
    Node five(6);
    Node six(11);
    Node seven(14);
    Node eight(2);
    Node nine(4);
    Node ten(9);

    root.left = &two;
    root.right = &three;

    two.left=&four;
    two.right=&five;

    three.left=&six;
    three.right=&seven;

    four.left=&eight;
    four.right=&nine;

    five.right=&ten;

    Solution s;
    Node* res=s.deleteNode(&root,3);
    s.printTree(res);
    
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
    solve();
    return 0;
}
