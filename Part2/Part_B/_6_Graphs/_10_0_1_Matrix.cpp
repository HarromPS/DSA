#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

*/

class Node{
public: 
    int i;
    int j;
    int dist;
    Node(int _i,int _j,int _dist){
        this->i=_i;
        this->j=_j;
        this->dist=_dist;
    }
    Node(){}
};

class Solution{
public:

    void bfs(vector<vector<int>>& grid,vector<vector<int>>& visited,vector<vector<int>>& distance,int m,int n){
        // Queue
        queue<Node> q;

        // add all 1s to queue
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push(Node(i,j,0));
                    distance[i][j]=0;
                    visited[i][j]=1;
                }
            }
        }

        // until queue is empty
        while(!q.empty()){
            int r = q.front().i;
            int c = q.front().j;
            int dist = q.front().dist;  
            q.pop();

            // go to is neighbours
            int drow[] = {-1,1,0,0};
            int dcol[] = {0,0,1,-1};
            for(int l=0;l<4;l++){
                int nrow = r + drow[l];
                int ncol = c + dcol[l];

                // boundaries
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && visited[nrow][ncol]!=1){
                    // mark visited
                    visited[nrow][ncol]=1;

                    // update distance
                    distance[nrow][ncol]=dist+1;

                    // add to queue
                    q.push(Node(nrow,ncol,dist+1));
                }
            }
        }
    }

    void bfs_optimize(vector<vector<int>>& grid,vector<vector<int>>& distance,int m,int n){
        // instead of using visited matrix we can initialize the dist matrix with -1 where -1 will indicate that the cell has not been visited: to space optimize

        for(int  i=0;i<m;i++){
            for(int j=0;j<n;j++){
                distance[i][j]=-1;  // not visited
            }
        }

        // Queue
        queue<Node> q;

        // add all 1s to queue
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push(Node(i,j,0));
                    distance[i][j]=0;   // 0 means diatance is 0 and is visited(not -1)
                }
            }
        }

        // until queue is empty
        while(!q.empty()){
            int r = q.front().i;
            int c = q.front().j;
            int dist = q.front().dist;  
            q.pop();

            // go to is neighbours
            int drow[] = {-1,1,0,0};
            int dcol[] = {0,0,1,-1};
            for(int l=0;l<4;l++){
                int nrow = r + drow[l];
                int ncol = c + dcol[l];

                // boundaries, and not visited
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && distance[nrow][ncol]==-1){
                    // mark visited + update distance
                    if(distance[nrow][ncol]==-1){
                        distance[nrow][ncol]=0;
                        distance[nrow][ncol]=dist+1;
                    }

                    // add to queue
                    q.push(Node(nrow,ncol,dist+1));
                }
            }
        }
    }

    void nearest(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        // not intimating with given data, so visited array for it 
        vector<vector<int>> visited(m,vector<int>(n,0));

        // distance grid to track distances from nearest 1s of current cell 
        vector<vector<int>> distance(m,vector<int>(n,0));

        // run function to update distance answer grid
        // bfs(grid,visited,distance,m,n);
        bfs_optimize(grid,distance,m,n);


        for(int  i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<distance[i][j]<<" ";
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
    vector<vector<int>> grid(m,vector<int>(n,0));
    for(int u=0;u<m;u++){
        for(int v=0;v<n;v++){
            int ip;
            cin>>ip;
            grid[u][v] = ip;
        }
    }

    Solution s;
    s.nearest(grid);
    
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