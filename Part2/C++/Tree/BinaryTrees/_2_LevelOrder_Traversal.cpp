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
    void levelOrderTraversal(Node* root){
        vector<vector<int>> ans;
        if(root==nullptr) return ;

        queue<Node*> q;     // queue for BFS traversal

        // initially add root to queue
        q.push(root);
        while(!q.empty()){
            // get all the nodes out 
            vector<Node*> temp;
            while(!q.empty()){
                temp.push_back(q.front());
                q.pop();
            }

            vector<int> level;
            for(auto it: temp){
                if(it->left!=nullptr) q.push(it->left);
                if(it->right!=nullptr) q.push(it->right);
                level.push_back(it->data);
            }
            // finally add to the answer 
            ans.push_back(level);
        }

        for(auto i: ans){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
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
    root.left = new Node(2);
    root.right = new Node(3);

    root.left->right = new Node(4);

    Solution s;
    s.levelOrderTraversal(&root);
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


