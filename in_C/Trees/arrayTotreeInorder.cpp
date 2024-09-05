#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* solve(vector<int>& v,int low,int high){
        if(low>high){
            return NULL;
        }
        TreeNode* root = new TreeNode(v[(low+high)/2]);
        root->left = solve(v,low,((low+high)/2)-1);
        root->right = solve(v,((low+high)/2)+1,high);
        return root;
    }

    TreeNode* sortedListToBST(vector<int>& ans) {
        return NULL;
    }
};

int main(){

    return 0;
}