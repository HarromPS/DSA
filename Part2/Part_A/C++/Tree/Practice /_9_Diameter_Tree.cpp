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
    // get diameter of a tree 
    // find extreme left and right height, and sum up them

    int getAns(Node* root,int* ans){   // height function
        if(root==nullptr) return 0; 

        int extremeLeft = getAns(root->left,ans);
        int extremeRight = getAns(root->right,ans);

        *ans = max(*ans, extremeLeft+extremeRight);

        return 1+max(extremeLeft,extremeRight);
    }   

    int getDiamter(Node* root){
        int ans = 0;
        getAns(root,&ans);
        return ans;
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
    Node three(3);
    Node four(4);
    Node five(5);
    Node six(6);
    Node seven(7);
    // Node eight(8);

    root.left = &two;
    root.right = &seven;

    two.left=&three;
    two.right=&four;
    four.left=&five;
    four.right=&six;

    // root.left = &two;
    // root.right = &five;

    // two.left=&three;
    // two.right=&four;

    // five.left=&six;
    // five.right=&seven;

    Solution s;
    int res = s.getDiamter(&root);
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


