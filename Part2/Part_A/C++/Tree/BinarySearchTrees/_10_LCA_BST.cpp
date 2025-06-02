#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes p and q as the lowest node in T that 
has both p and q as descendants (where we allow a node to be a descendant of itself).”

     10
    /  \
   5    11
  / \ 
 4   7
      \
       8

lca(8 4) => 5
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

    void search(Node* node,Node* p,vector<int>& ds){
        if(node==nullptr){
            return ;
        }
        Node* curr = node;
        while(curr!=nullptr){
            ds.push_back(curr->data);
            if(curr->data==p->data) break;
            if(curr->data > p->data) curr=curr->left;
            else if(curr->data < p->data) curr=curr->right;
        }
    }

    Node* lowestCommonAncestorBrute(Node* root,Node* p,Node* q){
        // search the paths for both nodes 
        vector<int> path1,path2;
        search(root,p,path1);
        search(root,q,path2);

        for(auto it:path1) cout<<it<<" ";
        cout<<endl;
        for(auto it:path2) cout<<it<<" ";
        cout<<endl;

        // check for last node where the generation tree got seperated 
        Node* lca=new Node(-1);
        for(int i=0;i<min(path1.size(), path2.size());i++){
            if(path1[i]!=path2[i]){
                lca->data=path1[i-1];
                break;
            }
        }
        if(lca->data == -1){
            if(path1.size()<path2.size()){
                lca->data = path1[path1.size()-1];
            }else{
                lca->data = path2[path2.size()-1];
            }
        }
        return lca;
    }

    Node* lowestCommonAncestor(Node* root,Node* p,Node* q){
        if(root==nullptr) return nullptr;
        Node* curr=root;
        while(curr!=nullptr){
            // any one of node found as lca
            if(curr->data == p->data || curr->data == q->data){
                return curr;
            }
            else if(curr->data > p->data && curr->data > q->data){
                // both on left 
                curr = curr->left;
            }
            else if(curr->data < p->data && curr->data < q->data){
                // both on right
                curr = curr->right;
            }else{
                // one on left and other on right 
                if(curr->left!=nullptr && curr->right!=nullptr){
                    return curr;
                }else{
                    curr=curr->left;
                }
            }
        }
        // not found
        return nullptr;
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
    Node* res =s.lowestCommonAncestorBrute(&root, &eight,&ten);
    cout<<res->data<<endl;
    res =s.lowestCommonAncestor(&root, &eight,&ten);
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
    solve();
    return 0;
}


