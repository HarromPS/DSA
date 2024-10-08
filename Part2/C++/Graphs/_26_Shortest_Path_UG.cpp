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
*/



class Solution
{
public:
    void dfs(int src,vector<int> adj_list[],vector<int>& dist,vector<int>& visited){
        visited[src]=1;
        int neigh_weight=1;

        // ask neighbours
        for(auto neigh: adj_list[src]){
            if(!visited[neigh]){
                // give it a distance to the neighbour from src
                dist[neigh] = dist[src]+neigh_weight;
                dfs(neigh,adj_list,dist,visited);
            }
            else {
                // if already visited, update weight by checking, if its path weight is less than curr path weight
                if(dist[neigh] > dist[src]+neigh_weight){
                    // update the weight
                    dist[neigh]=dist[src]+neigh_weight;
                }
            }
        }
    }

    // striver
    void bfs(int src,vector<int> adj_list[],vector<int>& dist,int n){
        // create a queue
        queue<int> q;
        // add src with dist 0 to queue
        q.push(src);
        dist[src]=0;    // src dist is 0

        while(!q.empty()){
            int node=q.front();
            q.pop();

            // ask neighbours
            for(auto neigh: adj_list[node]){
                // update distances
                if(dist[neigh] > dist[node]+1){
                    dist[neigh] = dist[node]+1;
                    q.push(neigh);
                }   
            }
        }

        // if a node is unreachable
        
        for(int i=0;i<n;i++){
            if(dist[i]==(int)(1e9)) dist[i]=-1;
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

    // generate a dg
    // Adjancency List for directed graph
    vector<int> adj_list[n];    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        // only from u to v
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
        
    }
    
    Solution s;
    vector<int> visited(n,0);       // visited array 
    vector<int> dist(n,(int)1e9);    // distance array initially with max distance

    // start dfs from src
    // distance of src is 0
    dist[src]=0;
    s.dfs(src,adj_list,dist,visited);
   
    for(int i=0;i<n;i++){
        if(dist[i]==(int)1e9){
            dist[i]=-1;
        }
        cout<<dist[i]<<"\n";
    }
    cout<<endl;

    for(int i=0;i<n;i++){
        dist[i]=(int)(1e9);
    }
    s.bfs(src,adj_list,dist,n);

    for(int i=0;i<n;i++){
        
        cout<<dist[i]<<"\n";
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
