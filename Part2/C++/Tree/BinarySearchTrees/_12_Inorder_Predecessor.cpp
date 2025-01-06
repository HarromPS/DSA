#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

/*
You are given root node of the BST and the key node of the tree. 
You need to find the in-order successor and predecessor of a given key. 
If either predecessor or successor is not found, then set it to NULL.

Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor. 

               10
            /      \
           5        13
          /  \     /  \ 
          3   6   11  14
         / \   \ 
        2   4   9

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
    void inorderTraversal(Node* node,vector<int>& v){
        if(node==nullptr) return ;
        inorderTraversal(node->left,v);
        v.push_back(node->data);
        inorderTraversal(node->right,v);
    }   

    // TC:O(N+log n) SC:O(N)
    Node* findInorderPredecessorBrute(Node* root,int value){
        // get the inorder traversal of bst 
        if(root==nullptr) return root;
        vector<int> inorder;
        inorderTraversal(root,inorder);

        // find value and return 
        int n=inorder.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(inorder[mid]==value){
                if(mid-1>=0){
                    return new Node(inorder[mid-1]);
                }
            }
            else if(value < inorder[mid]){
                // on left
                high=mid-1;
            }else{
                // on right 
                low=mid+1;
            }
        }
        return nullptr; // not found
    }

    void getRecursivePredecessor(Node* root, Node*& ans, int value){
        if(root==nullptr) return;

        // left root right
        getRecursivePredecessor(root->left, ans,value);
        
        if(root->data == value){
            return; // we have already got the predecessor in our ans, just return it.
        }else{
            // in our inorder tarversal, we havnt reached to value so this could be possible ans
            ans=root;
        }

        getRecursivePredecessor(root->right, ans,value);
    }
    // TC:O(N) SC:O(N) 
    Node* findInorderPredecessorBetter_Recursive(Node* root,int value){
        Node* ans=nullptr;
        getRecursivePredecessor(root,ans,value);
        return ans;
    }

    Node* findInorderPredecessorBetter_Iterative(Node* root,int value){
        // using morris algorithm
        if(root==nullptr) return root;
        Node* ans=nullptr;
        Node* curr=root;
        while(curr!=nullptr){
            // 1st condition 
            if(curr->left==nullptr){
                curr=curr->right;
            }else{
                // find rightmost guy in left subtree
                Node* prev=curr->left;
                while(prev->right!=nullptr && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==nullptr){
                    // create thread
                    prev->right=curr;
                    curr = curr->left;
                }else{
                    // remove thread 
                    if(curr->data == value){
                        ans=prev;
                    }
                    prev=nullptr;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }

    Node* findInoderPredecessorOptimal(Node* root,int value){
        // using height of tree to find solution in optimal time complexity 
        if(root==nullptr) return root;
        Node* ans=nullptr;
        Node* node=root;
        while(node!=nullptr){
            if(node->data >= value){
                node=node->left;    // want lesser but greater than value
            }else{
                ans=node;
                node=node->right;
            }
        }
        return ans;
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
    // Node* res =s.findInorderPredecessorBrute(&root,10);
    // cout<<res->data<<endl;
    // res =s.findInorderPredecessorBetter_Recursive(&root,10);
    // cout<<res->data<<endl;
    // res =s.findInorderPredecessorBetter_Iterative(&root,10);
    // cout<<res->data<<endl;
    Node* res =s.findInoderPredecessorOptimal(&root,10);
    cout<<res->data<<endl;
    
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


