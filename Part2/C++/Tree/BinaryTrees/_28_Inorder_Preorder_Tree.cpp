


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
    
    Node* buildTree(vector<int>& inorder, vector<int>& preorder){
        int n=inorder.size();
        // hashmap for inorder 
        map<int,int> inHash;
        for(int i=0;i<n;i++){
            inHash[inorder[i]]=i;
        }
        int instart=0, inend=n-1;
        int prestart=0, preend=n-1;
        return buildTreeInPre(inorder,instart,inend,inHash,preorder,prestart,preend);
    }

    Node* buildTreeInPre(vector<int>& inorder, int instart,int inend, map<int,int>& inHash, vector<int>& preorder, int prestart,int preend){
        // base condition 
        if(instart > inend || prestart>preend){
            return nullptr;
        }


        // root node for this level 
        Node* node = new Node(preorder[prestart]);

        int inRoot = inHash[preorder[prestart]];
        int numsLeft = inRoot - instart;

        node->left = buildTreeInPre(inorder, instart, inRoot-1, inHash, preorder, prestart+1, prestart+numsLeft);

        node->right = buildTreeInPre(inorder, inRoot+1, inend, inHash, preorder, prestart+1+numsLeft, preend);

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
    vector<int> inorder, preorder;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int inIp, preIp;
        cin>>inIp>>preIp;
        preorder.push_back(inIp);
        inorder.push_back(preIp);
    }

    Solution s;

    Node* ans=s.buildTree(inorder,preorder);
    s.printTree(ans);
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
    solve();
    return 0;
}
