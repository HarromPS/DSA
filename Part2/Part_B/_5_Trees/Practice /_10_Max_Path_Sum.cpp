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
    int getAns(Node* root,int* ans){
        if(root==nullptr) return 0;

        int leftSum = getAns(root->left,ans);
        if(leftSum<0) leftSum=0;

        int rightSum = getAns(root->right,ans);
        if(rightSum < 0) rightSum=0;

        *ans = max(*ans, root->data+leftSum+rightSum);
        return root->data + max(leftSum, rightSum);

    }

    int maxPathSum(Node* root){
        int ans=0;
        getAns(root,&ans);
        return ans;
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
    root.right = &seven;

    two.left=&three;
    two.right=&four;
    four.left=&five;
    four.right=&six;

    // root.left = &two;
    // root.right = &five;

    // two.left=&three;
    // two.right=&four;

    // five.left=&six;
    // five.right=&seven;

    Solution s;
    int res = s.maxPathSum(&root);
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


