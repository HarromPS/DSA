


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given a binary tree and a node data called target. 
Find the minimum time required to burn the complete binary tree if the target is set on fire. 
It is known that in 1 second all nodes connected to a given node get burned. 
That is its left child, right child, and parent.
Note: The tree contains unique values.
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

    Node* preorder(Node* node, int t){
        if(node==nullptr) return nullptr;
        if(node->data == t) {
            return node;
        }

        Node* left=preorder(node->left, t);
        Node* right=preorder(node->right, t);

        if(left==nullptr) return right;
        return left;
    }

    int minTime(Node* root, int t) {
        // 1. get the target node address 
        // 2. get the parent pointers 
        // 3. traverse in all directions and get max dist from target node => min time to burn complete tree

        Node* target=preorder(root,t);

        map<Node*, Node*> parentMap;
        queue<Node*> q;
        
        // add root node to queue and parentmap
        parentMap[root] = nullptr;  // no parent
        q.push(root);
        while(!q.empty()){
            Node* n=q.front();
            q.pop();

            if(n->left!=nullptr){
                parentMap[n->left]=n;
                q.push(n->left);
            }
            if(n->right!=nullptr){
                parentMap[n->right]=n;
                q.push(n->right);
            }
        }

        int ans=0;
        map<Node*,bool> visitedSet;
        queue<pair<Node*,int>> q2;
        q2.push({target, 0});   // target node at dist 0
        while(!q2.empty()){
            Node* n=q2.front().first;
            int dist=q2.front().second;
            visitedSet[n]=true;
            q2.pop();

            // parent exists and not visited 
            if(parentMap.find(n)!=parentMap.end() && parentMap[n]!=nullptr && visitedSet[parentMap[n]]==false){
                q2.push({parentMap[n], dist+1});    // add parent to queue
            }
            // left and right child
            if(n->left!=nullptr && visitedSet[n->left]==false){
                q2.push({n->left, dist+1});
            }
            if(n->right!=nullptr && visitedSet[n->right]==false){
                q2.push({n->right, dist+1});
            }
            ans=max(ans,dist);
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

    int ans=s.minTime(&root, 5);
    cout<<ans<<endl;
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


