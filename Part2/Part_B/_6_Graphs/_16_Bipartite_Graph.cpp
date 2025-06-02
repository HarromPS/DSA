#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given an adjacency list of a graph adj of V no. of vertices having 0 based index
Check whether the graph is bipartite or not.

Know more about Bipartite Graph: - https://www.geeksforgeeks.org/what-is-bipartite-graph/

BIPARTITIE GRAPH: A GRAPH THAT CAN BE COLORED WITH EXACTLY 2 COLORS SUCH THAT NO 2 ADJACENT
NODES HAVE SAME COLOR

*/

class Solution{
public:
    // DFS
    bool dfs(int node,int col,vector<vector<int>>& adj_list,vector<int>& color){
        // mark visited with the color
        color[node] = col;

        // go to its neighbours and color them 
        for(auto neigh: adj_list[node]){
            // if not visited, visit
            if(color[neigh]==-1){
                // change color
                int ncol = (col==1?0:1);
                bool ans = dfs(neigh, ncol, adj_list, color);
                // if any neighbour returned false return false
                if(ans==false) return false;
            }else{
                // if already visited, check if same color -> not a bipartite graph
                if(color[neigh]==col){
                    return false;
                }
            }
        }
        // if all colored
        return true;
    }
    
    void isBipartite(vector<vector<int>>& adj_list,int n){
        // visited array
        vector<int> color(n+1,-1);  // no node is colored yet

        // for connected components
        for(int i=0;i<n+1;i++){
            // if it is not colored, color it start with color 0
            if(color[i]==-1){
                bool ans = dfs(i,0,adj_list,color);
                if(ans==false){
                    cout<<"Not a bipartite graph"<<endl;
                    return;
                }
            }
        }
        cout<<"Yes a bipartitte graph"<<endl;
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
    vector<vector<int>> adj_list(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    Solution s;
    s.isBipartite(adj_list,n);
    
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