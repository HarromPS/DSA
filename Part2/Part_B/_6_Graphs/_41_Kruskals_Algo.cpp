#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Minimum Spanning Tree | Min cost to all nodes with n nodes and n-1 edges 

Kruskal's Algo | Disjoint Set | FindParent() | UnionByRank() | UnionBySize()

Given a weighted, undirected, and connected graph with V vertices and E edges,
your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. 
The graph is represented by an adjacency list, 
where each element adj[i] is a vector containing vector of integers. Each vector represents an edge, 
with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.

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
    int KruskalsAlgo(int n,int m){
        // get the edges and sort according to the edge weight 
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        for(int k=0;k<m;k++){
            int u,v,wt;
            cin>>u>>v>>wt;

            pq.push({wt,{u,v}});
        }

        // apply disjoint set algorithm
        int sum=0;
        while(!pq.empty()){
            int wt = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            pq.pop();

            // if not in same component then add its edge to the MST
            if(findParent(u) != findParent(v)){
                sum+=wt;
                UnionByRank(u,v);
            }

        }
        // return the sum at the end
        return sum;

    }

};

void solve()
{
//     DisjointSet s(7);
//     s.UnionByRank(1,2);
//     s.UnionByRank(2,3);
//     s.UnionByRank(4,5);
//     s.UnionByRank(6,7);
//     s.UnionByRank(5,6);
//     // check if 3 and 7 belongs to same component or not
//     if(s.findParent(3) == s.findParent(7)){
//         cout<<"same\n";
//     }else cout<<"Not same\n";

//    s.UnionByRank(3,7);
//     if(s.findParent(3) == s.findParent(7)){
//         cout<<"same\n";
//     }else cout<<"Not same\n";

    // Union by size
//     DisjointSet s(7);
//     s.UnionBySize(1,2);
//     s.UnionBySize(2,3);
//     s.UnionBySize(4,5);
//     s.UnionBySize(6,7);
//     s.UnionBySize(5,6);
//     // check if 3 and 7 belongs to same component or not
//     if(s.findParent(3) == s.findParent(7)){
//         cout<<"same\n";
//     }else cout<<"Not same\n";

//    s.UnionBySize(3,7);
//     if(s.findParent(3) == s.findParent(7)){
//         cout<<"same\n";
//     }else cout<<"Not same\n";

    int n,m;  // nodes 
    cin>>n>>m;

    DisjointSet s(n);
    int res = s.KruskalsAlgo(n,m);
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


