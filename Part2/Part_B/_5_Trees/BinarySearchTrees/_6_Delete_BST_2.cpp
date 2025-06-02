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

    Node* deleteNode(Node* root, int key) {
        if(root==nullptr) return nullptr;
        if(root->data == key){
            return helper(root);
        }

        Node* node = root;
        while(root!=nullptr){
            if(key < root->data){
                // must be on left 
                if(root->left!=nullptr && root->left->data == key){
                    root->left = helper(root->left);
                    break;
                }else{
                    root = root->left;
                }
            }else{
                if(root->right!=nullptr && root->right->data == key){
                    root->right = helper(root->right);
                    break;
                }else{
                    root = root->right;
                }
            }
        }
        return node;
    }

    Node* helper(Node* root){
        if(root->left==nullptr){
            return root->right;
        }
        else if(root->right==nullptr){
            return root->left;
        }

        // both child present 
        Node* rightChild = root->right;
        Node* lastLeftSubtreeChild = lastRight(root->left);
        lastLeftSubtreeChild->right = rightChild;
        return root->left;
    }

    Node* lastRight(Node* root){
        if(root->right==nullptr){
            return root;
        }
        Node* curr=root;
        while(curr->right!=nullptr){
            curr = curr->right;
        }
        return curr;
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
    Node* res=s.deleteNode(&root,5);
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
