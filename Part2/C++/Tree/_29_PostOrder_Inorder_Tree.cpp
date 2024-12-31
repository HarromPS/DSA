


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

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
    
    Node* buildTree(vector<int>& inorder, vector<int>& postorder){
        int n=inorder.size();
        // hashmap for inorder 
        map<int,int> inHash;
        for(int i=0;i<n;i++){
            inHash[inorder[i]]=i;
        }

        int instart=0, inend=n-1;       // left root right
        int poststart=n-1, postend=0;   // left right root
        return buildTreeInPre(inorder,instart,inend,inHash,postorder,poststart,postend);
    }

    Node* buildTreeInPre(vector<int>& inorder, int instart,int inend, map<int,int>& inHash, vector<int>& postorder, int poststart,int postend){
        // base condition 
        if(instart > inend || poststart < postend){
            return nullptr;
        }
        // root node for this level 
        Node* node = new Node(postorder[poststart]);

        int inRoot = inHash[postorder[poststart]];
        int numsRight = inend - inRoot;

        node->right = buildTreeInPre(inorder, inRoot + 1, inend, inHash, postorder, poststart - 1, poststart - numsRight);
        
        node->left = buildTreeInPre(inorder, instart, inRoot - 1, inHash, postorder, poststart - numsRight - 1, postend);
        return node;
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
    vector<int> inorder, postorder;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int inIp, postIp;
        cin>>inIp>>postIp;
        inorder.push_back(inIp);
        postorder.push_back(postIp);
    }
    Solution s;

    Node* ans=s.buildTree(inorder,postorder);
    s.printTree(ans);
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
    solve();
    return 0;
}
