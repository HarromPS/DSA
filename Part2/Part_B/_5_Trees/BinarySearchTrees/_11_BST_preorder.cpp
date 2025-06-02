#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

/*
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.
Input:
N = 5
arr[]  = {40,30,35,80,100}
Output: 35 30 100 80 40
Explanation: PreOrder: 40 30 35 80 100
Therefore, the BST will be:
              40
           /      \
         30       80
           \        \   
           35      100

inorder: 30 35 40 80 100
Hence, the postOrder traversal will
be: 35 30 100 80 40
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
    void preorderTraversal(Node* node){
        if(node==nullptr) return ;
        cout<<node->data<<" ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    Node* insertBST(Node* root,int val){
        Node* curr=root;
        while(curr!=nullptr){
            if(val<curr->data){
                if(curr->left == nullptr){
                    curr->left = new Node(val);
                    break;
                }else{
                    curr=curr->left;
                }
            }
            else if(val > curr->data){
                if(curr->right == nullptr){
                    curr->right = new Node(val);
                    break;
                }else{
                    curr = curr->right;
                }
            }
        }
        return root;
    }

    // TC:O(n)*O(N) SC:O(1)
    Node* bstFromPreorderBrute(vector<int>& preorder) {
        int n=preorder.size();
        if(n==0) return nullptr;
        Node* root = new Node(preorder[0]);   // root node
        for(int i=1;i<n;i++){
            root = insertBST(root,preorder[i]);
        }
        return root;
    }

    Node* buildTree(vector<int>& inorder,int instart, int inend, map<int,int>& inMap,vector<int>& preorder,int prestart,int preend){
        // base condition 
        if(instart > inend || prestart > preend){
            return nullptr;
        }

        Node* node = new Node(preorder[prestart]);
        int inRoot = inMap[preorder[prestart]];
        int numsLeft = inRoot - instart;

        node->left = buildTree(inorder,instart,inRoot-1, inMap, preorder, prestart+1, prestart+numsLeft);

        node->right = buildTree(inorder,inRoot+1, inend, inMap, preorder, prestart+1+numsLeft, preend);

        return node;
    }

    // TC:O(n log n) + O(n) SC:O(n)
    Node* bstFromPreorderBetter(vector<int>& preorder){
        // unique BST from preorder and inorder traveral
        vector<int> inorder(preorder);
        sort(inorder.begin(),inorder.end());

        // do a hash map of inorder traversal 
        map<int,int> inMap;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]]=i;
        }
        return buildTree(inorder,0,inorder.size()-1, inMap, preorder, 0, preorder.size()-1);
    }

    Node* solution(vector<int>& preorder, long upperBound){
        // base case 
        if(ind >= preorder.size() || preorder[ind] > upperBound){
            return nullptr;
        }

        // check range
        Node* root = new Node(preorder[ind]);
        ind++;
        root->left = solution(preorder, root->data);
        root->right = solution(preorder, upperBound);
        return root;
    }

    int ind=0;  // global index 
    Node* bstFromPreorderOptimal(vector<int>& preorder){
        return solution(preorder,LLONG_MAX);
    }
    
};

void solve(){
    
    int n;
    cin>>n;
    vector<int> preorder(n,0);
    for(int i=0;i<n;i++){
        cin>>preorder[i];
    }

    Solution s;
    // Node* res =s.bstFromPreorderBrute(preorder);
    // s.preorderTraversal(res);
    // Node* res =s.bstFromPreorderBetter(preorder);
    // s.preorderTraversal(res);
    Node* res =s.bstFromPreorderOptimal(preorder);
    s.preorderTraversal(res);
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
    int t;
    cin>>t;
    while(t--){
    solve();
        
    }
    return 0;
}


