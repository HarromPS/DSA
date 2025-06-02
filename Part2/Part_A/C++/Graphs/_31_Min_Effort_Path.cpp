#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
You are a hiker preparing for an upcoming hike. You are given heights[][], a 2D array of size rows x columns,
where heights[row][col] represents the height of cell (row, col). 
You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). 
You can move up, down, left, or right, and you wish to find the route with minimum effort.

Note: A route's effort is the maximum absolute difference in heights between 
two consecutive cells of the route.

*/



class Solution
{
public:
    // BFS -> will find the shortest path 
    int bfs_shortest(int src_i,int src_j,int dest_i,int dest_j,vector<vector<int>>& grid,vector<vector<int>>& diff,int n,int m){
        // create a priority queue
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        // add src node to pq with diff 0 
        pq.push({0,{src_i,src_j}});

        while(!pq.empty()){
            int difference=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();

            // check for destination
            if(i==dest_i && j==dest_j) return difference;

            // check for neighbours
            int drow[]={-1,1,0,0};
            int dcol[]={0,0,-1,1};
            for(int l=0;l<4;l++){
                int nrow=i+drow[l];
                int ncol=j+dcol[l];

                // check boundaries
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    // get the effort from current point to all paths 
                    int newEffort=max(abs(grid[nrow][ncol]-grid[i][j]), difference);

                    // min of all its paths 
                    if(newEffort < diff[nrow][ncol]){
                        diff[nrow][ncol] = newEffort;

                        // add to queue
                        pq.push({newEffort,{nrow,ncol}});
                    }
                }
            }
        }

        return 0;
    }


};

void solve()
{
    // grid
    int n;  // alphabets
    int m;  // array size
    cin >> n >> m ;

    // grid
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int k=0;k<n;k++){
        for(int l=0;l<m;l++){
            cin>>grid[k][l];
        }
    }
    
    Solution s;
    vector<vector<int>> dist(n,vector<int>(m,(int)1e9));
    int res = s.bfs_shortest(0,0,n-1,m-1,grid,dist,n,m);
    cout<<res<<endl;
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
