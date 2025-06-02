#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in 
the sequence has an edge connecting them. A node can only appear in the sequence at most once. 
Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.


root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
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
    // way 1
    bool isSameTree_1(Node* p, Node* q) {
        if(p==nullptr || q==nullptr){
            if(p==q) return true;
            return false;
        }

        // if not same value 
        if(p->data != q->data) return false ;

        // left and right subtree 
        return isSameTree_1(p->left, q->left) && isSameTree_1(p->right, q->right);
    }


    // way 2
    void preorder(Node* root,string str){
        if(root==nullptr){
            str+="N";
            return; 
        }

        str+=root->data;
        preorder(root->left,str);
        preorder(root->right,str);
    }

    bool isSameTree(Node* p,Node* q){
        string s1,s2;
        preorder(p,s1);
        preorder(q,s2);
        return (s1==s2);
    }
};

/*
        1
       /  \
      2    3
        \
        4

*/
void solve(){
    Node root(1);
    Node two(2);
    Node three(1);

    // Node four(4);
    // Node five(5);
    // Node six(6);
    // Node seven(7);

    // root.left = &two;
    // root.right = &five;

    // two.left=&three;
    // two.right=&four;

    // five.left=&six;
    // five.right=&seven;

    root.left = &two;

    // three.right = &two; // false
    three.left = &two; // true

    Solution s;

    bool ans = s.isSameTree_1(&root,&three);
    cout<<ans<<endl;    // false
    ans = s.isSameTree_1(&root,&three);
    cout<<ans<<endl;    // false
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

    // ll test;
    // cin>>test;
    // while(test--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}


