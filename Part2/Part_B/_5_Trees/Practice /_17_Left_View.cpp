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
    bool leafNode(Node* node){
        if(node->left==nullptr && node->right==nullptr){
            return true;
        }
        return false;
    }
    void leftView_1(Node* root){
        // by observation left boundary is left view
        if(root==nullptr) return;
        vector<int> leftBoundary;

        if(!leafNode(root)==true) leftBoundary.push_back(root->data);
        Node* curr = root->left;
        while(curr!=nullptr){
            if(!leafNode(curr)==true) leftBoundary.push_back(curr->data);
            if(curr->left!=nullptr) curr = curr->left;
            else curr = curr->right;
        }

        // still leaf nodes are left to add, so this code wont work as expected
        for(auto it:leftBoundary){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    void leftView(Node* root){
        // all nodes coming on left in a level order traversal
        // done using queue 
        vector<int> ans;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            // level wise traversal 
            int n = q.size();   // use n as q is getting filled, so it will misbehave
            for(int i=0;i<n;i++){
                Node* n = q.front();
                q.pop();

                // add next level to queue 
                if(n->left!=nullptr) q.push(n->left);
                if(n->right!=nullptr) q.push(n->right);

                // check for left view 
                if(i==0) ans.push_back(n->data);
            }
        }
    }

    void traversal(Node* root,vector<int>& v,int level){
        if(root==nullptr) return;
        if(v.size()==level) v.push_back(root->data);
        traversal(root->left,v,level+1);
        traversal(root->right,v,level+1);
    }
    void leftView_2(Node* root){
        int level = 0;
        vector<int> v;
        traversal(root,v,level);
        for(auto it:v) cout<<it<<" ";
        cout<<endl;
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
    // Node eight(8);

    root.left = &two;
    root.right = &five;

    two.left=&three;
    two.right=&four;

    five.left=&six;
    five.right=&seven;

    Solution s;
    // s.leftView_1(&root);
    s.leftView_2(&root);

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


