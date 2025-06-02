#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

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
    vector<vector<int>> zigzagLevelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue<Node*> q;
        q.push(root);

        int flag=0; // 0 ->left to right, 1->right to left
        while(!q.empty()){
            vector<Node*> temp;
            while(!q.empty()){
                temp.push_back(q.front());
                q.pop();
            }
            int n = temp.size();

            vector<int> res;
            for(int i=0;i<n;i++){
                if(temp[i]->left!=nullptr) q.push(temp[i]->left);
                if(temp[i]->right!=nullptr) q.push(temp[i]->right);
                if(flag==0){
                    res.push_back(temp[i]->data);
                }else{
                    res.push_back(temp[n-i-1]->data);
                }
            }
            flag^=1;
            ans.push_back(res);
        }

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

    vector<vector<int>> ans = s.zigzagLevelOrder(&root);
    for(auto iter:ans){
        for(auto it:iter){
            cout<<it<<" ";
        }
        cout<<endl;
    }
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


