


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.
Input:
target node = 50
k = 2 (dist)
Binary tree
       50
      /  \
     7     2
    / \   / \
    3  5 1  30

output: [3, 5, 1, 30]

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
    void printTree(Node* node){
        if(node==nullptr) return;
        cout<<node->data<<" ";
        printTree(node->left);
        printTree(node->right);
    }

    vector<int> distanceK(Node* root, Node* target, int k) {
        // 1. parent pointers
        // 2. move 1 dist in all directions & mark visited 
        // 3. if dist==k add it to ans and return back

        queue<Node*> q; // queue 
        map<Node*, Node*> parentMap;   // node parent

        // add root to map and queue 
        parentMap[root] = nullptr;    // no parent
        q.push(root);
        while(!q.empty()){
            Node* n = q.front();
            q.pop();

            // add parents 
            if(n->left!=nullptr){
                parentMap[n->left] = n;
                q.push(n->left);
            }
            if(n->right!=nullptr){
                parentMap[n->right]=n;
                q.push(n->right);
            }
        }
        vector<int> ans;

        // start from target node and move 1 distance 
        map<Node*, bool> visitedSet;   // visited node
        queue<pair<Node*, int>> q2; // node distance 
        q2.push({target,0}); // 0 distance 
        while(!q2.empty()){
            Node* n = q2.front().first;
            int dist = q2.front().second;
            visitedSet[n]=true;   // add it to set
            q2.pop();

            // if distance reached 
            if(dist == k){
                ans.push_back(n->data);
                continue;
            }

            // parent exists and not visited
            if(parentMap.find(n)!=parentMap.end() && parentMap[n]!=nullptr && visitedSet[parentMap[n]]==false){
                q2.push({parentMap[n], dist+1});
            }
            // left and right child 
            if(n->left!=nullptr && visitedSet[n->left]==false){
                q2.push({n->left, dist+1});
            }
            if(n->right!=nullptr && visitedSet[n->right]==false){
                q2.push({n->right, dist+1});
            }
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
    Node root(3);
    Node two(5);
    Node three(1);
    Node four(6);
    Node five(2);
    Node six(0);
    Node seven(8);
    Node eight(7);
    Node nine(4);

    root.left = &two;
    root.right = &three;

    two.left=&four;
    two.right=&five;

    three.left=&six;
    three.right=&seven;

    five.left=&eight;
    five.right=&nine;

    Solution s;

    vector<int> ans=s.distanceK(&root, &two, 2);
    for(auto it:ans) cout<<it<<" ";
    cout<<endl;
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


