#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally)
land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of
the grid in any number of moves.

SAME AS REPLACE O WITH X PROBLEM, WHERE W JUST REPLACED, HERE WE JUST HAVE TO COUNT
THE CELLS WHICH DOESN'T LEAD TO GO OFF BOUNDARY
Input: 
4 4 

0 0 0 0
1 0 1 0
0 1 1 0
0 0 0 0

Output: 
ans = 3 (1,2) (2,1) (2,2) 

*/


class Solution{
public:
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visited,int m,int n){
        // mark as visited & not to be converted 
        visited[i][j]=1;

        // go to all 4 directions
        int drow[] = {-1,1,0,0};
        int dcol[] = {0,0,1,-1};
        for(int l=0;l<4;l++){
            int nrow = i + drow[l];
            int ncol = j + dcol[l];
            // boundaries

            // if not visited and connected with a edged 1 then do consider that it wont lead to boundary
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1 && visited[nrow][ncol]!=1){
                dfs(nrow,ncol,grid,visited,m,n);
            }
        }

    }


    void numEnclaves(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        int numberOfLandsDoesNotLeadToBoundary = 0;
        // not intimating with given data, so visited array for it 
        vector<vector<int>> visited(m,vector<int>(n,0));

        // find edge 'O's which are not completely surrounded by all sides with 'X'
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // check only boundaries 
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    // check if its a 1
                    if(grid[i][j]==1){
                        dfs(i,j,grid,visited,m,n);      
                    }
                }
            }
        }

        // counting

        for(int  i=0;i<m;i++){
            for(int j=0;j<n;j++){

                // if is 1 and is not on edge and is within the grid then count
                if(grid[i][j]==1 && visited[i][j]!=1){  
                    numberOfLandsDoesNotLeadToBoundary++;
                }
            }
        }
        cout<<numberOfLandsDoesNotLeadToBoundary<<endl;
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
    vector<vector<int>> grid(m,vector<int>(n,0));
    for(int u=0;u<m;u++){
        for(int v=0;v<n;v++){
            int ip;
            cin>>ip;
            grid[u][v] = ip;
        }
    }

    Solution s;
    s.numEnclaves(grid);
    
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