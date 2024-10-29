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
    int maxPathSum(Node* root) {
        int ans=0;
        getAns(root,&ans);
        return ans;
    }

    int getAns(Node* root,int *ans){
        if(root==nullptr) return 0;

        int leftSum = getAns(root->left, ans);
        int rightSum = getAns(root->right, ans);

        // ignore negative path sum
        if(leftSum<0) leftSum=0;
        if(rightSum<0) rightSum=0;

        *ans=max(*ans, root->data+leftSum+rightSum);

        return root->data+max(leftSum,rightSum);
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

    // root.left = &two;
    // root.right = &five;

    // two.left=&three;
    // two.right=&four;

    // five.left=&six;
    // five.right=&seven;

    root.left = &two;
    root.right = &three;

    Solution s;

    int ans = s.maxPathSum(&root);
    cout<<ans<<endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
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


