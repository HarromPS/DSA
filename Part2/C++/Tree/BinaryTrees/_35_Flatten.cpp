


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Binary tree
       50
      /  \
     7     2
    / \  
    3  5 

ll: (50 -> 7 -> 3 -> 5 -> 2)
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
    void visit(Node* root){
        Node* curr=root;
        while(curr!=nullptr){
            cout<<curr->data<<" ";
            curr=curr->right;
        }
    }

    void preOrder(Node* node,vector<int>& preorder){
        if(node==nullptr) return;
        preorder.push_back(node->data);
        preOrder(node->left,preorder);
        preOrder(node->right,preorder);
    }


    // TC:O(N) SC:O(N)
    void flattenBruteForce(Node* root) {
        // store preorder in a list
        // create a new ll from that
        vector<int> preorder;
        preOrder(root,preorder);
        
        Node* curr=new Node(-1);
        Node* node=curr;
        for(int i=0;i<preorder.size();i++){
            curr->data = preorder[i];
            curr->right=new Node(-1);
            if(i==preorder.size()-1){
                curr->right=nullptr;
                break;
            }
            curr=curr->right;
        }
        visit(node);
    }
    
    // TC:O(N) SC:O(N)
    Node* prev=nullptr;
    void flattenBrute(Node* root) {
        if(root==nullptr) return;
        flattenBrute(root->right);
        flattenBrute(root->left);
        root->right=prev;
        root->left=nullptr;
        prev=root;
    }

    // TC:O(N) SC:O(N)
    void flattenBetter(Node* node){
        // iterative 
        if(node == NULL){
            return;
        }
        stack<Node*>st;
        st.push(node);
        while(!st.empty()){
            Node* curr=st.top();
            st.pop();

            if(curr->right!=nullptr) st.push(curr->right);
            if(curr->left!=nullptr) st.push(curr->left);
            
            if(!st.empty()) curr->right=st.top();
            curr->left=nullptr;
        }
    }

    void flattenOptimal(Node* root){
        if(root==nullptr) return;
        
        // left subtree rightmost guy -> right subtree leftmost guy
        Node* curr=root;
        while(curr!=nullptr){
            // 1st case if left is null, right is right obviously
            if(curr->left!=nullptr){
                Node* prev=curr->left;
                while(prev->right!=nullptr){
                    prev=prev->right;
                }
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=nullptr;
            }
            curr=curr->right;
        }
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
    Node nine(4);

    root.left = &two;
    root.right = &three;

    two.left=&four;
    two.right=&five;

    five.left=&six;
    five.right=&seven;

    Solution s;
    // s.flattenBruteForce(&root);
    // s.flattenBrute(&root);
    // s.flattenBetter(&root);
    s.flattenOptimal(&root);
    s.visit(&root);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    solve();
    return 0;
}
