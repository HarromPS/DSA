#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// https://www.youtube.com/watch?v=Pf0K7t8vuGE

/*
Given a Binary Tree and an integer target. Find all the ancestors of the given target.

Note:

The ancestor of node x is node y, which is at the upper level of node x, and x is directly connected with node y. 
Consider multiple levels of ancestors to solve this problem.
In case there are no ancestors available, return an empty list.

    Input:
         1
       /   \
      2     3
    /  \    /  \
   4   5  6     8
  /
 7

target = 7
Output: [4 2 1]
Explanation: The given target is 7, if we go above the level of node 7, then we find 4, 2 and 1. Hence the ancestors of node 7 are 4 2 and 1

 */
void solve()
{
    // int 
}
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
