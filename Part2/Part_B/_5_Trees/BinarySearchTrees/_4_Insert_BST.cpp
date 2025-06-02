#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

/*
You are given a BST(Binary Search Tree) with n number of nodes and value x. 
Your task is to find the greatest value node of the BST which is smaller than or equal to x.
Note: when x is smaller than the smallest node of BST then returns -1.

      5
    /   \
   1     7
    \
     2 
      \
       3

X = 3
We find 3 in BST, so ceil of 3 is 2.


X = 6
     10
    /  \
   5    11
  / \ 
 4   7
      \
       8

Output: 5
Explanation: We find 5 in BST, so ceil of 6 is 5.
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
    Node* insertIntoBST(Node* root,int val) {
        // insert into bst
        // best case
        if(root==nullptr){
            return new Node(val);
        }
        Node* node=root;
        while(node!=nullptr){
            if(node->data < val){
                // so val should be on right 
                if(node->right == nullptr){
                    node->right = new Node(val);
                    break;
                }else{
                    node = node->right; // search for space
                }
            }else{
                // if val is smaller than node, it should be placed on left 
                if(node->left==nullptr){
                    node->left = new Node(val);
                    break;
                }else{
                    node=node->left;
                }
            }
        }
        return root;
    }

    void printTree(Node* node){
        if(node==nullptr) return ;
        printTree(node->left);
        cout<<node->data<<" ";
        printTree(node->right);
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
    Node* res=s.insertIntoBST(&root,12);
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
