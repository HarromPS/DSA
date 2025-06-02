#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
A BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Solutoin=>

In a BST its all left are smaller than root node and all right is greater
So we need sorted nodes 

left < node < right => check for correct inorder traversal

*/
typedef struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
}TreeNode;

class Solution
{
    public:
    int heightOfTree(TreeNode* root){
        if(root!=NULL){
            return max(heightOfTree(root->left), heightOfTree(root->right))+1;
        }
        return 0;
    }

    TreeNode* constructTree(vector<int>& arr,int low,int high){
        TreeNode* newNode = NULL;
        if(low<=high){
            int mid = (low+high)/2;
            newNode = (TreeNode*)malloc(sizeof(TreeNode));
            newNode->data = arr[mid];
            newNode->left = constructTree(arr,low,mid-1);
            newNode->right = constructTree(arr,mid+1,high);
        }
        return newNode;
    }

    void inOrder(TreeNode* root,vector<int>& v){
        if(root==NULL){
            return;
        }
        
        inOrder(root->left,v);
        v.push_back(root->data);
        inOrder(root->right,v);
    }

    bool isBST(TreeNode* root) {
        vector<int> v;
        inOrder(root,v);
        
        // in a bast its all left are smaller than root node and all right is greater
        // so we need sorted nodes 
        for(int i=1;i<v.size();i++){
            if(v[i] <= v[i-1]){     // invalid condition
                return false;
            }
        }
        return true;
    }

};

void solve()
{
    // get the nodes 
    vector<int> arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int r=0;
        cin>>r;
        arr.push_back(r);
    }

    Solution s;

    TreeNode* root = s.constructTree(arr,0,arr.size()-1);

    // Check if a tree is BST
    bool ans=s.isBST(root);
    cout<<"IS BST:"<<ans<<endl;
}
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
