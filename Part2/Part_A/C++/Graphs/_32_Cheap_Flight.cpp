#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
There are n cities connected by some number of flights. 
You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, 
return the cheapest price from src to dst with at most k stops. 
If there is no such route, return -1.

Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.


Note: Generic Dijkstra wont work as it will not allow more cost paths for lesser stops 

1. so priority will be of stops and not the distance 
2. and no need of priority queue, as stops will increase in a step wise manner

also, queue<stop, node> will also work as dist can be taken from dist array

*/



class Solution
{
public:
    // BFS -> will find the shortest path 
    int bfs_shortest(int src,int dest,int k,vector<pair<int,int>> adj_weighted_list[],vector<int>& dist,int n,int m){
        // create a priority queue
        // stops, node
        queue<pair<int,pair<int,int>>> q;

        // add src with stop 0 to queue
        q.push({0,{src,0}});    // cost 0

        // cost of src is 0 
        dist[src]=0;

        while(!q.empty()){
            int stop = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();

            // if stops exceeds limit
            if(stop > k) continue; //  as it will be always increasing

            // ask neighours
            for(auto neigh: adj_weighted_list[node]){
                int n = neigh.first;
                int weight = neigh.second;

                // check 
                if(cost + weight < dist[n] && stop <= k){
                    // update the distance 
                    dist[n] = cost+weight;

                    // add it to the queue
                    q.push({stop + 1, {n, dist[n]}});
                }
            }
        }

        // if it is reachable then return its cost 
        if(dist[dest]==(int)1e9) return -1;
        return dist[dest];
    }


};

void solve()
{
    // grid
    int n;  // nodes
    int m;  // edges

    int src;
    int dest;
    int k;  // stops 
    cin >> n >> m >> src >> dest >> k ;

    // grid
    vector<pair<int,int>> adj_weighted_list[n];
    for(int k=0;k<m;k++){
        int u,v,wt;
        cin>>u>>v>>wt;

        adj_weighted_list[u].push_back({v,wt});
    }
    
    Solution s;
    vector<int> dist(n,(int)1e9);
    int res = s.bfs_shortest(src,dest,k,adj_weighted_list,dist,n,m);
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
