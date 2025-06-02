#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

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

    void inOrder(TreeNode* root){
        // base case
        if(root==NULL){
            return;
        }

        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }

};

void solve()
{
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
    s.inOrder(root);
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
