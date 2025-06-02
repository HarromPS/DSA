#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Function for Adjacency Matrix representation
void Adjacency_Matrix(int n, int m) {
    vector<vector<int>> adj_mat(n + 1, vector<int>(n + 1, 0)); // n x n matrix initialized with 0

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj_mat[u][v] = 1;
        adj_mat[v][u] = 1;
    }

    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }
}

// Function for Adjacency List representation
void Adjacency_List(int n, int m) {
    vector<vector<int>> adj_list(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    cout << "Adjacency List:" << endl;
    for (int i = 0; i <= n; i++) {
        cout << i << ": ";
        for (int j : adj_list[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

// Function for Weighted Graph (Adjacency List with Weights)
void Weighted_Matrix(int n, int m) {
    vector<vector<pair<int, int>>> adj_list(n + 1); // Each pair contains <node, weight>

    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj_list[u].push_back({v, wt});
        adj_list[v].push_back({u, wt});
    }

    cout << "Weighted Graph (Adjacency List with Weights):" << endl;
    for (int i = 0; i <= n; i++) {
        cout << i << ": ";
        for (auto edge : adj_list[i]) {
            cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        cout << endl;
    }
}

int main() {
    // Reading from input.txt and writing to output.txt
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;  // n = nodes, m = edges
    cin >> n >> m;

    // Uncomment the one you want to use:
    
    // Adjacency_Matrix(n, m);
    // Adjacency_List(n, m);
    Weighted_Matrix(n, m);

    return 0;
}
