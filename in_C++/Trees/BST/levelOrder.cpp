#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    public:
    int heightOfTree(Node* root){
        if(root!=NULL){
            return max(heightOfTree(root->left), heightOfTree(root->right))+1;
        }
        return 0;
    }
    //Function to return the level order traversal of a tree.
    void getLevelOrderTraversal(vector<int>& arr,Node* root,int level){
        if(root==NULL){
            return;
        }else if(level==1){
            arr.push_back(root->data);
        }else if(level>1){
            getLevelOrderTraversal(arr,root->left,level-1);
            getLevelOrderTraversal(arr,root->right,level-1);
        }
    }
    vector<int> levelOrder(Node* root)
    {
      //Your code here
      vector<int> ans;
      int h = heightOfTree(root);
      for(int i=1;i<=h;i++){
          getLevelOrderTraversal(ans,root,i);
      }
      return ans;
    }
};


void solve()
{
    
}
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    ll test;
    cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
