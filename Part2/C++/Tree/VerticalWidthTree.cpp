#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given a Binary Tree. You need to find and return the vertical width of the tree.
Input:

         1
       /    \
      2      3
     / \    /  \
    4   5  6   7
            \   \
             8   9
Output: 6
Explanation: The width of a binary tree is
the number of vertical paths in that tree.

line crosses
4   2   1   (3,8 )    7    9

The above tree contains 6 vertical lines.1
 */

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *getNode(int n)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = n;
    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
}

class Solution
{

public:
    int maxLeftDistance = (int)(1e8);
    int maxRightDistance = (int)(-1e8);

    void solve(Node *root, int n)
    {
        // base case
        if (root == NULL)
        {
            maxLeftDistance = min(maxLeftDistance, n);
            maxRightDistance = max(maxRightDistance, n);
            return;
        };

        // recurrence relation
        solve(root->left, n - 1);
        solve(root->right, n + 1);
    }

    int verticalWidth(Node *root)
    {
        // code here.
        if (root == NULL)
            return 0;
        solve(root, 0);
        return abs(maxLeftDistance) + abs(maxRightDistance) - 1;
    }

    int heightOfTree(Node *root)
    {
        if (root != NULL)
        {
            return max(heightOfTree(root->left), heightOfTree(root->right)) + 1;
        }
        return 0;
    }

    Node *constructTree(vector<int> &arr, int low, int high)
    {
        Node *newNode = NULL;
        if (low <= high)
        {
            int mid = (low + high) / 2;
            newNode = (Node *)malloc(sizeof(Node));
            newNode->data = arr[mid];
            newNode->left = constructTree(arr, low, mid - 1);
            newNode->right = constructTree(arr, mid + 1, high);
        }
        return newNode;
    }
};
void solve()
{
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int r = 0;
        cin >> r;
        arr.push_back(r);
    }

    Solution s;
    Node *root = s.constructTree(arr, 0, arr.size() - 1);

    cout << s.verticalWidth(root);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    // ll test;
    // cin >> test;
    // while (test--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}
