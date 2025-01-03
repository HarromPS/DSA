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
    // using recursive solutions
    // TC:O(N) SC:O(height)
    int heightOfTreeRecursive(Node* root){
        if(root==nullptr) return 0;

        int leftHeight = heightOfTreeRecursive(root->left);
        int rightHeight = heightOfTreeRecursive(root->right);

        return (1 + max(leftHeight, rightHeight));    // 1 for current node
    }
    
    int heightOfLevelOrder(Node* root){
        // if empty tree
        if(root==nullptr){
            return 0;
        }
        int height=1;   // so at least height is 1

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            vector<Node*> temp;
            while(!q.empty()){
                temp.push_back(q.front());
                q.pop();
            }
            int flag=0;
            for(auto it:temp){
                if(it->left!=nullptr){
                    q.push(it->left); 
                    flag=1; 
                }
                if(it->right!=nullptr){
                    q.push(it->right);
                    flag=1;
                }
            }
            if(flag==1) height++;
        }
        return height;
    }
};

/*
          1
       /    \
      2      5
     /  \   /  \
     3  4   6   7

*/
void solve(){
    Node root(1);
    Node two(2);
    Node three(3);
    Node four(4);
    Node five(5);
    Node six(6);
    Node seven(7);

    root.left = &two;
    root.right = &five;

    two.left=&three;
    two.right=&four;

    five.left=&six;
    five.right=&seven;

    Solution s;

    int ans = s.heightOfTreeRecursive(&root);
    cout<<"Height: "<<ans<<endl;

    ans = s.heightOfLevelOrder(&root);
    cout<<"Height: "<<ans<<endl;
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


