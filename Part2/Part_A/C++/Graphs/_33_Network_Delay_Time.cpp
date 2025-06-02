#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
You are given a network of n nodes, labeled from 1 to n. 
You are also given times, 
a list of travel times as directed edges times[i] = (ui, vi, wi), 
where ui is the source node, vi is the target node, 
and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k.
Return the minimum time it takes for all the n nodes to receive the signal. 
If it is impossible for all the n nodes to receive the signal, return -1.

Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

Dijsktra Algo | Shortest Path | BFS | Max time required 
*/



class Solution
{
public:
    // BFS -> will find the shortest path 
    int bfs_shortest(int src,vector<pair<int,int>> adj_weighted_list[],vector<int>& time,int n,int m){
        // create a queue
        // time, node
        queue<pair<int,int>> q;

        // add src with time 0 to queue
        q.push({0,src});

        // time of src is 0 
        time[src]=0;

        // 1 indexed graph
        time[0]=-1; // required check 

        // ans
        int ans=-1;

        while(!q.empty()){
            int node_time = q.front().first;
            int node = q.front().second;
            q.pop();            

            // ask neighours
            for(auto neigh: adj_weighted_list[node]){
                int n = neigh.first;
                int edge_time = neigh.second;

                // check 
                if(edge_time + node_time < time[n]){
                    // update the distance 
                    time[n] = edge_time+node_time;

                    // add it to the queue
                    q.push({time[n], n});
                }
            }
        }

        // check if all nodes received the signal 
        for(int i=1;i<=n;i++){
            if(time[i]==(int)1e9) return -1;
            ans=max(ans,time[i]);
        }
        return ans;
    }


};

void solve()
{
    // grid
    int n;  // nodes
    int m;  // edges
    int src;    // src
    cin >> n >> m >> src ;

    // grid
    vector<pair<int,int>> adj_weighted_list[n+1];
    for(int k=0;k<m;k++){
        int u,v,wt;
        cin>>u>>v>>wt;

        adj_weighted_list[u].push_back({v,wt});
    }
    
    Solution s;
    vector<int> time(n+1,(int)1e9);
    int res = s.bfs_shortest(src,adj_weighted_list,time,n,m);
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
