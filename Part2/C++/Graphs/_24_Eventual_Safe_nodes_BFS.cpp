#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

BFS | Topo sort -> Kahn's algo
A directed graph of V vertices and E edges is given in the form of an adjacency list adj. 
Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.

A node is a terminal node if there are no outgoing edges. 
A node is a safe node if every possible path starting from that node leads to a terminal node.

You have to return an array containing all the safe nodes of the graph.
The answer should be sorted in ascending order

7 7 

0 1 
0 2 
1 3 
1 2 
2 5 
3 0 
4 5 

Only nodes 2,4,5,6 are safe nodes, as every path from them leads to a terminal node 

Note: a terminal node is always a safe node


Now using, Indegrees of nodes to get safe nodes which are having indegree 0
So, a node with indegree 0 is a safe node 


# in previous approach i.e in DFS outdegrees are considered i.e when no neighbour with outdegree 0
# for every path from any node, then it is a safe node

# But to work with topo sort, indegrees are needed 

# 1. Reverse the degrees of nodes
# 2. find indegrees
# 3. reduce the degree of neighbours 
# 4. collect all nodes with indegree 0 -> they are safe nodes
*/



class Solution
{
public:
    vector<int> bfs(vector<int> rev_adj_list[],vector<int>& indegree,int n){
        // Queue 
        queue<int> q;
        set<int> st;        // for the nodes to be sorted

        // add all nodes with indegrees 0
        int m = indegree.size();
        for(int i=0;i<m;i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            st.emplace(node);       // safe node
            
            // ask all neighbours 
            for(auto neigh: rev_adj_list[node]){
                // reduce its indegree
                indegree[neigh]--;
                if(indegree[neigh]==0) q.push(neigh);
            }
        } 

        // copy data from set to vector
        vector<int> ans(st.size());
        copy(st.begin(),st.end(),ans.begin());
        return ans;
    }

};

void solve()
{
    // grid
    int m;  // edges
    int n;  // nodes
    cin >> m >> n;

    // visited array 
    vector<int> indegree(n,0);
    vector<int> ans;

    // Adjancency List for directed graph
    vector<int> adj_list[n];    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        // only from u to v
        adj_list[u].push_back(v);
    }

    // reverse the edges
    vector<int> rev_adj_list[n];
    for(int v=0;v<n;v++){
        for(auto u:adj_list[v]){
            rev_adj_list[u].push_back(v);
        }

    }

    // fill the indegree array
    for(int v=0;v<n;v++){
        for(auto u:rev_adj_list[v]){
            indegree[u]++;
        }
    }

    Solution s;
    ans=s.bfs(rev_adj_list,indegree,n);
    // answer must be returned in ascending order 
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
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
