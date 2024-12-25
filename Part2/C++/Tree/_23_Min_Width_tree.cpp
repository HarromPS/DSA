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
    // Brute force TC:O(N) SC:O(2^level -1) space complexity of a complete bt

    int getHeight(Node* root){
        if(root==nullptr) return 0;

        int left=getHeight(root->left);
        int right=getHeight(root->right);

        return 1+max(left,right);
    }

    int widthOfBinaryTree(Node* root) {
        vector<vector<int>> levels;
        queue<Node*> q;
        q.push(root);

        // run the below loop till height, so that null node can have their null nodes for each level nodes 
        int height=getHeight(root);
        int i=1;

        while(!q.empty() && i<=height){
            int n=q.size();
            vector<int> temp;
            for(int i=0;i<n;i++){
                Node* node=q.front();
                q.pop();

                temp.push_back(node->data);

                if(node->left!=nullptr) q.push(node->left);
                else if(i!=height) q.push(new Node(-1)) ;  
                
                if(node->right!=nullptr) q.push(node->right);
                else if(i!=height)q.push(new Node(-1)) ;  
            }
            levels.push_back(temp);
            i++;
        }

        // neglet last array inserted as it contains only nullptrs
        int maxi=INT_MIN;
        for(auto it:levels){
            int i=0,n=it.size();
            int j=n-1;
            while(i<n) {
                if(it[i]!=-1) break;
                else i++;
            }
            while(j>=0){
                if(it[j]!=-1) break;
                else j--;
            }

            if(i<j){
                // means two non null ends
                maxi = max(maxi, j-i+1);
            }
        }
        return maxi;
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

    three.left=&four;
    three.right=&five;

    four.left=&eight;

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


