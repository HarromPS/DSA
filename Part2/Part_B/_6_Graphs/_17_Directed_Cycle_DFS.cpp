#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

Directed Graph Cycle 

Undirected graph DFS algo fails as it detects 
5 is visited from node 7's point of view, but 7's parent is 3 and 5 is already visited -> so it detects a cycle 3-7-5-4-3

DFS: Node on the same path, if visited again -> Cycle

So when, a node is touched again & is in the same path 

1 -->2 -->3 --> 4
     |    |     |
     8    7---->5 --> 6
    / \
   9 - 10

   3 to 4 and revese false
   3 to 7 and revese false

   8 to 9 
   9 to 10
   10 to 8 

3 - 4 - 5 - 6 -> path 1
3 - 7 - 5 - 6 -> path 2 

8 - 9 - 10 - 8 -> same path


*/


class Solution
{
public:
    bool dfs(int node, vector<int>& visited,vector<int>& pathVisited,vector<int> adj_list[]){
        // visit 1st node
        visited[node] = 1;

        // mark path visited
        pathVisited[node]=1;

        // ask neighbours
        for(auto neigh: adj_list[node]){
            // if not visited explore
            if(!visited[neigh]){
                if(dfs(neigh,visited,pathVisited,adj_list)==true)   // if returns true of detecting a cycle
                    return true;
            }else{
                // if already visited, check if its in the same path 
                if(pathVisited[neigh]==1){
                    return true;
                }
            }
        }
        // omit node from the path
        pathVisited[node]=0;

        return false;   // not detected a cycle

    }

    bool dfs_2(int node, vector<int>& visited,vector<int> adj_list[]){
        // path visited 
        visited[node] = 2;


        // ask neighbours
        for(auto neigh: adj_list[node]){
            // if not visited explore
            if(!visited[neigh]){
                if(dfs_2(neigh,visited,adj_list)==true)   // if returns true of detecting a cycle
                    return true;
            }else{
                // if already visited, check if its in the same path 
                if(visited[neigh]==2){
                    return true;
                }
            }
        }
        // omit node from the path
        visited[node]=1;

        return false;   // not detected a cycle

    }

};

void solve()
{
    // grid
    int m;  // edges
    int n;  // nodes
    cin >> m >> n;

    // Adjancency List
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
    vector<int> visited(n+1,0);
    vector<int> pathVisited(n+1,0);

    Solution s;
    int src = 1;    // starting node with -1 as parent 

    // detect cycle component wise
    for(int i=1;i<=n;i++){
        // if not visited
        if(!visited[i]){
            // if cycle
            if(s.dfs(i,visited,pathVisited,adj_list)==true){
                cout<<"Cycle"<<endl;
                break;
            }
        }
    }
    for(int i=0;i<=n;i++) visited[i]=0;
    
    for(int i=1;i<=n;i++){
        // if not visited
        if(!visited[i]){
            // if cycle
            if(s.dfs_2(i,visited,adj_list)==true){
                cout<<"Cycle"<<endl;
                break;
            }
        }
    }
    cout<<"Nope"<<endl;
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
