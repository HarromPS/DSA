#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
You have been given a non-empty grid consisting of only 0s and 1s. 
You have to find the number of islands in the given grid.

An island is a group of 1s (representing land) connected horizontally, vertically or diagonally. 
You can assume that all four edges of the grid are surrounded by 0s (representing water).

Sample Input 1:

2
4 5
0 0 1 1 0
1 0 1 1 0
0 1 0 0 0 
0 0 0 0 1
1 3
1 1 1

Sample output 1:

2
1

Explanation of Sample output 1:

For the first test case, there are two islands in the grid.
For the second test case, there is only one island in the grid.

*/

class Node{
public: 
    int i;
    int j;
    Node(){}
    Node(int i,int j){
        this->i=i;
        this->j=j;
    }
};

class Solution{
public:
    // BFS
    void bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visited,int color,int m,int n){
        // mark visited with the color
        visited[i][j]=color;

        // queue
        queue<Node> q;
        q.push(Node(i,j));

        while(!q.empty()){
            int r = q.front().i;
            int c = q.front().j;
            q.pop();

            // asking neighbours in all 8 directions
            int drow[]={-1,-1,-1,0,0,1,1,1};
            int dcol[]={-1,0,1,-1,1,-1,0,1};
            for(int l=0;l<8;l++){
                int nrow = r+drow[l];
                int ncol = c+dcol[l];

                // boundaries
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1 && visited[nrow][ncol]==0){
                    // mark them as visited
                    visited[nrow][ncol]=color;
                    // add to queue
                    q.push(Node(nrow,ncol));
                }
            }            
        }
    }
    
    void numberOfIslands(vector<vector<int>>& grid,int m,int n){
        // color the islands which are there in grid with colors and count the no of colors used
        int color = 0;

        // visited array
        vector<vector<int>> visited(m,vector<int>(n,0));

        // from where any island starts, color all the lands which is attatched to it
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && visited[i][j]==0){  // is a land and not colored    
                    color++;
                    bfs(i,j,grid,visited,color,m,n);
                }
            }
        }

        cout<<color<<endl;
        // return color;
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
    s.numberOfIslands(grid,m,n);
    
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