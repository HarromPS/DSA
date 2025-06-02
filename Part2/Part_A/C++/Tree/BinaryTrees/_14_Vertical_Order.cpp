#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions 
(row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each 
column index starting from the leftmost column and ending on the rightmost column. 
There may be multiple nodes in the same row and same column. In such a case, 
sort these nodes by their values.

Return the vertical order traversal of the binary tree.

Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.
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
    vector<vector<int>> verticalTraversal(Node* root) {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> nodes; // {vertical: {level: nodes}}
        queue<pair<Node*, pair<int, int>>> q; // {node, {vertical, level}}

        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            Node* node = p.first;
            // x = vertical , y=level
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node->data);

            if (node->left)
                q.push({node->left, {x - 1, y + 1}});   // left-1, level+1
            if (node->right)    
                q.push({node->right, {x + 1, y + 1}});  // right+1, l
        }

        for (auto& [_, vertical_map] : nodes) {
            vector<int> col;
            for (auto& [_, values] : vertical_map) {
                col.insert(col.end(), values.begin(), values.end());
            }
            ans.push_back(col);
        }

        return ans;
    }

    vector<vector<int>> verticalTraversal_2(Node* root) {
        vector<vector<int>> ans;    
        map<int, vector<int>> mp;   // mapping vertical, array of node values 
        queue<pair<Node*,int>> q;     // storing node,vertical 

        // add root 
        q.push({root, 0});
        while(!q.empty()){
            vector<pair<Node*,int>> temp;
            while(!q.empty()){
                temp.push_back(q.front());
                q.pop();
            }
            int n=temp.size();
            for(int i=0;i<n;i++){
                Node* n = temp[i].first;
                int v = temp[i].second;
                if(n->left!=nullptr) q.push({n->left,v-1});
                if(n->right!=nullptr) q.push({n->right,v+1});
                mp[v].push_back(n->data);
            }
        }

        // all the verticals are sorted already 
        for(auto it:mp){
            vector<int> res;
            for(int i=0;i<it.second.size();i++){
                res.push_back(it.second[i]);
            }
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

    vector<vector<int>> ans = s.verticalTraversal(&root);
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


