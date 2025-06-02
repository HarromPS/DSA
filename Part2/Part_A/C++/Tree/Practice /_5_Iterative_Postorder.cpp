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
    void IterativePostorderTraversal_2_Stack(Node* root){
        // Done using stack ds, DFS 
        // left right root
        vector<int> ans;
        stack<Node*> st1;
        stack<Node*> st2;

        // add root for intial configuration 
        st1.push(root);
        while(!st1.empty()){
            Node* n = st1.top();
            st1.pop();
            st2.push(n);

            if(n->left!=nullptr) st1.push(n->left);
            if(n->right!=nullptr) st1.push(n->right);
        }

        while(!st2.empty()) {
            ans.push_back(st2.top()->data);
            st2.pop();
        }
        for(auto it:ans) cout<<it<<" ";
        cout<<endl;
    }

    void IterativePostorderTraversal_1_Stack(Node* root){
        // Done using stack ds, DFS 
        // left right root
        vector<int> ans;
        stack<Node*> st1;

        // add root for intial configuration 
        st1.push(root);
        while(!st1.empty()){
            Node* n = st1.top();
            st1.pop();
            ans.insert(ans.begin(),n->data);

            if(n->left!=nullptr) st1.push(n->left);
            if(n->right!=nullptr) st1.push(n->right);
        }

        for(auto it:ans) cout<<it<<" ";
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
    two.right=&four;
    four.left=&five;
    four.right=&six;

    Solution s;
    s.IterativePostorderTraversal_2_Stack(&root);
    s.IterativePostorderTraversal_1_Stack(&root);
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


