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
    void LevelOrderTraversal(Node* root){
       // Done using a Queue data structure
       vector<int> ans;
       queue<Node*> q;

        // add root node to start
        q.push(root);

        // iterate tree and do level order traversal 
        while(!q.empty()){
            vector<Node*> temp;
            while(!q.empty()){
                temp.push_back(q.front());
                q.pop();
            }
            for(auto it:temp){
                // add left and right child 
                if(it->left!=nullptr){
                    q.push(it->left);
                }
                if(it->right!=nullptr){
                    q.push(it->right);
                }
            }

            // add it to answer 
            for(int i=0;i<temp.size();i++){
                ans.push_back(temp[i]->data);
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
    three.right=&four;
    four.right=&five;
    five.right=&six;
    seven.left=&eight;

    Solution s;
    s.LevelOrderTraversal(&root);
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


