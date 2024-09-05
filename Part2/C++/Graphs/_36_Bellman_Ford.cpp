#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given start, end and an array arr of n numbers. At each step, 
start is multiplied with any number in the array and
then mod operation with 100000 is done to get the new start.

Your task is to find the minimum steps in which end can be achieved starting from start. 
If it is not possible to reach end, then return -1.

Input:
arr[] = {2, 5, 7}
start = 3, end = 30
Output:
2
Explanation:
Step 1: 3*2 = 6 % 100000 = 6 
Step 2: 6*5 = 30 % 100000 = 30

Bellman ford | Shortest path | Negative cycles | Directed Graphs
*/

class Solution
{
public:
    // BFS -> will find the shortest path 
    int bellmanFord(int src,vector<vector<int>>& edges,vector<int>& dist,int n,int m){

        // src distance is 0 
        dist[src]=0;

        // run the iterations for n-1 times
        for(int i=0;i<n-1;i++){
            // cover all the edges
            for(int k=0;k<m;k++){
                int u=edges[k][0];
                int v=edges[k][1];
                int wt=edges[k][2];               
                // relax the edges
                if(dist[u]!=(int)1e9 && dist[u] + wt < dist[v]){
                    dist[v]=dist[u]+wt;
                }
            }
        }

        // check on nth iteration if the distance gets updated 
        for(int k=0;k<m;k++){
            int u=edges[k][0];
            int v=edges[k][1];
            int wt=edges[k][2];

            // it should not be infinite & if distance gets reduced, means there is a cycle
            if(dist[u]!=(int)1e9 && dist[u] + wt < dist[v]){
                return -1;
            }
        }

        // else print the distance array
        for(int i=0;i<dist.size();i++){
            cout<<dist[i]<<" ";
        }
        cout<<endl;
        return 0;
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
    vector<vector<int>> edges;
    vector<int> temp;
    for(int k=0;k<m;k++){
        int u,v,wt;
        cin>>u>>v>>wt;

        temp.push_back(u);
        temp.push_back(v);
        temp.push_back(wt);

        edges.push_back(temp);
        temp.clear();
    }
    
    Solution s;
    vector<int> dist(n,(int)1e9);
    int res = s.bellmanFord(src,edges,dist,n,m);
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
