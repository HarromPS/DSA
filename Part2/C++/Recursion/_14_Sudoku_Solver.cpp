#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

=> Sudoku Solver
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

The '.' character indicates empty cells.

*/
class Solution
{
public:

    // function to check if digit is there in row or cell or 3x3 grid
    int is_valid(vector<vector<int>>& sudoku,int dig,int row,int col){
        for(int i=0;i<sudoku.size();i++){
            // row: moving column wise
            if(i!=col && sudoku[row][i]==dig){
                return 0;
            }
            // col: moving row wise
            if(i!=row && sudoku[i][col]==dig){
                return 0;
            }
            // 3x3 grid traverse
            if (sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == dig) {
                return 0;
            }
        }
        // if the digit was not there previously return 1
        return 1;
    }

    // Brute force
    // T.C: O(2^n)
    // S.C: O(n)
    int Sudoku_Solver(vector<vector<int>>& sudoku){
        // iterate through the board, 0 means empty, try to fill 1-9 numbers 
        int n = sudoku.size();
        int m = sudoku[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // try to fill if cell is empty
                if(sudoku[i][j]==0){
                    for(int dig = 1;dig<=9;dig++){
                        // check if we can place a digit here
                        if(is_valid(sudoku, dig,i,j)==1){
                            sudoku[i][j]=dig;
                            int res = Sudoku_Solver(sudoku);

                            // if we got a solution after filling all digits return 1
                            if(res==1){
                                return 1;
                            }

                            // else try with other digits
                            sudoku[i][j]=0;
                        }
                    }

                    // if no solution returned by putting all digits, backtrack by returning 0
                    return 0;
                }
            }
        }
        // if all cells are traversed, means all cells are filled correctly
        return 1;
    }
};

void solve()
{
    int n;
    cin>>n;

    // fill the sudoku
    vector<vector<int>> sudoku = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout<<"Solution of Sudoku"<<endl;
    Solution soln;
    soln.Sudoku_Solver(sudoku);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }


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
