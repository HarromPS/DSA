#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Topological sorting of a directed acyclic graph is nothing but the 
linear ordering of vertices such that if there is an edge between node u and v(u -> v), node u appears before v in that ordering.

Why only Directed ?
-> In undirected, 1 is before 2 and vice versa, 2 can be before 1, violates the defination of Topo sort

Why Acyclic ?
1 -> 2 i.e 1 before 2
2 -> 3 i.e 2 before 3
3 -> 1 i.e 3 before 1 violates the topo sort defination

5-->0<--4
|       |
-       -
2-->3-->1

0-
1-
2-3
3-1
4-0,1
5-0,2

one of the ordering
5 4 2 3 1 0

*/


class Solution
{
public:
    void dfs(int node, vector<int> adj_list[],vector<int>& visited,vector<int>& st){
        // visit 1st node
        visited[node] = 1;

        // ask neighbours
        for(auto neigh: adj_list[node]){
            // if not visited explore
            if(!visited[neigh]){
                dfs(neigh,adj_list,visited,st);
            }
        }
        st.push_back(node); // add to stack before back
        return;
    }

};

void solve()
{
    // grid
    int m;  // edges
    int n;  // nodes
    cin >> m >> n;

    // Adjancency List for directed graph
    vector<int> adj_list[n+1];    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        // only from u to v
        adj_list[u].push_back(v);
    }

    cout<<"Adjancency List:\n";
    for(int u=0;u<=n;u++){
        // cout<<u<<": ";
        for(int v=0;v<adj_list[u].size();v++){
            // cout<<adj_list[u][v]<<" ";
        }
        // cout<<endl;
    }

    // visited array 
    vector<int> visited(n,0);
    vector<int> st;     // stack

    Solution s;

    // detect cycle component wise
    for(int i=0;i<n;i++){
        // if not visited
        if(!visited[i]){
            s.dfs(i,adj_list,visited,st);
        }
    }
    
    for(int i=st.size()-1;i>=0;i--){
        cout<<st[i]<<" ";
    }
    cout<<endl;
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
