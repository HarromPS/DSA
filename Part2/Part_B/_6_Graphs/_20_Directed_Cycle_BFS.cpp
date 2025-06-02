#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

Detect Cycle using Kahn's algo

Kahn Algo | BFS 

Uses Indegrees

Topological sorting of a directed acyclic graph is nothing but the 
linear ordering of vertices such that if there is an edge between node u and v(u -> v), node u appears before v in that ordering.

Why only Directed ?
-> In undirected, 1 is before 2 and vice versa, 2 can be before 1, violates the defination of Topo sort

Why Acyclic ?
1 -> 2 i.e 1 before 2
2 -> 3 i.e 2 before 3
3 -> 1 i.e 3 before 1 violates the topo sort defination

So if, cant produce a topo sort of n size, as it contains all nodes 
Then there is a cycle
*/


class Solution
{
public:
    // return true of cycle
    bool bfs(vector<int> adj_list[],vector<int>& indegree,vector<int>& ans,int n){
        // Queue
        queue<int> q;

        // add all nodes with indegrees 0
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        // not empty
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            ans.push_back(node);

            // ask neighbours

            // node is in the topo sort 
            // so remove it from the indegree
            for(auto neigh: adj_list[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }

        // if not same, return true -> cycle
        return ans.size()!=n;
    }

    void getIndegree(vector<int> adj[],int n){
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto v: adj[i]){
                indegree[v]++;
            }
        }
    }

};

void solve()
{
    // grid
    int m;  // edges
    int n;  // nodes
    cin >> m >> n;

    // visited array 
    vector<int> indegree(n,0);
    vector<int> ans;     // ans ds

    // Adjancency List for directed graph
    vector<int> adj_list[n+1];    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        // get the indegres
        indegree[v]++;

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


    Solution s;
    bool res = s.bfs(adj_list,indegree,ans,n);
    cout<<(res==1?"Cycle":"No Cycle")<<endl;
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
