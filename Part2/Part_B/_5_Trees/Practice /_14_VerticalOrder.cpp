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
    void VerticalOrder(Node* root){
        // same line same position 
        // done using queue 
        queue<pair<Node*,pair<int,int>>> q; // {node, {vertical, level}}

        // Note: multiset sorts the nodes inserted 
        // map<int, map<int, multiset<int>>> mp;   // {vertical, {level, array of vertical order nodes }

        map<int, map<int, vector<int>>> mp;

        // add root node to queue
        q.push({root,{0,1}}); // rootnode, vertical 0, level 1

        while(!q.empty()){
            Node* n = q.front().first;
            int vertical = q.front().second.first;
            int level = q.front().second.second;
            q.pop();

            // add it to map 
            mp[vertical][level].push_back(n->data);

            // go to next level 
            if(n->left!=nullptr){
                q.push({n->left,{vertical-1, level+1}});
            }
            if(n->right!=nullptr){
                q.push({n->right,{vertical+1, level+1}});
            }
        }

        vector<vector<int>> ans;    
        for(auto& verticals: mp){
            auto& vertical = verticals.first; // int 
            auto& innerMap = verticals.second;  // multimap 

            vector<int> res;    // to get the vertical order nodes for each vertical 
            for(auto& level: innerMap){
                for(auto& nodes: level.second){
                    res.push_back(nodes);
                }
            }
            ans.push_back(res);
        }

        /*
        for(auto& it: mp){
            auto& v = it.first;
            auto& inner_map = it.second;
            vector<int> res;
            for(auto& items: inner_map){
                // insert it to ans
                res.insert(res.end(), items.second.begin(), items.second.end());
            }
            ans.push_back(res);
        }
         */

        for(auto it:ans){
            for(auto iter: it) cout<<iter<<" ";
            cout<<endl;
        }
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
    s.VerticalOrder(&root);

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


