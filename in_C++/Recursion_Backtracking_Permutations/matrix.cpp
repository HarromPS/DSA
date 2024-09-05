#include <iostream>
#include <cstdio>
using namespace std;

// find number of ways in a M x N matrix to reach the bottom
// Condition: move to only right & bottom

int ways(int m,int n)       // size of a matrix
{
    // logic: in a single row or column it will return 1, as eventually it will hit the boundary straight
    // move right in one recursive stack, then bottom -> repeat until end

    // base condition: if m & n is in last row or column
    if (m==1 || n==1)
    {
        return 1;
    }

    // m-1-> down, n-1 right
    return ways(m-1, n) + ways(m, n-1);
}
int main()
{
    int mat[3][3]={
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
    int res=ways(3,3);
    cout<<res<<endl;
    return 0;
}
