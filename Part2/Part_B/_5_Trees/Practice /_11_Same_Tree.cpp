#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Tree - non linear data structure
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
    bool isSameTree(Node* node1, Node* node2){
        if(node1==nullptr || node2==nullptr){
            if(node1==node2) return true;
            return false;
        }

        if(node1->data != node2->data) return false;
        return isSameTree(node1->left,node2->left) && isSameTree(node1->right,node2->right);
    }

    void preOrder(Node* root,string& s){
        if(root==nullptr) {
            s+="N";
            return;
        }

        s+=(root->data);
        preOrder(root->left,s);
        preOrder(root->right,s);
    }

    bool isSameTreeString(Node* node1,Node* node2){
        string s1="",s2="";
        preOrder(node1,s1);
        preOrder(node2,s2);
        if(s1!=s2) return false;
        return true;
    }
};

/*
        1
       /  \
      2    7
     /  \
     3  4
       /  \
       5   6

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
    // three.left = &two; // true

    Solution s;
    bool res = s.isSameTree(&root,&three);
    cout<<res<<endl;
    res = s.isSameTreeString(&root,&three);
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

    // ll test;
    // cin>>test;
    // while(test--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}


