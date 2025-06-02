#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

=> N Queens

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.
You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, 
where 'Q' and '.' both indicate a queen and an empty space, respectively.

e.g n=4

Solution of N-Queens
0 1 0 0 
0 0 0 1 
1 0 0 0 
0 0 1 0 

0 0 1 0 
1 0 0 0 
0 0 0 1 
0 1 0 0 

*/
class Solution
{
public:

    // IMP NOTE: this function check safe place for row by row filling method
    int is_safe(int row,int col, vector<vector<int>>& chessboard,int n){
        // need to check only 4 directions out of 4
        int i=row,j=col;

        // up
        while(i>=0){
            if(chessboard[i][j]==1){
                return 0;
            }
            i--;
        }

        // backward
        i=row; j=col;
        while(j>=0){
            if(chessboard[i][j]==1){
                return 0;
            }
            j--;
        }

        // upper left
        i=row; j=col;
        while(i>=0 && j>=0){
            if(chessboard[i][j]==1){
                return 0;
            }
            j--;
            i--;
        }

        // upper right
        i=row; j=col;
        while(i>=0 && j<n){
            if(chessboard[i][j]==1){
                return 0;
            }
            i--;
            j++;
        }

        // return 1 when no attacking queen is there
        return 1;
    }

    // Brute force
    // T.C: O(2^n)
    // S.C: O(n)
    void N_Queens(int row, vector<vector<int>>& chessboard,int n){      
        // base case
        // if row reached end means all queens are placed, got a solution
        if(row==n){
            // print answer 
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<chessboard[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
            return;
        }

        // recurrence relation
        // try to place a queen on every row
        // so on every row, place queen column wise
        // check is safe to place, if not move to next cell in same row
        for(int col=0;col<n;col++){
            // check if placing the queen is safe
            if(is_safe(row, col,chessboard, n)==1){
                // place the queen
                chessboard[row][col] = 1;

                // place queen on next row
                N_Queens(row+1, chessboard, n);

                // when backtracked, means no solution found
                // so remove queen from current cell and try to place on some other cell in same column
                chessboard[row][col] = 0;
            }
        }
    }
};

void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> chessboard(n, vector<int>(n, 0));

    // 0-empty, 1-Queen 

    // Note: as we are filling row wise, so if queen is placed at last cell in a row,
    // cannot be detected by is safe function, as it check previous left values

    // so we have to check 4 direction in this way,
    // 
    Solution soln;
    cout<<"Solution of N-Queens"<<endl;
    soln.N_Queens(0,chessboard,n);      // start from first row 

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
