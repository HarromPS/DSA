#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
/*
BFS: 

1. Level wise traversal
2. Distance wise traversal

steps: 

Initial configurations

Queue
visited array 
Put it in queue
Mark 1st starting node as visited

2nd 

take all out until queue is empty 
take out and print 
ask for its neighbours
if neighbours are not visited add it to queue 
mark as visited

repeat step 2 until empty
*/

void BFS_Traversal(int n,vector<int> adj[]){
    // 1 based indexing 

    queue<int> q;   // Queue
    int visited[n+1] = {0};     // visited array
    visited[1]=1;       // 1st node is 1
    q.push(1);          // Put it in queue

    // take all out until queue is empty
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";

        // ask for its neighbours
        for(auto neighbour: adj[node]){
            // if neighbours are not visited add it to queue
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=1;
            }
        }
    }
}

void BFS(int n,int m){
    // list S.C:O(N)
    vector<int> adj_list[n+1];    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    cout<<"Adjancency List:\n";
    for(int u=0;u<=n;u++){
        cout<<u<<" ";
        for(int v=0;v<adj_list[u].size();v++){
            cout<<adj_list[u][v]<<" ";
        }
        cout<<endl;
    }

    // bfs traversal
    cout<<"\nBFS Traversal"<<endl;
    BFS_Traversal(n,adj_list);
}

void solve()
{
    // inputs
    int n;  // nodes
    int m;  // edges
    cin>>n>>m;

    BFS(n,m);
}
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
