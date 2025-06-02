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

    // TC:O(n) SC:O(n) + O(n)
    void IterativePostOrderTraversal_2_stack(Node* root){
        vector<int> PostOrder;
        if(root==nullptr) return ;

        stack<Node*> st1;   // stack for DFS operation
        stack<Node*> st2;   // stack for DFS operation

        // initially add root to stack
        st1.push(root);
        while(!st1.empty()){
            Node* n = st1.top();
            st1.pop();

            st2.push(n);
            if(n->left!=nullptr){ st1.push(n->left);}
            if(n->right!=nullptr){ st1.push(n->right);}
        }
        while(!st2.empty()){
            PostOrder.push_back(st2.top()->data);
            st2.pop();
        }

        for(auto it: PostOrder){
            cout<<it<<" ";
        }
    }

    void IterativePostOrderTraversal_1_stack(Node* root){
        // go left right root 
        Node* curr=root;
        Node* temp=nullptr;
        stack<Node*> st;

        vector<int> ans;

        while(!st.empty() || curr!=nullptr){
            if(curr!=nullptr){ // curr, go left 
                st.push(curr);
                curr=curr->left;
            }else{
                temp=st.top()->right;
                if(temp==nullptr){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->data);
                    while(!st.empty() && temp==st.top()->right) {
                        temp=st.top();
                        st.pop();
                        ans.push_back(temp->data);
                    }
                }
                else{
                    curr=temp;
                }
            }
        }
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
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
    Node eight(8);

    root.left = &two;
    root.right = &seven;

    two.left=&three;
    three.right=&four;
    four.right=&five;
    five.right=&six;
    seven.left=&eight;

    Solution s;
    s.IterativePostOrderTraversal_2_stack(&root);
    cout<<endl;
    s.IterativePostOrderTraversal_1_stack(&root);
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


