#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given a matrix mat of size N x M where every element is either 'O' or 'X'. 
Replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.

A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, 
just above, just left and just right of it.

Input: 
n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: 
ans = {{'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}

*/


class Solution{
public:
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& visited,int m,int n){
        // mark as visited & not to be converted 
        visited[i][j]=2;

        // go to all 4 directions
        int drow[] = {-1,1,0,0};
        int dcol[] = {0,0,1,-1};
        for(int l=0;l<4;l++){
            int nrow = i + drow[l];
            int ncol = j + dcol[l];
            // boundaries

            // if not visited and connected with a edged 'O' then do not convert
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]=='O' && visited[nrow][ncol]!=2){
                dfs(nrow,ncol,grid,visited,m,n);
            }
        }

    }


    void fill(vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        // not intimating with given data, so visited array for it 
        vector<vector<int>> visited(m,vector<int>(n,0));

        // find edge 'O's which are not completely surrounded by all sides with 'X'
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // check only boundaries 
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    // check if its a 'O
                    if(grid[i][j]=='O'){
                        dfs(i,j,grid,visited,m,n);      
                    }
                }
            }
        }

        // conversion

        for(int  i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='O' && visited[i][j]!=2){    // if is 'O and is not on edge and a part of group of such, then convert
                    grid[i][j]='X';
                }
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

void solve()
{
    // grid
    int m;  // edges
    int n;  // nodes
    cin >> m >> n;

    // cout<<m<<" "<<n<<endl;

    // Adjancency List
    vector<vector<char>> grid(m,vector<char>(n,0));
    for(int u=0;u<m;u++){
        for(int v=0;v<n;v++){
            char ip;
            cin>>ip;
            grid[u][v] = ip;
        }
    }

    Solution s;
    s.fill(grid);
    
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