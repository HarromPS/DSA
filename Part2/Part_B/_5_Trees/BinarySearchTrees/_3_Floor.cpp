#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

/*
You are given a BST(Binary Search Tree) with n number of nodes and value x. 
Your task is to find the greatest value node of the BST which is smaller than or equal to x.
Note: when x is smaller than the smallest node of BST then returns -1.

      5
    /   \
   1     7
    \
     2 
      \
       3

X = 3
We find 3 in BST, so ceil of 3 is 2.


X = 6
     10
    /  \
   5    11
  / \ 
 4   7
      \
       8

Output: 5
Explanation: We find 5 in BST, so ceil of 6 is 5.
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
    int findFloor(Node* root,int key) {
        int ans = INT_MIN;
        Node* node=root;
        while(node!=nullptr){
            if(node->data == key){
                ans = node->data;
                return ans;
            }
            if(node->data < key){
                // chances of node being ceil of key
                ans = max(ans,node->data);
                node=node->right;
            }else{
                // no chance of node to be ceil of key
                node=node->left;   
            }
        }
        return ans==INT_MIN?-1:ans;
    }
};

/*
        1
       /  \
      2    2
     / \  / \
    3   4 4  3
       /  \ 
       5   5

*/
void solve(){
    Node root(10);
    Node two(5);
    Node three(13);
    Node four(3);
    Node five(6);
    Node six(11);
    Node seven(14);
    Node eight(2);
    Node nine(4);
    Node ten(9);

    root.left = &two;
    root.right = &three;

    two.left=&four;
    two.right=&five;

    three.left=&six;
    three.right=&seven;

    four.left=&eight;
    four.right=&nine;

    five.right=&ten;

    Solution s;
    int res=s.findFloor(&root,12);
    cout<<res<<endl;
    
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
    solve();
    return 0;
}
