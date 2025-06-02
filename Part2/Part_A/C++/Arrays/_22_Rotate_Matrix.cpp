#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
You are given an n x n 2D matrix representing an image, 
rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, 
which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation

input:      
1 2 3 4
5 6 7 8 
4 3 2 1
8 7 6 4 

output: 
8 4 5 1 
7 3 6 2 
6 2 7 3 
4 1 8 4 

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

    // Brute force Solution:TC-O(n*m), SC-O(n*m)
    void rotateMatrixBrute(vector<vector<int>> matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> temp(n,vector<int>(m,0));

        // traverse and rotate
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp[i][j]=matrix[n-j-1][i];
            }
        }

        for(int i=0;i<n;i++){
            for(auto it:temp[i]) cout<<it<<" ";
            cout<<endl;
        }
    }
    
    // Optimal TC:O(N*M) SC:O(N*M) + O(1)
    void rotateMatrixOptimal(vector<vector<int>>& matrix){
        // using matrix operations 
        // transpose of matrix Aij=Aji
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                Swap(i,j,matrix);
            }
        }

        // reverse every row 
        for(int i=0;i<n;i++){
            reverse(i,n-1,matrix);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
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
    s.rotateMatrixBrute(matrix);

    cout<<"Optimal: "<<endl;
    s.rotateMatrixOptimal(matrix);

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


