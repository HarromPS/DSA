#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
 * Given an undirected graph with V vertices. We say two vertices u and v belong
 * to a single province if there is a path from u to v or v to u. Your task is
 * to find the number of provinces.
 *
 * Note: A province is a group of directly or indirectly connected cities and no
 * other cities outside of the group.
 *
 *
 *
 */

void BFS_Traversal(int n, vector<int> adj[],int start,vector<int>& visited)
{
    // 1 based indexing

    queue<int> q;             // Queue
    visited[start] = 1;           // 1st node is 1
    q.push(start);                // Put it in queue

    // take all out until queue is empty
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        // cout << node << " ";

        // ask for its neighbours
        for (auto neighbour : adj[node])
        {
            // if neighbours are not visited add it to queue
            if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = 1;
            }
        }
    }
}

void DFS_Traversal(int node, vector<int> &visited, vector<int> adj_list[])
{
    // mark node as visited
    visited[node] = 1;
    // cout << node << " ";

    // ask for neighbours
    for (auto neighbour : adj_list[node])
    {
        // if not visited call dfs for them and go to depth
        if (visited[neighbour] != 1)
        {
            DFS_Traversal(neighbour, visited, adj_list);
        }
    }
}

void Provinces(int n, int m)
{
    // list S.C:O(N)
    vector<int> adj_list[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    // cout << "Adjancency List:\n";
    // for (int u = 0; u <= n; u++)
    // {
    //     cout << u << " ";
    //     for (int v = 0; v < adj_list[u].size(); v++)
    //     {
    //         cout << adj_list[u][v] << " ";
    //     }
    //     cout << endl;
    // }

    int provinces = 0;
    vector<int> visited(n+1, 0);

    // run a loop for all nodes and find non visited disconnected nodes
    for (int i = 1; i <= n; i++)
    {
        // if not visited
        if (visited[i] != 1)
        {
            provinces++;
            // call dfs or bfs
            BFS_Traversal(n, adj_list, i,visited);
            // DFS_Traversal(i, visited, adj_list);
        }
    }
    cout<<"Number of Provinces: " << provinces<<endl;
}

void solve()
{
    // inputs
    int n; // nodes
    int m; // edges
    cin >> n >> m;

    Provinces(n, m);
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
