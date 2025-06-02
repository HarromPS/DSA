#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.

Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.

Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.


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

    int largestIsland(int n, int m, vector<vector<int>> grid) {
        // connect all the cells as nodes in the disjoint set        
        // traverse all the grid & connect all the cells nodes
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    // 4 directions
                    int drow[]={-1,1,0,0};
                    int dcol[]={0,0,1,-1};
                    for(int l=0;l<4;l++){
                        int nrow=i+drow[l];
                        int ncol=j+dcol[l];
                        // boundary
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                            // if adjacent are island and are not connected
                            if(grid[nrow][ncol]==1){
                                // if not connected
                                int node = i * m + j;
                                int adjNode = nrow * m + ncol;
                                if(findParent(node)!=findParent(adjNode)){
                                    // union them, by size as we need size of islands
                                    UnionBySize(node,adjNode);
                                }
                            }
                        }
                    }
                }
            }
        }

        int ans=0;
        // now get the largest island
        // visit every non island node
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){

                    set<int> st;
                    // 4 directions
                    int drow[]={-1,1,0,0};
                    int dcol[]={0,0,1,-1};
                    for(int l=0;l<4;l++){
                        int nrow=i+drow[l];
                        int ncol=j+dcol[l];
                        // boundary
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                            // if adjacent is island 
                            if(grid[nrow][ncol]==1){
                                // get its ultimate parent
                                int node = nrow * m + ncol;
                                int parentUltimate = findParent(node);

                                // // get the size of the parent holding 
                                // int componentSize=size[parentUltimate];
                                // // add up all the component size
                                // res+=componentSize;

                                // store the ultimate parent to clear edge cases
                                st.insert(parentUltimate);
                            }
                        }
                    }
                    int res=1;  // +1 alredy added
                    for(auto it: st){
                        res+=size[it];
                    }

                    // maximize the answer 
                    ans=max(ans,res);
                }
            }
        }
        // if all the cells are 1
        for(int node=0;node<n*m;node++){
            ans=max(ans, size[findParent(node)]);
        }
        return ans;
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

    // n*m nodes are there
    DisjointSet s(n*m);
    int ans=s.largestIsland(n,m,grid);
    cout<<ans<<endl;
    
    
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


