
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

/*
Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

               10
            /      \
           5        13
          /  \     /  \ 
          3   6   11  14
         / \   \ 
        2   4   9

        k=19
        node 6 and node 13 make it true
        node 5 and node 14 make it true

        k=21
        node 10 and node 11

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
    // get the inorder traversal of tree and perform 2 sum
    bool twoSum(vector<int>& v,int k){
        int i=0;
        int j=v.size()-1;
        while(i<j){
            if(v[i]+v[j]==k) return true;
            if(v[i]+v[j]<k){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }

    // brute force:TC:O(N) SC:O(N)
    bool findTarget(Node* root, int k) {
        if(root==nullptr) return false;
        Node* curr=root;
        vector<int> inorder;
        while(curr!=nullptr){
            if(curr->left==nullptr){
                inorder.push_back(curr->data);
                curr=curr->right;
            }else{
                Node* prev=curr->left;  // get rightmost guy in left subtree
                while(prev->right!=nullptr && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==nullptr){
                    // create thread 
                    prev->right=curr;
                    curr=curr->left;
                }else{
                    // remove thread 
                    prev->right=nullptr;
                    inorder.push_back(curr->data);
                    curr=curr->right;
                }
            }
        }
        return twoSum(inorder,k);
    }
    
};

class BSTIterator{
private:
    stack<Node*> st1;
    stack<Node*> st2;
public:
    BSTIterator(Node* root){
        // push initially all nodes to stack till left is null
        pushRightsLeftNodes(root);
        // push initially all nodes to stack till left is null
        pushLeftsRightNodes(root);
    }

    Node* next(){
        Node* node=st1.top();
        st1.pop();

        // push all nodes in right to stack
        pushRightsLeftNodes(node->right);
        return node;
    }

    Node* before(){
        Node* node=st2.top();
        st2.pop();

        // push all nodes in left to stack
        pushLeftsRightNodes(node->left);
        return node;
    }

    void pushRightsLeftNodes(Node* node){
        while(node!=nullptr){
            st1.push(node);
            node=node->left;
        }
    }

    void pushLeftsRightNodes(Node* node){
        while(node!=nullptr){
            st2.push(node);
            node=node->right;
        }
    }

    bool findTarget(int k){
        Node* i=next();
        Node* j=before();
        while(i!=j){
            if(i->data+j->data == k) return true;
            if(i->data+j->data < k){
                i=next();
            }else{
                j=before();
            }
        }
        return false;
    }
};
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
    int k=20;
    bool res = s.findTarget(&root,k);
    cout<<res<<endl;


    BSTIterator s2(&root);
    res = s2.findTarget(k);
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
    // int t;
    // cin>>t;
    // while(t--){
    // solve();
        
    // }
    solve();
    return 0;
}


