#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell
1 representing a fresh orange, or
2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.
If this is impossible, return -1.
*/

class Node{
public:
    int i;
    int j;
    int time;
    Node(int _i,int _j,int _time){
        this->i = _i;
        this->j = _j;
        this->time = _time;
    }

    Node(){}
};

class Solution
{
public:
    int Rotting_Oranges(int m, int n)
    {
        // list S.C:O(N)
        vector<vector<int>> adj_matrix(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                int ip;
                cin >> ip;
                adj_matrix[i][j] = ip;
            }
        }

        int ansTime = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<Node> q;       // Queue

        // fill all rotten oranges ie 2 in Queue to visit BFS traversal to its neighbours
        // to be rottened

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(adj_matrix[i][j]==2){
                    // mark visited, i.e rottened
                    visited[i][j]=2;
                    // add it to the queue
                    q.push(Node(i,j,0));    // at 0 time

                }else{
                    visited[i][j]=0;
                }
            }
        }

        // Perform BFS
        while (!q.empty())
        {
            Node x = q.front();
            q.pop();

            int i = x.i;
            int j = x.j;
            int time = x.time;

            // max time required
            ansTime = max(ansTime,time);

            // ask for its neighbours to be fresh
            // check in adjacent directions

            // down
            // if is reachable, is not rotten and is not empty
            if(i+1 < m && visited[i+1][j]!=2 && adj_matrix[i+1][j]!=0){
                Node y;
                y.i = i+1;
                y.j = j;
                y.time = time + 1;  // time required to get rottened

                // mark as rottened
                visited[i+1][j] = 2;

                // add to queue
                q.push(y);
            }
            // left

            // if is reachable, is not rotten and is not empty
            if(j-1 >=0 && visited[i][j-1]!=2 && adj_matrix[i][j-1]!=0){
                Node y;
                y.i = i;
                y.j = j-1;
                y.time = time + 1;  // time required to get rottened

                // mark as rottened
                visited[i][j-1] = 2;

                // add to queue
                q.push(y);
            }
            // right

            // if is reachable, is not rotten and is not empty
            if(j+1 < n && visited[i][j+1]!=2 && adj_matrix[i][j+1]!=0){
                Node y;
                y.i = i;
                y.j = j+1;
                y.time = time + 1;  // time required to get rottened

                // mark as rottened
                visited[i][j+1] = 2;

                // add to queue
                q.push(y);
            }

            // up

            // if is reachable, is not rotten and is not empty
            if(i-1 >=0 && visited[i-1][j]!=2 && adj_matrix[i-1][j]!=0){
                Node y;
                y.i = i-1;
                y.j = j;
                y.time = time + 1;  // time required to get rottened

                // mark as rottened
                visited[i-1][j] = 2;

                // add to queue
                q.push(y);
            }
        }

        // check if any orange is stll remaining to be rotten
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if(adj_matrix[i][j]==1 && visited[i][j]!=2){
                    return -1;
                }
            }
        }


        return ansTime;
    }

    int Rotting_Oranges_2(int m, int n)
    {
        vector<vector<int>> adj_matrix(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                int ip;
                cin >> ip;
                adj_matrix[i][j] = ip;
            }
        }

        int ansTime = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<Node> q;       // Queue
        int countFresh=0;

        // fill all rotten oranges ie 2 in Queue to visit BFS traversal to its neighbours
        // to be rottened

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(adj_matrix[i][j]==2){
                    // mark visited, i.e rottened
                    visited[i][j]=2;
                    // add it to the queue
                    q.push(Node(i,j,0));    // at 0 time

                }else{
                    visited[i][j]=0;
                }
                if(adj_matrix[i][j]==1){
                    countFresh++;
                }
            }
        }

        int deltaRow[] = {-1,0,0,1};
        int deltaCol[] = {0,-1,1,0};
        int cnt=0;
        // Perform BFS
        while (!q.empty())
        {
            Node x = q.front();
            q.pop();

            int r = x.i;
            int c = x.j;
            int time = x.time;

            // max time required
            ansTime = max(ansTime,time);

            // ask for its neighbours to be fresh
            // check in adjacent directions using a loop
            // u l r d

            for(int l=0;l<4;l++){
                int nrow = r + deltaRow[l];
                int ncol = c + deltaCol[l];

                // boundaries
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && visited[nrow][ncol]!=2 && adj_matrix[nrow][ncol]==1){
                    Node y;
                    y.i = nrow;
                    y.j = ncol;
                    y.time = time+1;

                    // mark unrotten as rotten
                    visited[nrow][ncol] = 2;

                    // add to queue
                    q.push(y);
                    cnt++;
                }
            }
        }

        // check if any orange is stll remaining to be rotten
        if(countFresh!=cnt){
            return -1;
        }
        return ansTime;
    }
};

void solve()
{
    // grid
    int m;
    int n;
    cin >> m >> n;

    Solution s;
    // int ans = s.Rotting_Oranges(n, m);
    // cout<<"1: "<<ans<<endl;

    int ans = s.Rotting_Oranges_2(n, m);
    cout<<"Striver: "<<ans<<endl;
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
