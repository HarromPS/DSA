#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Maximum Stone Removal

Minimum Spanning Tree | Min cost to all nodes with n nodes and n-1 edges

There are n stones at some integer coordinate points on a 2D plane. 
Each coordinate point may have at most one stone.

You need to remove some stones. 

A stone can be removed if it shares either the same row or 
the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, 
return the maximum possible number of stones that you can remove.

Input:
n=6
[[0 0] ,[ 0 1], [1 0] ,[1 2] ,[2 1] ,[2 2]]

Output:
5

Example:
One way to remove 5 stones are
1--[0,0]
2--[1,0]
3--[0,1]
4--[2,1]
5--[1,2]
*/

class DisjointSet
{
public:
    void dfs(int i,int j,vector<vector<int>>& adj_matrix,vector<vector<int>>& visited,int maxNodes){
        // mark the node as visited 
        visited[i][j] = 1;
        cout<<"("<<i<<","<<j<<")-> ";

        // call the dfs call from the node if in same row or column 
        // check in the row 
        for(int index=0;index<maxNodes;index++){
            if(adj_matrix[i][index]==1 && visited[i][index]==0){
                dfs(i,index,adj_matrix,visited,maxNodes);
            }
        }

        // check in the column 
        for(int index=0;index<maxNodes;index++){
            if(adj_matrix[index][j]==1 && visited[index][j]==0){
                dfs(index,j,adj_matrix,visited,maxNodes);
            }
        }

    }

    int maxRemove(int maxNode,vector<vector<int>>& stones, int n) {
        // Code here
        int numberOfComponents=0;
        vector<vector<int>> adj_matrix(maxNode,vector<int>(maxNode,0));
        vector<vector<int>> visited(maxNode,vector<int>(maxNode,0));

        for(int i=0;i<stones.size();i++){
            int u = stones[i][0];
            int v = stones[i][1];
            adj_matrix[u][v]=1;
        }
        // search in all the components
        for(int i=0;i<maxNode;i++){
            for(int j=0;j<maxNode;j++){
                if(adj_matrix[i][j]==1 && visited[i][j]==0){
                    numberOfComponents++;
                    dfs(i,j,adj_matrix,visited,maxNode);
                    cout<<endl;
                }
            }
        }

        for(int i=0;i<maxNode;i++){
            for(int j=0;j<maxNode;j++){
                cout<<visited[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<numberOfComponents<<endl;
        return (n-numberOfComponents);
    }
};

void solve(){
    int n;  // number of  
    int m;  // number of edges 
    cin>>n>>m;
    int maxNodes=0;

    // Works but not for all the test cases -> Momory Limit Exceed in Leetcode and GFG

    DisjointSet s;
    vector<vector<int>> stones;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        // get the max number of nodes 
        maxNodes = max(u,max(v,maxNodes));

        vector<int> temp;
        temp.push_back(u);
        temp.push_back(v);

        stones.push_back(temp);
        temp.clear();
    }
    int res = s.maxRemove(maxNodes+1,stones,n);
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


    