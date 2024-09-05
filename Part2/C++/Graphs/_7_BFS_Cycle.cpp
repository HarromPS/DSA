#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

Undirected Graph Cycle 

BFS algo says: it always visits in same distance in all direction
Then how it meets in same direction-> because there is a cycle

So when, a node is touched again but it was not the source 

1 -- 2 -- 5 -- 7
|               |
3 --------------6
|
4

if we say as 7 was already visited by 5, 6 again will try to visit it
but it was already visited, and its not the source(parent) where 6 is came from

6 7

1 2 
1 3 
2 5 
3 4 
3 6 
5 7

Output: Nope

7 7

1 2 
1 3 
2 5 
3 4 
3 6 
5 7
6 7 

Cycle

*/

class Node{
public: 
    int i;
    int parent;
    Node(int _i,int _parent){
        this->i = _i;
        this->parent = _parent;
    }
    Node(){}
};

class Solution
{
public:
    bool detect_Cycle(int src, vector<int>& visited,vector<int> adj_list[]){
        // visit 1st node
        visited[src] = 1;
        queue<Node> q;
        // add it to queue
        q.push(Node(src,-1));

        // loop until queue is empty
        while(!q.empty()){
            int node = q.front().i;
            int parent = q.front().parent;
            q.pop();

            // iterate to its neighbours
            for(auto neigh: adj_list[node]){
                // if not visited visit it, add to queue
                if(visited[neigh]!=1){
                    visited[neigh] = 1;
                    q.push(Node(neigh,node));
                }else if(parent != neigh){
                    cout<<"Cycle"<<endl;
                    return true;
                }
            }
        }
        cout<<"Nope"<<endl;
        return false;

    }
};

void solve()
{
    // grid
    int m;  // edges
    int n;  // nodes
    cin >> m >> n;

    // Adjancency List
    vector<int> adj_list[n+1];    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    // visited array 
    vector<int> visited(n+1,0);

    Solution s;
    int src = 1;    // starting node with -1 as parent 
    s.detect_Cycle(src,visited,adj_list);
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
