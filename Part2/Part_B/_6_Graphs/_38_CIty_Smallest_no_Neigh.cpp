#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
There are n cities labeled from 0 to n-1 with m edges connecting them. 
Given the array edges where edges[i] = [fromi , toi ,weighti] 
represents a bidirectional and weighted edge between cities fromi and toi, 
and given the integer distanceThreshold. 
You need to find out a city with the smallest number of cities that are reachable through some path and 
whose distance is at most Threshold Distance. 
If there are multiple such cities, our answer will be the city with the greatest label.

Note: The distance of a path connecting cities i and j is equal to the sum of the edge's weights along that path.

Input:
n = 4, m = 4
edges = [[0, 1, 3],
         [1, 2, 1], 
         [1, 3, 4],  
         [2, 3, 1]]
distanceThreshold = 4
Output:
3

*/

class Solution
{
public:
    // BFS -> will find the shortest path 
    int floydWarshall(vector<vector<int>>& cost_adj_matrix,int n,int m,int threshold){
        // 1st iteration is already done

        // n iterations for shortest path from all nodes to all nodes 
        for(int via=0;via<n;via++){
            // iterate to every cell 
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    // minimize the cost
                    cost_adj_matrix[i][j] = min(cost_adj_matrix[i][j], cost_adj_matrix[i][via] + cost_adj_matrix[via][j]);
                }
            }
        }

        // go to all the cities an collect frequencies of cities they can reach with threshold
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[i]=0;

        int smallestCity=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(cost_adj_matrix[i][j]<=threshold){
                    mp[i]++;
                }
            }
            // get the smallest city before hand
            smallestCity=min(smallestCity,mp[i]);
        }

        // iterate through the map and get the city
        int ans=0;
        for(auto it:mp){
            // if multiple cities with same number of small cities, get max of all of them 
            if(it.second == smallestCity){
                ans = max(ans,it.first);
            }
        }
        return ans;
    }


};

void solve()
{
    // grid
    int n;   // nodes
    int m;
    int threshold;
    cin >> n >> m >>threshold;

    // provided with a weighted adj matrix 
    // grid
    vector<vector<int>> edges(n, vector<int>(n,(int)1e9));
    for(int k=0;k<m;k++){
        int u,v,wt;
        cin>>u>>v>>wt;

        // undirected weighted graph
        edges[u][v]=wt;
        edges[v][u]=wt;
    }
    
    for(int i=0;i<n;i++){
        // node to itself is 0 
        edges[i][i]=0;
    }

    Solution s;
    int res = s.floydWarshall(edges,n,m,threshold);
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


