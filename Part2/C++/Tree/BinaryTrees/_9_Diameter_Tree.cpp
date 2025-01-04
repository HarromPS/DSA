#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
The diameter of a binary tree is the length of the longest path between any two end nodes in a tree.

The number of edges between two nodes represents the length of the path between them.

It does not need to be passed through to root
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
    int getHeight(Node* root){
        if(root==nullptr) return 0;

        return 1+max(getHeight(root->left), getHeight(root->right));
    }

    void getAns(Node* root,int* ans){
        if(root==nullptr) return;

        int leftExtreme = getHeight(root->left);
        int rightExtreme = getHeight(root->right);

        *ans = max(*ans, leftExtreme+rightExtreme);

        getAns(root->left,ans);
        getAns(root->right,ans);
    }

    int diameterOfBinaryTree(Node* root) {
        int ans=0;
        getAns(root,&ans);
        return ans;
    }

    int getAns_2(Node* root,int *ans){
        if(root==nullptr) return 0;

        int leftH = getAns_2(root->left, ans);
        int rightH = getAns_2(root->right, ans);

        *ans=max(*ans, leftH+rightH);

        return 1+max(leftH,rightH);
    }

    int diameterOfBinaryTree_2(Node* root) {
        int ans=0;
        getAns_2(root,&ans);
        return ans;
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

    Solution s;

    int ans = s.diameterOfBinaryTree(&root);
    cout<<ans<<endl;
    ans = s.diameterOfBinaryTree_2(&root);
    cout<<ans<<endl;
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


