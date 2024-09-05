#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

Undirected Graph Cycle 

DFS algo says: goes to depth and if comes back to same node -> cycle

So when, a node is touched again but it was not the source 

1 -- 2 -- 5 -- 7
|               |
3 --------------6
|
4

start from 1 
it goes -> 2 -> 5 -> 7 -> 6 -> 3 -> 4 -> back to 3 -> 1 (but 3 is already touched)
and for 3 1 is not its source, 6 is so it will form a loop

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
    bool detect_Cycle(int node,int parent, vector<int>& visited,vector<int> adj_list[]){
        // visit node
        visited[node] = 1;

        // iterate to its neighbours
        for(auto neigh: adj_list[node]){
            // if not visited visit it, add to queue
            if(visited[neigh]!=1){
                // go and explore its depths 
                return detect_Cycle(neigh, node,visited,adj_list);

            }else if(parent != neigh){  // if already visited, check if that neighbour 1 if its parent -> if not loop
                return true;
            }
        }
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

    // for components 
    for(int i=1;i<=n;i++){
        // if not visited, detect cycle for that component as a starting point
        if(visited[i]!=1){
            bool ans = s.detect_Cycle(i,-1,visited,adj_list);
            if(ans){
                cout<<"Cycle"<<endl;
                break;
            }
        }
    }
    cout<<"Nope";
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
