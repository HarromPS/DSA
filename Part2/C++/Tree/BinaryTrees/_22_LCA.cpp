#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes p and q as 
the lowest node in T that has both p and q as descendants 
(where we allow a node to be a descendant of itself).”

        1
      /  \
      2   3
         / \
         4  5
        /   / \
        8   6  7

lca (7,8) = 3
lca (3, 8) = 3
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
    int lowestCommonAncestor(Node* root, int p,int q) {
        if(root==nullptr) return -1;    // as null

        // if it is one of p or q
        if(root->data == p) return p;
        if(root->data == q) return q;

        int left = lowestCommonAncestor(root->left, p, q);
        int right = lowestCommonAncestor(root->right, p, q);

        // if any of the side has one of the node we are looking for 
        if(left==-1 && right!=-1) return right;
        if(right==-1 && left!=-1) return left;

        // check if found on left and right 
        if(left!=-1 && right!=-1) return root->data;

        // means not found on left and right, return null
        return -1;
    }

    bool traversal(Node* node,vector<int>& v,int targetNode){
        if(node==nullptr){
            return false;
        }

        v.push_back(node->data);
        if(node->data==targetNode){
            return true;
        }

        // in mirror, left = right and vice versa
        bool l = traversal(node->left,v,targetNode);
        if(l==true) return true;

        bool r = traversal(node->right,v,targetNode);
        if(r==true) return true;

        // take out previous node, after both way traversal 
        v.pop_back();

        return false;
    }

    int lowestCommonAncestorBruteForce(Node* root, int p,int q){
        vector<int> p_ds;
        vector<int> q_ds;
        traversal(root,p_ds,p);
        traversal(root,q_ds,q);
        
        // check for common ancestor
        int i=0,j=0;
        while(i<p_ds.size() && j<q_ds.size()){
            if(p_ds[i]==q_ds[j]){
                i++;
                j++;
            }
            else{
                if(i>0)
                    return p_ds[i-1];
            }
        }
        if(i>0) 
            return p_ds[i-1];
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
    Node root(1);
    Node two(2);
    Node three(3);
    Node four(4);
    Node five(5);
    Node six(6);
    Node seven(7);
    Node eight(8);
    Node nine(9);

    root.left = &two;
    root.right = &three;

    three.left=&four;
    three.right=&five;

    four.left=&eight;

    five.left=&six;
    five.right=&seven;

    Solution s;

    int res = s.lowestCommonAncestorBruteForce(&root,7,6);
    cout<<res<<endl;
    res=s.lowestCommonAncestor(&root,3,8);
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


