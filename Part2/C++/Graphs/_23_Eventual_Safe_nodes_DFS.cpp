#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

DFS | Cycle detection | pathvisited nodes

A directed graph of V vertices and E edges is given in the form of an adjacency list adj. 
Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.

A node is a terminal node if there are no outgoing edges. 
A node is a safe node if every possible path starting from that node leads to a terminal node.

You have to return an array containing all the safe nodes of the graph.
The answer should be sorted in ascending order

7 7 

0 1 
0 2 
1 3 
1 2 
2 5 
3 0 
4 5 

Only nodes 2,4,5,6 are safe nodes, as every path from them leads to a terminal node 

Note: a terminal node is always a safe node
*/



class Solution
{
public:
    bool dfs(int node,vector<int> adj_list[],vector<int>& visited,vector<int>& pathVisited,int n){
        visited[node]=1;
        pathVisited[node]=1;

        // ask all neighbours 
        for(auto neigh: adj_list[node]){
            if(!visited[neigh]){
                bool res = dfs(neigh,adj_list,visited,pathVisited,n);
                if(res==false){
                    return false;
                }
            }else if(pathVisited[neigh]==1){    // same path
                return false;
            }
        }

        // omit node from the path
        pathVisited[node]=0;

        return true;    // when all paths are visited and it lead to a terminal node
    }

};

void solve()
{
    // grid
    int m;  // edges
    int n;  // nodes
    cin >> m >> n;

    // visited array 
    vector<int> visited(n,0);
    vector<int> pathVisited(n,0);     
    vector<int> ans;

    // Adjancency List for directed graph
    vector<int> adj_list[n];    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        // only from u to v
        adj_list[u].push_back(v);
    }

    Solution s;
    // run dfs for every node to explore its all paths to terminal to be safe
    for(int i=0;i<n;i++){
        bool res = s.dfs(i,adj_list,visited,pathVisited,n);
        if(res==true) ans.push_back(i);
        // reset the  visited & path visited array for each node 
        for(int j=0;j<n;j++) {
            pathVisited[j]=0;
            visited[j]=0;
        }
    }

    // answer must be returned in ascending order 
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
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
