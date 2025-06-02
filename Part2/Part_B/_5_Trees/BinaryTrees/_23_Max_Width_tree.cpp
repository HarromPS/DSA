#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), 
where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

        1               1
      /  \
      2   3             2
         / \
         4  5           2
        / \  / \
        8  N 6  7       4

        max width between two non null nodes at any level is 4


Using Segment Trees 

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
    // Using segment trees 
    int widthOfBinaryTree(Node* root) {
        // level order traversal
        queue<pair<Node*,long long>> q;   // node, index
        q.push({root,0});
        int ans=0;

        while(!q.empty()){
            // take out whole level 
            int size = q.size();
            int min = q.front().second; // min in whole level 
            int first, last;
            for(int ind=0;ind<size;ind++){
                Node* n = q.front().first;
                int i = q.front().second;
                q.pop();

                int currId = i - min; // i - min
                if(ind==0) first = currId;
                if(ind == size-1) last = currId;
                if(n->left!=nullptr) q.push({n->left, (long long)2*currId+1});
                if(n->right!=nullptr) q.push({n->right, (long long)2*currId+2});
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }    
};

/*
        1
       /  \
      2    2
     / \  / \
    3   4 4  3
       /  \ 
       5   5

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
    Node nine(9);

    root.left = &two;
    root.right = &five;

    two.left=&three;
    two.right=&four;

    five.left=&six;
    five.right=&seven;

    Solution s;

    int res = s.widthOfBinaryTree(&root);
    cout<<res<<endl;
    // res=s.lowestCommonAncestor(&root,3,8);
    // cout<<res<<endl;
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


