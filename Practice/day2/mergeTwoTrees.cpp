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

class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *r1, TreeNode *r2)
    {
        if (r1 == NULL)
        {
            return r2;
        }
        else if (r2 == NULL)
        {
            return r1;
        }

        // TreeNode* newNode=(TreeNode*)malloc(sizeof(TreeNode)*1);
        // newNode->val=r1->val+r2->val;

        // newNode->left=mergeTrees(r1->left,r2->left);
        // newNode->right=mergeTrees(r1->right,r2->right);

        r1->val += r2->val;
        r1->left = mergeTrees(r1->left, r2->left);
        r1->right = mergeTrees(r1->right, r2->right);
        return r1;
    }
};
int main()
{

    return 0;
}
