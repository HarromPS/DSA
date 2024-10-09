#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given an m x n matrix, return all elements of the matrix in spiral order.

input:      
1 2 3 
4 5 6 
7 8 9 

output: 
1 2 3 6 9 8 7 4 5 
*/

class Solution {
public:
    void reverse(int row,int end,vector<vector<int>>& matrix){
        int start=0;
        while(start<end){
            int temp=matrix[row][start];
            matrix[row][start]=matrix[row][end];
            matrix[row][end]=temp;
            start++;
            end--;
        }
    }

    void Swap(int Ai,int Aj,vector<vector<int>>& matrix){
        int temp=matrix[Ai][Aj];
        matrix[Ai][Aj]=matrix[Aj][Ai];
        matrix[Aj][Ai]=temp;
    }

    void dfs(int i,int j,int direction,vector<vector<int>> matrix,vector<vector<int>> visited,vector<int>& ans,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m || visited[i][j]==1){
            return;
        }

        // mark as visited 
        visited[i][j]=1;
        ans.push_back(matrix[i][j]);

        // go dfs 
        if(direction==1){   // go right 
            if(j+1<m && visited[i][j+1]==0){
                dfs(i,j+1,1,matrix,visited,ans,n,m);
            }
            else{
                dfs(i+1,j,2,matrix,visited,ans,n,m);
            }
        }
        if(direction==2){   // go down 
            if(i+1<n && visited[i+1][j]==0){
                dfs(i+1,j,2,matrix,visited,ans,n,m);
            }
            else{
                dfs(i,j-1,3,matrix,visited,ans,n,m);
            }
        }
        if(direction==3){   // go left 
            if(j-1>=0 && visited[i][j-1]==0){
                dfs(i,j-1,3,matrix,visited,ans,n,m);
            }
            else{
                dfs(i-1,j,4,matrix,visited,ans,n,m);
            }
        }
        if(direction==4){   // go up 
            if(i-1>=0 && visited[i-1][j]==0){
                dfs(i-1,j,4,matrix,visited,ans,n,m);
            }
            else{
                dfs(i,j+1,1,matrix,visited,ans,n,m);
            }
        }
    }

    // Brute force Solution:TC-O(n*m), SC-O(2(n*m))
    void spiralMatrixBrute(vector<vector<int>> matrix){
        vector<int> ans;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        dfs(0,0,1,matrix,visited,ans,n,m);    // going right

        for(auto it:ans) cout<<it<<" ";
        cout<<endl;
    }
    
    // Optimal TC:O(N*M) SC:O(N*M) + O(1)
    void spiralMatrixOptimal(vector<vector<int>>& matrix){
        // doing it traditionally 
        int n=matrix.size();
        int m=matrix[0].size();
        int left=0, top=0;
        int right=m-1,bottom=n-1;
        vector<int> ans;

        while(left<=right && top<=bottom){
            // left to right , top is same 
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            // top to bottom, right is same 
            for(int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){
                // right to left, bottom is same 
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right){
                // bottom to top, left is same 
                for(int i=bottom;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        for(auto it:ans) cout<<it<<" ";
        cout<<endl;
    }

};

void solve(){
    int n,m;  // matrixay size
    cin>>n>>m;

    vector<vector<int>> matrix(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            cin>>matrix[i][j];
        }
    }   

    Solution s;
    cout<<"Brute: "<<endl;
    s.spiralMatrixBrute(matrix);

    cout<<"Optimal: "<<endl;
    s.spiralMatrixOptimal(matrix);

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


