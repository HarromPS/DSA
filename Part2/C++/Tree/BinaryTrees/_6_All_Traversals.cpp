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
    // TC:O(3N) SC:O(3N)
    void AllTraversals(Node* root,vector<int>& preorder,vector<int>& inorder,vector<int>& postorder){
        if(root==nullptr) return;

        preorder.push_back(root->data);
        AllTraversals(root->left,preorder,inorder,postorder);
        inorder.push_back(root->data);
        AllTraversals(root->right,preorder,inorder,postorder);
        postorder.push_back(root->data);
    }

    void AllTraversalsIteratively(Node* root){
        vector<int> preorder,inorder,postorder;
        stack<pair<Node*,string>> st;
        st.push({root,"preOrder"});   

        // node: root, preorder - 1
        // node: root, inorder - 2
        // node: root, postorder - 3

        while(!st.empty()){
            pair<Node*, string> n = st.top();
            st.pop();

            if(n.second == "preOrder"){
                preorder.push_back(n.first->data);
                st.push({n.first,"inOrder"});
                if(n.first->left!=nullptr){
                    st.push({n.first->left,"preOrder"});
                }
            }
            else if(n.second == "inOrder"){
                inorder.push_back(n.first->data);
                st.push({n.first,"postOrder"});
                if(n.first->right!=nullptr){
                    st.push({n.first->right,"preOrder"});
                }
            }
            else if(n.second == "postOrder"){
                postorder.push_back(n.first->data);
            }
        }
        for(int i=0;i<preorder.size();i++){
            cout<<preorder[i]<<" "<<inorder[i]<<" "<<postorder[i]<<endl;
        }   
    }
};

/*
        1
       /  \
      2    3
        \
        4

*/
void solve(){
    Node root(1);
    Node two(2);
    Node three(3);
    Node four(4);
    Node five(5);
    Node six(6);
    Node seven(7);

    root.left = &two;
    root.right = &five;

    two.left=&three;
    two.right=&four;

    five.left=&six;
    five.right=&seven;
    
    vector<int> preorder,inorder,postorder;
    Solution s;

    // using recursion 
    s.AllTraversals(&root, preorder,inorder,postorder);
    for(int i=0;i<preorder.size();i++){
        cout<<preorder[i]<<" "<<inorder[i]<<" "<<postorder[i]<<endl;
    }

    // iterative method
    cout<<endl;
    s.AllTraversalsIteratively(&root);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../..input.txt", "r", stdin);
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


