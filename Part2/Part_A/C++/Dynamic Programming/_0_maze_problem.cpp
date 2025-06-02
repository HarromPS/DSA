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


// Using Top Down Approch

int maze_problem(int M, int N){
    // base case
    if(M==1 && N == 1){
        return 1;
    }

    // only one dimension
    else if(M==1 || N==1){
        return 1;
    }

    return maze_problem(M,N-1) + maze_problem(M-1,N);
}

int main(){
    int m=2,n=3;
    int res = maze_problem(m,n);
    cout<<res<<endl;
    return 0;
}