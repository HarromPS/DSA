#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given a weighted, undirected and connected graph of V vertices and an adjacency list adj 
where adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is edge between i and j , 
second integers corresponds to the weight of that  edge . 
You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. 
You have to return a list of integers denoting shortest distance between each node and Source vertex S.

Dijkstra Algo | necessary for graphs having cycles | because they cant be topologically sorted

Solved using Priority Queue instead of topological sort for Undirected graph

*/

// shortest distance of all the vertices from the source vertex src

class Solution
{
public:
   void bfs_dijkstra(int src,vector<pair<int,int>> adj_weighted_list[],vector<int>& dist){
        // create a priority queue for min heap
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // add src with dist 0 
        pq.push({0,src});    // min heap | dist, node

        while(!pq.empty()){
            int node_dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // ask neighbours
            for(auto neigh: adj_weighted_list[node]){
                int n=neigh.first;          // in adj list we have node as first element and weight as second
                int edge_weight=neigh.second;

                if(dist[n] > edge_weight + node_dist){
                    dist[n]=edge_weight + node_dist;

                    // add neigh and its distance to pq
                    pq.push({dist[n], n});
                }
            }
        }

        // if node not reachable 
        for(int i=0;i<dist.size();i++){
            if(dist[i]==(int)1e9){
                dist[i]=-1;
            }
        }
   }

};

void solve()
{
    // grid
    int m;  // alphabets
    int n;  // array size
    int src;
    cin >> m >> n >> src;

    // list
    vector<pair<int,int>> adj_weighted_list[n];
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;

        // for weighted graph
        adj_weighted_list[u].push_back({v,wt});
        adj_weighted_list[v].push_back({u,wt});
    }

    // cout<<"Adjancency weighted graph list:\n";
    // for(int u=0;u<n;u++){
    //     cout<<u<<"[";
    //     for(auto v: adj_weighted_list[u]){
    //         cout<<"["<<(v.first)<<" "<<(v.second)<<"]";
    //     }
    //     cout<<"]"<<endl;
    // }
    
    Solution s;
    vector<int> dist(n,(int)1e9);    // distance array initially with max distance
    vector<int> topostack;       // topo sort array

    // distance of src is set to 0 
    // start dfs from src
    dist[src]=0;

    s.bfs_dijkstra(src,adj_weighted_list,dist);

    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
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
