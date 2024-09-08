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
    // create a rank, parent size array for Union by rank
    // create a size, parent size array for Union by size
    vector<int> rank, parent, size;
public:
    // Constructor function to get initial configurations
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    // function to find the ultimate parent recursively along with path compression 
    int findParent(int node){
        if(node == parent[node]){
            return node;
        }

        // return by finding its ultimate parent while backtracking
        return parent[node] = findParent(parent[node]);
    }

    // get the union by rank 
    void UnionByRank(int u,int v){
        // get the ultimate parents of u and v nodes
        int pu = findParent(u);
        int pv = findParent(v);

        // if they have same parnent, just return 
        if(pu == pv) return;

        // else if check the rank 
        if(rank[pu] < rank[pv]){
            parent[pu] = parent[pv];
        }else if(rank[pu] > rank[pv]){
            parent[pv] = parent[pu];
        }else{
            parent[pv] = parent[pu];
            // update the rank 
            rank[pu]++;
        }
    }

    // union by size -> keeps the track of the size of the component
    void UnionBySize(int u,int v){
        // get the ultimate parents of u and v nodes
        int pu = findParent(u);
        int pv = findParent(v);

        // if they have same parnent, just return 
        if(pu == pv) return;

        // else if check the rank 
        if(size[pu] < size[pv]){
            parent[pu] = parent[pv];
            size[pv] += size[pu];
        }else if(rank[pu] > rank[pv]){
            parent[pv] = parent[pu];
            size[pu] += size[pv];
        }else{
            parent[pu] = parent[pv];
            size[pv] += size[pu];
        }
    }

    int maxRemove(vector<vector<int>>& stones, int n) {
            return 0;
    }

};

void solve(){
    int n;  // number of  
    int m;  // number of edges 
    cin>>n>>m;

    // Works but not for all the test cases -> Momory Limit Exceed in Leetcode and GFG

    DisjointSet s(n);
    vector<vector<int>> stones;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        vector<int> temp;
        temp.push_back(u);
        temp.push_back(v);

        stones.push_back(temp);
        temp.clear();
    }
    int res = s.maxRemove(stones,n);
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


