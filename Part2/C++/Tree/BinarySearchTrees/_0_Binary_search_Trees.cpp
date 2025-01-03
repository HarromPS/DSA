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
    Node two(2);
    Node three(3);
    Node four(4);
    Node five(5);

    Node six(6);
    Node seven(7);
    Node eight(8);
    Node nine(4);

    root.left = &two;
    root.right = &three;

    two.left=&four;
    two.right=&five;

    five.left=&six;
    five.right=&seven;

    Solution s;
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
    solve();
    return 0;
}
