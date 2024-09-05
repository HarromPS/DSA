#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

You are given an Undirected Graph having unit weight of the edges, 
find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, 
then return -1 for that vertex.

Which algo to use? 
DFS -> trying all paths | Recursion | src to all the vertices

# create a visited array and a distance array initially filled with max distance from src
# visit all nodes from src and update their weights 
# if already visited, check if the distance from another path is shortest, then update the weight

# INTUTION

Why topo sort?
In topo sort, src 6 goes into 5 and 4 which are just next to 6 
so already moving according to reachability
*/



class Solution
{
public:
   void bfs_topo_sort(int node,vector<pair<int,int>> adj_weighted_list[],vector<int> & topostack,vector<int> & visited){
        // visit node
        visited[node]=1;

        // ask neighbours
        for(auto neighs: adj_weighted_list[node]){
            int n = neighs.first;
            if(!visited[n]){
                bfs_topo_sort(n,adj_weighted_list,topostack,visited);
            }
        }
        
        // add to stack
        topostack.push_back(node);
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
    vector<int> visited(n,0);       // visited array 
    vector<int> dist(n,(int)1e9);    // distance array initially with max distance
    vector<int> topostack;       // topo sort array 
    
    // find topo sort
    for(int i=0;i<n;i++){
        if(!visited[i])
            s.bfs_topo_sort(i,adj_weighted_list,topostack,visited);
    }

    // distance of src is set to 0 
    // start dfs from src
    dist[src]=0;

    // take out node out of stack and relax the edge distances 
    for(int i=topostack.size()-1;i>=0;i--){ // LIFO
        int node = topostack[i];
        int node_weight = dist[node];

        // ask neighbours
        for(auto neighs: adj_weighted_list[node]){
            int n=neighs.first;
            int n_weig=neighs.second;

            if(dist[n] > (n_weig + node_weight)){
                dist[n] = n_weig + node_weight;
            }
        }
    }   

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
