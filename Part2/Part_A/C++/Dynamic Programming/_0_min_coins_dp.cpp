#include<iostream>
#include<stdlib.h>
using namespace std;

// Coin Problem: 

// Coins: {1,4,5}
// sum: 13

// In this problem, there is a lot of repeated computation in subproblems
// so combining recursion with memoization 

// Solution:

int minIgnoreNone(int a,int b){
    if(a==-1){
        return b;
    }
    if(b==-1){
        return a;
    }

    return min(a,b);
}
int minCoins(int* coin,int sum,int size,int* dp){

    // check if the subproblem is already solved 
    if(dp[sum] != -1){
        return dp[sum];
    }
    int answer;
    if(sum==0){
        answer=0;
    }
    else{
        answer = -1;
        for(int i=0;i<size;i++){
            int subproblem = sum - coin[i];
            if(subproblem<0){
                continue;
            }

            answer = minIgnoreNone(answer, minCoins(coin, subproblem, size, dp)+1);
        }
    }

    // save the subproblem in memory

    // thus, each subproblem is calculated recursively only once
    dp[sum] = answer;
    return answer;
}

void memset(int* dp, int val, int sizeOfDP){
    int size = sizeOfDP/sizeof(int);
    for(int i=0;i<size;i++){
        dp[i] = val;
    }
}
int main(){
    int coins[] = {1,4,5};
    int size = sizeof(coins)/sizeof(int);

    // it is optimized and efficient
    int sum = 13; 

    int dp[sum+1];
    memset(dp,-1,sizeof(dp));
    int res = minCoins(coins,sum,size,dp);
    cout<<res<<endl;

    // for(int i=0;i<sizeof(dp)/sizeof(int);i++){
    //    cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    return 0;
}