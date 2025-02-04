#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
The problem is to find the shortest distances between every pair of 
vertices in a given edge-weighted directed graph.
The graph is represented as an adjacency matrix of size n*n. 
Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, 
it means there is no edge from i to j.
Note : Modify the distances for every pair in-place.

Input: matrix = [[0, 1, 43],[1, 0, 6],[-1, -1, 0]]

Output: [[0, 1, 7],[1, 0, 6],[-1, -1, 0]]

Explanation: We can reach 2 from 0 as 0->1->2 and the cost will be 1+6=7 which is less than 43.


Floyd Warshall | Shortest path | Negative cycles | Directed & Undirected Graphs | multi-source to all nodes
*/

// shortest distances between every pair of vertices in a given edge-weighted directed graph

class Solution
{
public:
    // BFS -> will find the shortest path 
    int floydWarshall(vector<vector<int>>& cost_adj_matrix,int n,int m){
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

        // detect cycle 
        // if node to itself has path weight < 0, then we can say that there is a negative edge cycle
        for(int i=0;i<n;i++){
            if(cost_adj_matrix[i][i]<0) return -1;
        }

        // then print the final matrix
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<cost_adj_matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        return 1;
    }


};

void solve()
{
    // grid
    int n;   // nodes
    int m;
    cin >> n >>m ;

    // provided with a weighted adj matrix 
    // grid
    vector<vector<int>> edges(n, vector<int>(n,(int)1e8));
    for(int k=0;k<m;k++){
        int u,v,wt;
        cin>>u>>v>>wt;

        edges[u][v]=wt;
    }
    
    for(int i=0;i<n;i++){
        // node to itself is 0 
        edges[i][i]=0;
    }

    Solution s;
    int res = s.floydWarshall(edges,n,m);
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
