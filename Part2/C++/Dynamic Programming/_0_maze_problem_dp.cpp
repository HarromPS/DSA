#include<iostream>
#include<stdlib.h>
using namespace std;

/* Implementation of a maze problem
Given an M x N grid, so in how many ways can a rabbit get from top left corner to 
bottom right corner, if it can only move down or 
right.

e.g 6 x 9  grid 

if rabbit moves down, rows decreases
if rabbit moves right, columns decreases

Formula 

solution(1,1) = 1
solution(m,1) = solution(m,1) = 1    as 1D way is the only 1 way
solution(m,n) = solution(m,n-1) + solution(m-1,n)
           OR = solution(m,n+1) + solution(m+1,n)   if starts with 1 x 1, then reaching to end will be m x n grid

*/

// Using Bottom Up Approch

int maze_problem(int M, int N){
    int dp[M][N];

    dp[0][0]=0;
    for(int i=1;i<M;i++){
        dp[i][0]=1;     // 1st column 
    }
    for(int i=1;i<N;i++){
        dp[0][i]=1;     // 1st row 
    }

    // to make solution from already calculated solutions
    for(int i=1;i<M;i++){
        for(int j=1;j<N;j++){
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return dp[M-1][N-1];
}

int main(){
    int m=3,n=3;
    int res = maze_problem(m,n);
    cout<<res<<endl;
    return 0;
}