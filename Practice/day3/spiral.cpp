#include <iostream>
#include <cstdio>
using namespace std;

int main()
{

    int row = 3, col = 4;
    int arr[row][col] = {
        {1, 2, 3, 4},
        {6, 7, 8, 9},
        {11, 12, 13, 14},
        // {16, 17, 18, 19},
        // {21, 22, 23, 24},
    };

    // for the n x n matrix, there are (2n-1) paths to traverse all elements
    // if m < n => (m*2 - 1), if m > n (n*2)

    int m = row, n = col;
    int wait = (m<=n)?(2*m -1 ):(n*2);
    for (int run = 0; run < wait;run++){
        // ttraverse row
        // for(int i=0;i<)

        // traverse col
    }

        return 0;
}