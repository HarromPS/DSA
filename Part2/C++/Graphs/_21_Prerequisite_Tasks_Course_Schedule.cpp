#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1,
which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P, 
find if it is possible to finish all tasks.

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] 
where bi must be done before doing ai i.e complete bi then ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

for eg 
1 0 
2 1 
3 2 

1st 0 should be done before 1  (view from right to left)
1 0 

2nd iter, 1 should be before 2
2 1 0 

3rd iter, 2 should be before 3 
3 2 1 0 

thus all tasks can be finished

for e.g
1 2
2 4 
3 4
4 1 

-> 1 2 (2 before 1)
-> 1 2 4 (4 before 2)
-> 1 2 4 3 (3 before 4)
-> 1 2 4 1 3 (1 before 4) => invalid condition -> creates a cycle, so 

This is a topo sort problem for any u and v u appears before v

so a topo sort cannot be made as there is a cycle detected 


*/



class Solution
{
public:
    // return true of cycle
    bool bfs(vector<int> adj_list[],vector<int>& indegree,vector<int>& ans,int n){
        // Queue
        queue<int> q;

        // add all nodes with indegrees 0
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        // not empty
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            ans.push_back(node);

            // ask neighbours

            // node is in the topo sort 
            // so remove it from the indegree
            for(auto neigh: adj_list[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }

        // if not same, return true -> cycle
        return ans.size()!=n;
    }

    void getIndegree(vector<int> adj[],int n){
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto v: adj[i]){
                indegree[v]++;
            }
        }
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
    vector<int> ans;     // ans ds

    // Adjancency List for directed graph
    vector<int> adj_list[n+1];    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        // get the indegres
        indegree[v]++;

        // only from u to v
        adj_list[u].push_back(v);
    }

    cout<<"Adjancency List:\n";
    for(int u=0;u<=n;u++){
        // cout<<u<<": ";
        for(int v=0;v<adj_list[u].size();v++){
            // cout<<adj_list[u][v]<<" ";
        }
        // cout<<endl;
    }


    Solution s;
    bool res = s.bfs(adj_list,indegree,ans,n);
    cout<<(res==1?"Cycle":"No Cycle")<<endl;
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
