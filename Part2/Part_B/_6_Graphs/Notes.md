Dijkstra:
    - from a single source, find shortest paths to all nodes.
    - Works on both directed and undirected graph with non-negative edge weights, Greedy approach

Floyd-Warshall:
    - shortest path from every node as a source.

Bellman-Ford:
    - same as Dijkstra, but works for negative weights.
    - Works on both directed and undirected graph with non-negative edge weights as well as directed graph with negative edge weights as long as no negative cycles are present, Dynamic Programming approach 

Topological Sort:
    - print the nodes with no incoming edges first.

MST:
    - connect all the nodes with minimum costs (n nodes // n-1 edges).

Prim's Algo:
    - build the MST by starting from any node and expanding the tree one edge at a time.

Kruskal Algo:
    - build the MST by sorting all edges and adding them one by one, ensuring no cycles are formed.