#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
 * DFS:
 *
 * 1. Depth wise traversal
 * 2. Recursive traversal
 *
 * steps:
 *
 * Initial configurations
 *
 * visited array
 * Mark 1st starting node as visited
 *
 * 2nd
 *
 * call dfs recursive function for starting node
 * mark it as visited
 * print it
 * ask for its neighbours
 * if neighbours are not visited
 * then repeat step 2nd
 *
 */

// TC:O(2 * edges):degree of a node + O(n)
void DFS_Traversal(int node, vector<int> &visited, vector<int> adj_list[])
{
    // mark node as visited
    visited[node] = 1;
    cout << node << " ";

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

void DFS(int n, int m)
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

    cout << "Adjancency List:\n";
    for (int u = 0; u <= n; u++)
    {
        cout << u << " ";
        for (int v = 0; v < adj_list[u].size(); v++)
        {
            cout << adj_list[u][v] << " ";
        }
        cout << endl;
    }

    // DFS traversal
    cout << "\nDFS Traversal" << endl;

    vector<int> visited(n + 1, 0);
    DFS_Traversal(1, visited, adj_list);
}

void solve()
{
    // inputs
    int n; // nodes
    int m; // edges
    cin >> n >> m;

    DFS(n, m);
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
