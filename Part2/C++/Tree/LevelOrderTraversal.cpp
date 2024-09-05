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
    //Function to return the level order traversal of a tree.
    void getLevelOrderTraversal(vector<int>& arr,TreeNode* root,int level){
        if(root==NULL){
            return;
        }else if(level==1){
            arr.push_back(root->data);
        }else if(level>1){
            getLevelOrderTraversal(arr,root->left,level-1);
            getLevelOrderTraversal(arr,root->right,level-1);
        }
    }
    vector<int> levelOrder(TreeNode* root)
    {
      //Your code here
      vector<int> ans;
      int h = heightOfTree(root);
      for(int i=1;i<=h;i++){
          getLevelOrderTraversal(ans,root,i);
      }
      return ans;
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

    vector<int> levelOrderArray = s.levelOrder(root);
    for(int i=0;i<levelOrderArray.size();i++){
        cout<<levelOrderArray[i]<<" ";
    }
    cout<<endl;
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
