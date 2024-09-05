#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;

int isSafe(vector<vector<int>> &v, int row, int col, int n)
{
    // vertical direction
    for (int i = 0; i < row; i++)
    {
        if (v[i][col] != -1)
        {
            return 0;
        }
    }

    // left diagonal direction
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (v[i][j] != -1)
        {
            return 0;
        }
    }
    // right diagonal direction
    for (int i = row, j = col; i <= n && j >= 0; i++, j--)
    {
        if (v[i][j] != -1)
        {
            return 0;
        }
    }
    return 1;
}
bool nQueens(vector<vector<int>> &v, int row, int N)
{
    if (row == N)
    {
        return true;
    }
    for (int cols = 0; cols <= N; cols++)
    {
        if (isSafe(v, row, cols, N))
        {
            v[row][cols] = 1;
            if (nQueens(v, row + 1, N))
            {
                return true;
            }
            v[row][cols] = 0;
        }
    }
    return false;
}
int nQueensSolver(vector<vector<int>> &v, int row, int cols, int n)
{
    return nQueens(v, 0, n - 1) ? 1 : 0;
}
int main()
{
    int row = 4, cols = 4;
    vector<vector<int>> v;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            v[i].push_back(0);
        }
    }

    cout << nQueensSolver(v, row, cols, row);
    return 0;
}

