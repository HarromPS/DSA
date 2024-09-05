#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>
using namespace std;

/*
N-Queens is a std problem : Placing N queens in a n*n chess board
                            such that no two queens attack each other

Backtrack to current queen -> if there is no safe place to put a queen in next row
*/

bool isSafe2(vector<vector<int>> &board, int row, int col, int N)
{
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i <= N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// checks all directions
int isSafe(vector<vector<int>> &board, int row, int cols, int n)
{
    // check row
    for (int i = 0; i < n; i++)
    {
        if (board[row][i] == 1)
        {
            return 0;
        }
    }
    // check column
    for (int i = 0; i < n; i++)
    {
        if (board[i][cols] == 1)
        {
            return 0;
        }
    }
    // check upper left diagonal
    int temp[] = {row, cols};
    while (temp[0] >= 0 && temp[1] >= 0)
    {
        if (board[temp[0]][temp[1]] == 1)
        {
            return 0;
        }
        temp[0]--;
        temp[1]--;
    }
    // check upper right diagonal
    temp[0] = row;
    temp[1] = cols;
    while (temp[0] >= 0 && temp[1] <= n)
    {
        if (board[temp[0]][temp[1]] == 1)
        {
            return 0;
        }
        temp[0]--;
        temp[1]++;
    }
    temp[0] = row;
    temp[1] = cols;

    // check lower right diagonal
    while (temp[0] <= n && temp[1] <= n)
    {
        if (board[temp[0]][temp[1]] == 1)
        {
            return 0;
        }
        temp[0]++;
        temp[1]++;
    }

    // check lower left diagonal
    temp[0] = row;
    temp[1] = cols;
    while (temp[0] <= n && temp[1] >= 0)
    {
        if (board[temp[0]][temp[1]] == 1)
        {
            return 0;
        }
        temp[0]++;
        temp[1]--;
    }
    return 1;
}

// N = last row/cols; row = current row
bool nQueens(vector<vector<int>> &board, int row, int N)
{
    if (row == N)
    {
        return true;
    }
    // iterate all the cells in the current row
    for (int cols = 0; cols <= N; cols++)
    {
        // if (isSafe(board, row, cols, N))
        if (isSafe2(board, row, cols, N))
        {
            board[row][cols] = 1; // place the queen
            if (nQueens(board, row + 1, N))
            {
                return true;
            }
            board[row][cols] = 0; // backtracks if not reached the end row
        }
    }
    return false;
}
int main()
{
    int n = 4;
    vector<vector<int>> board(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i].push_back(0);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    bool ans = nQueens(board, 0, n - 1);
    cout << ans << endl;

    return 0;
}