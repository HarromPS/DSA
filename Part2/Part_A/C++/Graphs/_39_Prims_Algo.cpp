#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Minimum Spanning Tree | Min cost to all nodes with n nodes and n-1 edges 

Prims Algo | PQ | MST | VIS 

Given a weighted, undirected, and connected graph with V vertices and E edges, 
your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. 
The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers. 
Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge

*/

class Solution
{
public:
    int primsAlgo(int src,vector<pair<int,int>> adj_weighted_list[],int n,int m){
        // create a visited array 
        vector<int> visited(n,0);

        // create a mst ds 
        vector<pair<int,int>> mst;

        // add src to pq 
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        pq.push({0,{src,-1}});    // -1 means no parent
        int sum=0;

        // O(E)
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second.first;
            int parent = pq.top().second.second;
            pq.pop();

            // if node is already visited, skip this iteration
            if(visited[node]==1) continue;

            // mark this as visited 
            visited[node]=1;

            // if parent is not -1 then add this edge to mst
            if(parent!=-1) mst.emplace_back(node,parent);

            // add the sum of mst
            sum+=wt;

            // ask neighbours 
            for(auto neigh: adj_weighted_list[node]){
                int n = neigh.first;
                int edge_weight = neigh.second;

                // if not visited 
                if(visited[n]==0){
                    // add it to queue 
                    pq.push({edge_weight,{n, node}});
                }
            }
        }

        return sum;
    }


};

void solve()
{
    // grid
    int n;   // nodes
    int m;
    int src;
    cin >> n >> m >> src;

    // provided with a weighted adj matrix 
    // grid
    vector<pair<int,int>> adj_weighted_list[n];
    for(int k=0;k<m;k++){
        int u,v,wt;
        cin>>u>>v>>wt;

        // undirected weighted graph
        adj_weighted_list[u].push_back({v,wt});
        adj_weighted_list[v].push_back({u,wt});
    }

    // for(int i = 0; i < n; i++){  // Iterate through all nodes
    //     cout << "Node " << i << ": ";
    //     for(auto neigh : adj_weighted_list[i]){
    //         cout << "(" << neigh.first << ", " << neigh.second << ") ";  // Print neighbor and weight
    //     }
    //     cout << endl;
    // }

    Solution s;
    int res = s.primsAlgo(src,adj_weighted_list,n,m);
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


