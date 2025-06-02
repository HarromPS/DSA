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
    void IterativeInorderTraversal(Node* root){
        // Done using stack ds, DFS 
        // left root right
        vector<int> ans;
        stack<Node*> st;

        while(true){
            if(root!=nullptr){
                st.push(root);
                root = root->left;
            }
            else{
                if(st.empty()) break;
                root = st.top();
                st.pop();
                ans.push_back(root->data);
                root = root->right;
            }
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
    s.IterativeInorderTraversal(&root);
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


