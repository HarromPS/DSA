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
    void AllTraversals(Node* root){
        vector<int> preorder,inorder,postorder;

        stack<pair<Node*,string>> st;
        // add root initially 
        st.push({root, "preorder"});

        // preorder - 1
        // inorder - 2
        // postorder - 3
        while(!st.empty()){
            pair<Node*,string> n = st.top();
            st.pop();

            if(n.second == "preorder"){
                preorder.push_back(n.first->data);
                st.push({n.first,"inorder"});
                if(n.first->left!=nullptr){
                    st.push({n.first->left,"preorder"});
                }
            }
            else if(n.second == "inorder"){
                inorder.push_back(n.first->data);
                st.push({n.first,"postorder"});
                if(n.first->right!=nullptr){
                    st.push({n.first->right,"preorder"});
                }
            }
            else if(n.second == "postorder"){
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
    Node eight(8);

    root.left = &two;
    root.right = &seven;

    two.left=&three;
    two.right=&four;
    four.left=&five;
    four.right=&six;

    Solution s;
    s.AllTraversals(&root);
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


