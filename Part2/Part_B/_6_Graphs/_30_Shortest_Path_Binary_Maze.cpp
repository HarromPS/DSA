#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Shortest Distance in a Binary Maze

Given a n * m matrix grid where each element can either be 0 or 1. 
You need to find the shortest distance between a given source cell to a destination cell. 
The path can only be created out of a cell if its value is 1. 

If the path is not possible between source cell and destination cell, then return -1.

Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. 
Two cells are adjacent if they share a side. 
In other words, you can move in one of the four directions, Up, Down, Left and Right. 
The source and destination cell are based on the zero based indexing. 
The destination cell should be 1.

BFS | return Shortest Path

*/



class Solution
{
public:
    // BFS -> will find the shortest path 
    int bfs_shortest(int src_i,int src_j,int dest_i,int dest_j,vector<vector<int>>& grid,vector<vector<int>>& dist,int n,int m){
        // if src is 0 or destination is 0 return -1;
        if(grid[src_i][src_j]==0 || grid[dest_i][dest_j]==0)
            return -1;
        
        // create a queue
        // src node will be assigned 0 as its distance
        dist[src_i][src_j]=0;

        queue<pair<int,pair<int,int>>> q;

        // add src cell to queue with distance 0
        q.push({0,{src_i,src_j}});

        while(!q.empty()){
            int distance = q.front().first;
            int i = q.front().second.first;
            int j = q.front().second.second;
            q.pop();

            // check all neighbours 
            int drow[]={1,-1,0,0};
            int dcol[]={0,0,1,-1};
            for(int l=0;l<4;l++){
                int nrow=i+drow[l];
                int ncol=j+dcol[l];

                // boundaries and checks 
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && dist[nrow][ncol] > 1 + distance){
                    // reduce the distance
                    dist[nrow][ncol]=1+distance;
                    // add to queue
                    q.push({1+distance,{nrow,ncol}});
                }
            }
        }
        
        // if not reached 
        if(dist[dest_i][dest_j]==(int)1e9)
            return -1;

        // else return distance
        return dist[dest_i][dest_j];
    }


};

void solve()
{
    // grid
    int n;  // alphabets
    int m;  // array size
    int i,j;
    int destination_i,destination_j;
    cin >> n >> m >> i >> j >> destination_i >> destination_j;

    // grid
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int k=0;k<n;k++){
        for(int l=0;l<m;l++){
            cin>>grid[k][l];
        }
    }
    
    Solution s;
    vector<vector<int>> dist(n,vector<int>(m,(int)1e9));
    int res = s.bfs_shortest(i,j,destination_i,destination_j,grid,dist,n,m);
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
