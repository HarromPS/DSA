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
    int MaxDepth_Height_Tree_recursive(Node* root){
        // recursively find depth of tree 
        // base condition
        if(root==nullptr){
            return 0;
        }

        // recursive function calls 
        int left = MaxDepth_Height_Tree_recursive(root->left);
        int right = MaxDepth_Height_Tree_recursive(root->right);

        return 1 + max(left,right);
    }

    int MaxDepth_Height_Tree_iteratively(Node* root){
        // use a level wise traversal BFS
        // Done using a queue ds 

        if(root==nullptr) return 0;

        int height=1;   // at least 1 node
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            vector<Node*> temp;
            for(int i=0;i<q.size();i++){
                temp.push_back(q.front());
                q.pop();
            }

            int flag=0; // to check if any child node
            for(auto it:temp){
                if(it->left!=nullptr) {
                    q.push(it->left);
                    flag=1;
                }
                if(it->right!=nullptr){
                    q.push(it->right);
                    flag=1;
                }
            }
            if(flag==1){
                height+=1;
            }
        }
        return height;
    }
};

/*
        1
       /  \
      2    7
     /  \
     3  4
       /  \
       5   6

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
    int res = s.MaxDepth_Height_Tree_recursive(&root);
    cout<<res<<endl;
    res = s.MaxDepth_Height_Tree_iteratively(&root);
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


