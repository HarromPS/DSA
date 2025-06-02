#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

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
    Node* searchBST(Node* root, int val) {
        Node* node=root;
        while(node!=nullptr){
            if(node->data == val){
                return node;
            }
            if(val < node->data){
                node=node->left;
            }
            else{
                node=node->right;
            }
        }
        return node;
    }

    Node* searchBST_2(Node* root, int val) {
        Node* node=root;
        while(node!=nullptr && node->data!=val){
            node=val<node->data ? node->left:node->right;
        }
        return node;
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
    Node root(8);
    Node two(5);
    Node three(12);
    Node four(4);
    Node five(7);

    Node six(10);
    Node seven(14);
    Node eight(6);
    Node nine(13);

    root.left = &two;
    root.right = &three;

    two.left=&four;
    two.right=&five;

    three.left=&six;
    three.right=&seven;
    
    five.left=&eight;
    
    seven.left=&nine;

    Solution s;
    Node* res=s.searchBST(&root,4);
    cout<<res->data<<endl;
    res=s.searchBST_2(&root,4);
    cout<<res->data<<endl;
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
