#include<iostream>
#include<stdlib.h>
using namespace std;

/* Coin Problem: 

Coins: {1,4,5}
sum: 13

Solution: 4 ways
1 + 1 + 1 + 1 
1 + 4 
4 + 1 
5 

In this problem, finding how many solutions are possible to make the target sum using the coins

*/

// Solution: Bottom Up Approach (Recursive)
// move through sum

int minCoins(int* coin,int sum,int size,int *dp){
    dp[0] = 1;
    for(int i=1;i<=sum;i++)  {
        dp[i] = 0;
        for(int j=0;j<size;j++){
            int remSum = i-coin[j];
            if(remSum<0){
                continue;
            }
            dp[i] = dp[i] + dp[remSum];
        }
    }
    return dp[sum];
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

    int sum = 5; 
    int dp[sum+1];

    memset(dp,-1,sizeof(dp));
    int res = minCoins(coins,sum,size,dp);
    cout<<res<<endl;

    return 0;
}