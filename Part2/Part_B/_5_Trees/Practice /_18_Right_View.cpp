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
    void traversal(Node* root,vector<int>& v,int level){
        if(root==nullptr) return;
        if(v.size()==level) v.push_back(root->data);
        traversal(root->right,v,level+1);
        traversal(root->left,v,level+1);
    }
    void rightView(Node* root){
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
    s.rightView(&root);

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


