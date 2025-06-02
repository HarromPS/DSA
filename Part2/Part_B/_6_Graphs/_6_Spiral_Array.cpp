#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Spirally traversing a matrix

You are given a rectangular matrix, and your task is to return an array while traversing the matrix in spiral form.

Examples:

4 4

1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 

*/

class Node{
public: 
    int i;
    int j;
    int color;
    Node(int _i,int _j,int _color){
        this->i = _i;
        this->j = _j;
        this->color = _color;
    }

    Node(){}
};

class Solution
{
public:
    void dfs(int i,int j,vector<vector<int>>& matrix,vector<int> &ans,vector<vector<int>>& visited,int direction,int m,int n){
        // Check if out of bounds or already visited
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] == 1) {
            return;
        }

        // Mark current cell as visited and add to answer
        visited[i][j] = 1;
        ans.push_back(matrix[i][j]);

        // Determine the next direction based on the current direction and boundary/visited status
        if (direction == 1) { // Right
            if (j + 1 < n && visited[i][j + 1] == 0) {
                dfs(i, j + 1, matrix, ans, visited, 1, m, n);
            } else {
                dfs(i + 1, j, matrix, ans, visited, 2, m, n); // Change direction to Down
            }
        } else if (direction == 2) { // Down
            if (i + 1 < m && visited[i + 1][j] == 0) {
                dfs(i + 1, j, matrix, ans, visited, 2, m, n);
            } else {
                dfs(i, j - 1, matrix, ans, visited, 3, m, n); // Change direction to Left
            }
        } else if (direction == 3) { // Left
            if (j - 1 >= 0 && visited[i][j - 1] == 0) {
                dfs(i, j - 1, matrix, ans, visited, 3, m, n);
            } else {
                dfs(i - 1, j, matrix, ans, visited, 4, m, n); // Change direction to Up
            }
        } else if (direction == 4) { // Up
            if (i - 1 >= 0 && visited[i - 1][j] == 0) {
                dfs(i - 1, j, matrix, ans, visited, 4, m, n);
            } else {
                dfs(i, j + 1, matrix, ans, visited, 1, m, n); // Change direction to Right
            }
        }
    }

    void Spiral_Matrix(int m,int n,vector<vector<int>>& matrix){
        vector<int> ans;
        vector<vector<int>> visited(m, vector<int>(n,0));

        // starting from 0,0 index
        dfs(0,0,matrix,ans,visited,1,m,n);    // start by going right 
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        // return ans;
    }
};

void solve()
{
    // grid
    int m;
    int n;
    cin >> m >> n;
    vector<vector<int>> matrix(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }

    Solution s;
    s.Spiral_Matrix(m, n, matrix);
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
