#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given the root of a binary tree, 
check whether it is a mirror of itself (i.e., symmetric around its center).

        1
       /  \
      2    2
     / \  / \
    3   4 4  3
       /  \ 
       5   5

Yes
        1
       /  \
      2    2
     / \  / \
    3   4 3  4
       /     / 
       8     8

No

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
    bool traversal(Node* p,Node* q){
        if(p==nullptr || q==nullptr){
            if(p==q) return true;
            return false;
        }

        if(p->data != q->data) return false;

        // in mirror, left = right and vice versa
        bool l = traversal(p->left,q->right);
        bool r = traversal(p->right,q->left);

        return l&&r;
    }

    bool isSymmetric(Node* root) {
        if(root==nullptr) return true;
        Node* p = root->left;
        Node* q = root->right;
        return traversal(p,q);
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
    Node root(1);
    Node two_1(2);
    Node two_2(2);
    Node three_1(3);
    Node three_2(3);
    Node four_1(4);
    Node four_2(4);
    Node five_1(5);
    Node five_2(6);

    root.left = &two_1;
    root.right = &two_2;

    two_1.left=&three_1;
    two_1.right=&four_1;
    two_2.left=&four_2;
    two_2.right=&three_2;

    four_1.left=&five_1;
    four_2.right=&five_2;
    Solution s;

    bool ans = s.isSymmetric(&root);
    cout<<ans<<endl;
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
    // cin>>test;
    // while(test--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}


