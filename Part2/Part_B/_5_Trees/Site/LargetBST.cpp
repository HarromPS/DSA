#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

typedef struct Node
{
    int data;
    Node *left;
    Node *right;
}Node;

class Solution{
    public:

    int heightOfTree(Node* root){
        if(root!=NULL){
            return max(heightOfTree(root->left), heightOfTree(root->right))+1;
        }
        return 0;
    }

    Node* constructTree(vector<int>& arr,int low,int high){
        Node* newNode = NULL;
        if(low<=high){
            int mid = (low+high)/2;
            newNode = (Node*)malloc(sizeof(Node));
            newNode->data = arr[mid];
            newNode->left = constructTree(arr,low,mid-1);
            newNode->right = constructTree(arr,mid+1,high);
        }
        return newNode;
    }


    vector<int> solve(Node *root){
        //{//size,TF,mini,maxi} left max<node<right min
        if(root == NULL){//null
            return {0,1,INT_MAX,INT_MIN};
        }
        {
            if(root->left==NULL && root->right==NULL){//leaf node 

                // size 1, true it is a bst, left max, right min is root itself
                return {1,1,root->data,root->data};
            }
            vector<int>left=solve(root->left);
            vector<int>right=solve(root->right);
            
            int leftsize=left[0],LTF=left[1],leftmini=left[2],leftmaxi=left[3];
            int rightsize=right[0],RTF=right[1],rightmini=right[2],rightmaxi=right[3];
            if(LTF ==1 && RTF==1 && leftmaxi < root->data && root->data < rightmini){
                return {leftsize+rightsize+1,1,min(root->data,leftmini),max(root->data,rightmaxi)};
            }
            else{
                return {max(leftsize,rightsize),0,0,0}; // if below subtree is not a bst, then above tree is also not a bst
            }
        }
    }
    
    int largestBst(Node *root)
    {
    	//codeGenius
    	return solve(root)[0];
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

    Node* root = s.constructTree(arr,0,arr.size()-1);
    int ans = s.largestBst(root);
    cout<<"Larget BST: "<<ans<<endl;

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
