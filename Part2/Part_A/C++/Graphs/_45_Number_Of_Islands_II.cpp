#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

There are n stones at some integer coordinate points on a 2D plane. 
You are given a n,m which means the row and column of the 2D matrix and an array of size k denoting the number of operations. 
Matrix elements is 0 if there is water or 1 if there is land.
Originally, the 2D matrix is all 0 which means there is no land in the matrix.
he array has k operator(s) and each operator has two integer A[i][0], A[i][1] means that you 
can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are 
there in the matrix after each operation.You need to return an array of size k.

Note : An island means group of 1s such that they share a common side.

Input: n = 4
m = 5
k = 4
A = {{1,1},{0,1},{3,3},{3,4}}

Output: 1 1 2 2
Explanation:
0.  00000
    00000
    00000
    00000
1.  00000
    01000
    00000
    00000
2.  01000
    01000
    00000
    00000
3.  01000
    01000
    00000
    00010
4.  01000
    01000
    00000
    00011

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

    vector<int> numOfIslands(int n, int m, vector<vector<int>> &query) {
        // create a visited array 
        vector<vector<int>> visited(n,vector<int>(m,0));
        int cnt=0;
        vector<int> ans;

        // iterate through each query 
        for(auto it: query){
            int row = it[0];
            int col = it[1];
            // if already visited -> just add its count 
            if(visited[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            // else 
            visited[row][col]=1;
            cnt++;  // count it as an individual island

            // check in 4 directions
            int drow[]={-1,1,0,0};
            int dcol[]={0,0,1,-1};
            for(int l=0;l<4;l++){
                int nrow=row+drow[l];
                int ncol=col+dcol[l];
                // boundaries
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    if(visited[nrow][ncol]==1){    // if there is any connected islands
                        // check if they are not already connected 
                        int node = row*m + col;
                        int adjNode= nrow*m + ncol;
                        if(findParent(node)!=findParent(adjNode)){
                            cnt--;
                            UnionByRank(node,adjNode);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }

};

void solve(){
    int n;  // number of  
    int m;  // number of edges 
    int numberOfQueries;
    cin>>n>>m>>numberOfQueries;

    // Works but not for all the test cases -> Momory Limit Exceed in Leetcode and GFG
    vector<vector<int>> query;
    for(int i=0;i<numberOfQueries;i++){
        int u,v;
        cin>>u>>v;

        vector<int> temp;
        temp.push_back(u);
        temp.push_back(v);

        query.push_back(temp);
        temp.clear();
    }

    // n*m nodes are there
    DisjointSet s(n*m);
    vector<int> ans=s.numOfIslands(n,m,query);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }   
    cout<<endl;
    
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


