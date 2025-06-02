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
    void ZigZagTree(Node* node){
        // using bfs traversal i.e queue ds 
        queue<Node*> q;
        vector<vector<int>> ans;
        q.push(node);

        int flag = 1;   // right to left 
        while(!q.empty()){
            vector<Node*> temp;
            while(!q.empty()){
                temp.push_back(q.front());
                q.pop();
            }

            // zig zag, left to right, right to left 
            flag^=1;
            vector<int> res;
            for(int i=0;i<temp.size();i++){
                if(flag==0){    // left to right 
                    res.push_back(temp[i]->data);
                }
                else{
                    res.push_back(temp[temp.size()-i-1]->data);
                }
                if(temp[i]->left!=nullptr) q.push(temp[i]->left);
                if(temp[i]->right!=nullptr) q.push(temp[i]->right);
            }
            ans.push_back(res);
        }
        for(auto it:ans){
            for(auto iter:it){
                cout<<iter<<" ";
            }
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
    root.right = &seven;

    two.left=&three;
    two.right=&four;
    four.left=&five;
    four.right=&six;

    Solution s;
    s.ZigZagTree(&root);

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


