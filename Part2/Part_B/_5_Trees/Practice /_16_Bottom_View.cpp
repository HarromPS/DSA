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
    void TopView(Node* root){
        // go level wise, as if using recursive algo, we can lost imp results 
        // done using queue 
        queue<pair<Node*,int>> q;   // node, vertical 
        map<int,int> mp;

        // add root node to queue
        q.push({root,0}); // rootnode, vertical 0

        while(!q.empty()){
            Node* n = q.front().first;
            int vertical = q.front().second;
            q.pop();

            // update verticals, to let it go deep down
            mp[vertical] = n->data;
            // go to next level 
            if(n->left!=nullptr){
                q.push({n->left,vertical-1});
            }
            if(n->right!=nullptr){
                q.push({n->right,vertical+1});
            }
        }

        vector<int> ans;    
        for(auto& verticals: mp){
            ans.push_back(verticals.second);
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
            cout<<it<<" ";
        }
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
    s.TopView(&root);

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


