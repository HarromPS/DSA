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
    void inorderTraversal(Node* node, vector<int>&v){
        if(node==nullptr) return ;
        inorderTraversal(node->left,v);
        v.push_back(node->data);
        inorderTraversal(node->right,v);
    }

    int KthSmallestBruteForce(Node* root,int k){
        // collect the inorder traversal of BST
        vector<int> inorder;
        inorderTraversal(root,inorder);
        // return kth indexed node value(k is 1 based indexed)
        return inorder[k-1];
    }

    int optimizedKthSmallestUsingMorrisAlgo(Node* root,int k){
        // use a count variable to count current node count 
        int count=0;
        int ans=0;
        Node* node=root;
        while(node!=nullptr){
            // 1st case 
            if(node->left == nullptr){
                // node is itself root
                count+=1;
                if(count==k){
                    // if this is kth smallest element return
                    ans= node->data;
                    return ans;
                }
                node = node->right;
            }
            else{
                // find rightmost guy in left subtree 
                Node* prev=node->left;
                while(prev->right!=nullptr && prev->right!=node){
                    prev=prev->right;
                }
                if(prev->right==nullptr){
                    // if no thread, create one 
                    prev->right = node;
                    node=node->left;
                }
                else{
                    // remove thread 
                    prev->right=nullptr;
                    count+=1;   // visit the node
                    if(count==k){
                        // if this is kth smallest element return
                        ans= node->data;
                        return ans;
                    }
                    node = node->right;
                }
            }
        }
        return -1;
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
    int res =s.KthSmallestBruteForce(&root,5);
    cout<<res<<endl;
    res = s.optimizedKthSmallestUsingMorrisAlgo(&root,5);
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
    solve();
    return 0;
}
