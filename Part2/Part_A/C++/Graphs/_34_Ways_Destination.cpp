#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
You are in a city that consists of n intersections numbered from 0 to n - 1 with 
bi-directional roads between some intersections. 
The inputs are generated such that you can reach any intersection from any other 
intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where 
roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. 
You want to know in how many ways you can travel from intersection 0 to 
intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. 
Since the answer may be large, return it modulo 109 + 7.

Dijsktra Algo | Shortest Path | BFS | Counting array 
*/



class Solution
{
public:
    // BFS -> will find the shortest path 
    int bfs_shortest(int src,int dest,vector<pair<int,int>> adj_weighted_list[],vector<int>& dist,vector<int>& ways,int n,int m){
        // create a priority queue
        // dist, node
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // add src with time 0 to queue
        pq.push({0,src});

        // dist of src is 0 
        dist[src]=0;

        // ways to reach src is 1
        ways[src]=1;

        while(!pq.empty()){
            int n = pq.top().second;
            int d = pq.top().first;
            pq.pop();            

            // ask neighours
            for(auto neigh: adj_weighted_list[n]){
                int node = neigh.first;
                int edge_weight = neigh.second;

                // shortest distance 
                if(edge_weight + d < dist[node]){
                    // update the distance 
                    dist[node] = edge_weight + d;
                    
                    // ways will be same the previous node is taking to be reached
                    ways[node] = ways[n];
                    // add it to the queue
                    pq.push({dist[node], node});
                }
                // same distance again -> add this path which is from node n
                else if(edge_weight + d == dist[node]){
                    ways[node] += ways[n];
                }
            }   
        }
        // return ways to reach the destination
        return ways[dest];
    }


};

void solve()
{
    // grid
    int n;  // nodes
    int m;  // edges
    int src;    // src
    int dest;    // dest
    cin >> n >> m >> src >> dest;

    // grid
    vector<pair<int,int>> adj_weighted_list[n];
    for(int k=0;k<m;k++){
        int u,v,wt;
        cin>>u>>v>>wt;

        adj_weighted_list[u].push_back({v,wt});
    }
    
    Solution s;
    vector<int> ways(n,0);
    vector<int> dist(n,(int)1e9);
    int res = s.bfs_shortest(src,dest,adj_weighted_list,dist,ways,n,m);
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
