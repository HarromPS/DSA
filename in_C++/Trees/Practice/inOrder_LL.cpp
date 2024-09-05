#include <iostream>
#include <cstdio>
using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
} TreeNode;

// Time complexity: O(n)
// Space complexity: Auxillary space O(n)
class Solution
{
public:
    TreeNode*  inOrderLL(TreeNode *root)
    {
        if (root == NULL)
        {
            return root;
        }
        TreeNode *left = inOrderLL(root->left);
        cout<<root->val<<" ";
        root->left=NULL;
        TreeNode* temp=NULL;
        if(left!=NULL){
            temp=left;
            while(temp!=NULL && temp->right!=NULL){
                temp=temp->right;
            }
            if(temp!=NULL){
                temp->right=root;
                temp=temp->right;
            }
            else {
                left->left=root;
            }
            root=left;
        }
        if(temp==NULL){
            root->right=inOrderLL(root->right);
        }
        else {
            temp->right=inOrderLL(temp->right);
        }
        return root;
    }
    TreeNode *increasingBST(TreeNode *root)
    {
        root=inOrderLL(root);
        return root;
    }
};
int main()
{

    return 0;
}