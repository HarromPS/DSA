#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given an array, arr. The task is to find the largest element in it.

Examples:

Input: arr = [1, 8, 7, 56, 90]
Output: 90
Explanation: The largest element of the given array is 90.

*/

class Solution {
public:
    int largest(vector<int> &arr) {
        // code here
        int largestElement=0;
        return largestElement;
    }
};

void solve(){
    int n;  // number of rows
    int m;  // number of cols 
    cin>>n>>m;

    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int ip;
            cin>>ip;
            grid[i][j]=ip;
        }
    }   
    
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


