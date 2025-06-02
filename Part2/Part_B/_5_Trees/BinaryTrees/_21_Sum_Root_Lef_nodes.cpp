#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 

    1
   /  \
   2   3

so 12, 13 => 12 + 13 = 25
Return the total sum of all root-to-leaf numbers. 
Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.
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

    void rootLeafTraversal(Node* node, int* ans,vector<int>& ds){
        if(node == nullptr) return; 

        // add node value 
        ds.push_back(node->data);

        // if its a leaf node, add it and return
        if(node->left==nullptr && node->right==nullptr){
            // create a number from root to leaf travesal
            int num=0;
            int x=1;
            for(int i=ds.size()-1;i>=0;i--){
                num = num+(x*ds[i]);
                x*=10;
            }
            *ans+=num;
            
            // 1 pop out of leaf node, to add next root node
            ds.pop_back();
            return;
        }
        rootLeafTraversal(node->left,ans,ds);
        rootLeafTraversal(node->right,ans,ds);
        
        // take out 
        ds.pop_back();
    }

    void Paths(Node* root) {
        int ans=0;
        vector<int> temp;
        rootLeafTraversal(root,&ans,temp);
        cout<<ans<<endl;
        return;
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
    root.right = &three;

    // two.left=&three;
    // two.right=&four;

    // five.left=&six;
    // five.right=&seven;

    Solution s;

    s.Paths(&root);
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


