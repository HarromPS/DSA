#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. 
You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, 
plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, 
plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. 
Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), 
all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
*/

class Node{
public: 
    int i;
    int j;
    int color;
    Node(int _i,int _j,int _color){
        this->i = _i;
        this->j = _j;
        this->color = _color;
    }

    Node(){}
};

class Solution
{
public:
    int Flood_Fill(int m, int n,int sr,int sc,int flood_Color)
    {
        vector<vector<int>> adj_matrix(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                int ip;
                cin >> ip;
                adj_matrix[i][j] = ip;
            }
        }

        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<Node> q;       // Queue

        // add starting node to queue
        q.push(Node(sr,sc,adj_matrix[sr][sc]));

        // mrk starting node as visited 
        visited[sr][sc]=flood_Color;

        // delta directions
        int deltaRow[] = {-1,0,0,1};
        int deltaCol[] = {0,1,-1,0};

        // Perform BFS
        while (!q.empty())
        {
            Node x = q.front();
            q.pop();

            int r = x.i;
            int c = x.j;
            int color = x.color;

            // ask for its neighbours
            // check in adjacent directions
            for(int l=0;l<4;l++){
                int nrow = r + deltaRow[l];
                int ncol = c + deltaCol[l];

                // boundaries
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && visited[nrow][ncol]!=flood_Color && adj_matrix[nrow][ncol]==color){
                    // mark visited 
                    visited[nrow][ncol] = flood_Color;

                    // add to queue
                    q.push(Node(nrow,ncol,adj_matrix[nrow][ncol]));
                }
            }

        }

        // travel & fill the rest of the non matched colors of grid 
        cout<<"Flooded Grid:"<<endl;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if(visited[i][j]!=flood_Color){
                    visited[i][j]=adj_matrix[i][j];
                }
                cout<<visited[i][j]<<" ";
            }
            cout<<endl;
        }


        return 0;
    }

    // dfs

    void dfs(int r,int c,int flood_Color,int prev_Color,vector<vector<int>> adj_matrix,vector<vector<int>>& visited){

        int m = adj_matrix.size();
        int n = adj_matrix[0].size();

        // mark as visited with flood color
        visited[r][c] = flood_Color;

        // go to all the neighbours
        int drow[]={-1,0,0,1};
        int dcol[]={0,1,-1,0};
        for(int l=0;l<4;l++){
            int nrow = r+drow[l];
            int ncol = c+dcol[l];

            // boundaries
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && visited[nrow][ncol]!=flood_Color && adj_matrix[nrow][ncol]==prev_Color){
                // call dfs function for the current cell 
                dfs(nrow, ncol, flood_Color, prev_Color, adj_matrix, visited);
            }
        }

    }

    void DFS_Flood_Fill(int m, int n,int sr,int sc,int flood_Color){
        vector<vector<int>> adj_matrix(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                int ip;
                cin >> ip;
                adj_matrix[i][j] = ip;
            }
        }

        vector<vector<int>> visited = adj_matrix;

        dfs(sr,sc,flood_Color,adj_matrix[sr][sc],adj_matrix,visited);
    }
};

void solve()
{
    // grid
    int m;
    int n;
    cin >> m >> n;

    int sr,sc,color;
    cin>>sr>>sc>>color;

    Solution s;

    // int ans = s.Flood_Fill(m, n,sr,sc,color);
    // cout<<"ans: "<<ans<<endl;

    s.DFS_Flood_Fill(m, n,sr,sc,color);
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
