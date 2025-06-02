#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Minimum Spanning Tree | Min cost to all nodes with n nodes and n-1 edges

There are n cities. 
Some of them are connected, while some are not. 
If city a is connected directly with city b, and city b is connected directly with city c, 
then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 
if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/

class DisjointSet
{
    // create a rank, parent size array for Union by rank
    // create a size, parent size array for Union by size
    vector<int> rank, parent, size;
public:
    // Constructor function to get initial configurations
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    // function to find the ultimate parent recursively along with path compression 
    int findParent(int node){
        if(node == parent[node]){
            return node;
        }

        // return by finding its ultimate parent while backtracking
        return parent[node] = findParent(parent[node]);
    }

    // get the union by rank 
    void UnionByRank(int u,int v){
        // get the ultimate parents of u and v nodes
        int pu = findParent(u);
        int pv = findParent(v);

        // if they have same parnent, just return 
        if(pu == pv) return;

        // else if check the rank 
        if(rank[pu] < rank[pv]){
            parent[pu] = parent[pv];
        }else if(rank[pu] > rank[pv]){
            parent[pv] = parent[pu];
        }else{
            parent[pv] = parent[pu];
            // update the rank 
            rank[pu]++;
        }
    }

    // union by size -> keeps the track of the size of the component
    void UnionBySize(int u,int v){
        // get the ultimate parents of u and v nodes
        int pu = findParent(u);
        int pv = findParent(v);

        // if they have same parnent, just return 
        if(pu == pv) return;

        // else if check the rank 
        if(size[pu] < size[pv]){
            parent[pu] = parent[pv];
            size[pv] += size[pu];
        }else if(rank[pu] > rank[pv]){
            parent[pv] = parent[pu];
            size[pu] += size[pv];
        }else{
            parent[pu] = parent[pv];
            size[pv] += size[pu];
        }
    }

    // step 1 in kruskal's algo -> get all the edges and sort them according to the edge weight
    int NumberOfProvinces(int n,int m){
        // get the edges and sort according to the edge weight 
        vector<pair<int,int>> pq;

        for(int k=0;k<m;k++){
            for(int l=0;l<m;l++){
                int ip;
                cin>>ip;
                if(ip==1){
                    int u=k,v=l;
                    // pq.push_back({u,v});
                    UnionByRank(u,v);
                }
            }
        }

        // apply disjoint set algorithm
        int count=0;

        // for(int i=0;i<pq.size();i++){
        //     // make the union of the edges
        //     int u = pq[i].first;
        //     int v = pq[i].second;
        //     UnionByRank(u,v);
        // }

        // number of ultimate parents represents the number of provinces 
        for(int u=0;u<n;u++){
            if(parent[u]==u){
                count++;
            }
        }
        // return the count at the end
        return count;

    }

};

void solve()
{
    int n,m;  // nodes 
    cin>>n;
    m = n;

    DisjointSet s(n);
    int res = s.NumberOfProvinces(n,m);
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


