#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

/*
Given a BST and a number X, find Ceil of X.
Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.

If Ceil could not be found, return -1.

      5
    /   \
   1     7
    \
     2 
      \
       3

X = 3
We find 3 in BST, so ceil of 3 is 3.


X = 6
     10
    /  \
   5    11
  / \ 
 4   7
      \
       8

Output: 7
Explanation: We find 7 in BST, so ceil of 6 is 7.
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
    int findCeil(Node* root,int key) {
        int ans = INT_MAX;
        Node* node=root;
        while(node!=nullptr){
            if(node->data == key){
                ans = node->data;
                return ans;
            }
            if(key < node->data){
                // chances of node being ceil of key
                ans = min(ans,node->data);
                node=node->left;
            }else{
                // no chance of node to be ceil of key
                node=node->right;   
            }
        }
        return ans==INT_MAX?-1:ans;
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
    int res=s.findCeil(&root,15);
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
